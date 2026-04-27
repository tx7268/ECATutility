#ifndef RUNTIME_H
#define RUNTIME_H

#include <QObject>
#include <QQueue>
#include <QTimer>
#include <QString>
#include <QDateTime>
#include <QByteArray>


class QComboBox;
class QTableWidget;
class QWidget;
class QTimer;


// 信息日志结构体
struct LogSendInfo
{
    int seq;         // 序号
    QString cmdName; // 命令
    int sendValue;   // 发送值
    qint64 sendTime; // 发送时间戳
};

class RunTime : public QObject
{
    Q_OBJECT

public:
    explicit RunTime(QObject *parent = nullptr);
    ~RunTime();

    void init(QTableWidget* tableWidget, QComboBox* filterComboBox, QWidget* dialogParent);

    int commandTimeoutMs() const { return m_commandTimeoutMs; } // 获取超时时间

signals:
    void sendSerialDataRequested(const QByteArray& data);
    void logMessage(const QString& msg);

public slots:
    void sendCmdWithLog(const QByteArray& data, const QString& cmdName, int sendValue = 0);
    void updateLogRow(int retValue, const QString& status);
    void checkTimeoutCommands();
    void filterRunTimeLog(int index);
    void clearLog();
    void exportLog();


private slots:


private:
    void addLogRow(QString time, int seq, QString cmd, int send, int ret, double delay, QString status);

    QTableWidget* m_tableWidget = nullptr;
    QComboBox* m_filterComboBox = nullptr;
    QWidget* m_dialogParent = nullptr;
    QTimer* m_timeoutTimer = nullptr;
    int m_logSeq = 0;
    QQueue<LogSendInfo> m_sendLogQueue;
    const int m_commandTimeoutMs = 8000;
};

#endif // RUNTIME_H
