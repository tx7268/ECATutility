#ifndef RUNTIME_H
#define RUNTIME_H

#include <QObject>
#include <QQueue>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QByteArray>
#include <QThread>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QChartView>

class QComboBox;
class QTableWidget;
class QWidget;
class QTimer;


// 信息日志结构体
struct LogSendInfo
{
    int seq;         // 序号
    int protoSeq;    // 协议序列号
    int protoCmd;    // 协议命令码
    QString cmdName; // 命令
    int sendValue;   // 发送值
    qint64 sendTime; // 发送时间戳
};

// 通信统计数据结构体
struct RunTimeStats
{
    int totalPackets = 0;      // 总包数（所有发送的命令）
    int okPackets = 0;         // 成功包数（收到OK应答）
    int errorPackets = 0;      // 错误包数（收到ERROR应答）
    int timeoutPackets = 0;    // 超时包数
    QList<double> latencyList; // 所有有效延时列表（单位ms）
    double maxLatency = 0;     // 最大延时
    double minLatency = 0;     // 最小延时
    double currentLatency = 0; // 当前延时（最新的）
    double avgLatency = 0;     // 平均延时
    double jitter = 0;         // 抖动（相邻延时差的平均）
    double packetLossRate = 0; // 丢包率（%）
};

struct RunTimeLogRow
{
    QString time;       // 时间戳
    int seq = 0;        // 序号
    QString cmd;        // 命令名称
    int send = 0;       // 发送值
    int ret = 0;        // 返回值
    double delay = 0.0; // 延时
    QString status;     // 状态
};

struct RunTimeLogUpdate
{
    int row = -1;        // 行号
    int ret = 0;         // 返回值
    double delay = 0.0;  // 延时
    QString status;      // 状态
};



class ChartThread : public QThread
{
    Q_OBJECT
public:
    explicit ChartThread(QObject *parent = nullptr);

public slots:
    void addFreqData(double freq);


signals:
    void chartDataUpdated(double freq, double latency);

protected:
    void run() override;
};


class RunTime : public QObject
{
    Q_OBJECT

public:
    explicit RunTime(QObject *parent = nullptr);
    ~RunTime();

    void init(QTableWidget* tableWidget, QComboBox* filterComboBox, QWidget* dialogParent, QWidget *chartParent);
    // 外部传入ECAT频率数据（从Widget串口解析调用）
    Q_SLOT void onEcatFreqUpdated(quint32 freq);
    
signals:
    void sendSerialDataRequested(const QByteArray& data);// 请求发送串口数据信号
    void logMessage(const QString& msg);
    void statsUpdated(const RunTimeStats& stats); // 统计数据更新信号

public slots:

    void sendCmdWithLog(const QByteArray& data, const QString& cmdName, int sendValue = 0);
    void updateLogRow(int protoSeq, int protoCmd, int retValue, const QString& status);
    void checkTimeoutCommands();
    void filterRunTimeLog(int index);// 过滤运行时日志
    void clearLog();
    void exportLog();


private slots:
    void updateChart(double freq);

private:
    // 添加日志行到表格
    void addLogRow(QString time, int seq, QString cmd, int send, int ret, double delay, QString status);
    void calculateStats(); // 计算所有统计指标（核心）
    int findPendingCommandIndex(int protoSeq, int protoCmd) const;

    void createChart();    // 创建图表


    QTableWidget *m_tableWidget = nullptr; // 表格控件，用于显示日志
    QComboBox *m_filterComboBox = nullptr; // 过滤器下拉框
    QWidget *m_dialogParent = nullptr;     // 父窗口，用于对话框显示
    QTimer *m_timeoutTimer = nullptr;      // 超时检测定时器
    QWidget *m_chartParent = nullptr;  // 图表父控件    

    int m_logSeq = 0;

    QQueue<LogSendInfo> m_sendLogQueue;  // 发送日志队列，记录已发送但未收到响应的命令
    const int m_commandTimeoutMs = 8000; // 命令超时时间（毫秒）

    RunTimeStats m_stats; // 统计数据实例

    // 图表对象
    QChart *m_chart = nullptr;
    QLineSeries *m_seriesFreq = nullptr;    // ECAT频率曲线
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;       // Y轴（频率）
    QChartView *m_chartView = nullptr;

    ChartThread *m_chartThread = nullptr; // 绘图线程
    QList<double> m_dataHistory;          // 数据缓存（滚动显示）
    const int MAX_DATA_COUNT = 400;       // 最大显示点数

    int m_xIndex = 0; 
    double m_maxFreq = 0;                // 缓存最大频率（优化性能）
};

#endif // RUNTIME_H
