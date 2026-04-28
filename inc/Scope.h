#ifndef SCOPE_H
#define SCOPE_H

#include <QObject>
#include <QElapsedTimer>
#include <QtGlobal>

class QWidget;
class QChart;
class QChartView;
class QLineSeries;
class QValueAxis;

class Scope : public QObject
{
public:
    explicit Scope(QObject *parent = nullptr);

    void init(QWidget *chartContainer);//创建图表、坐标轴、视图
    void configure(bool actualPositionEnabled,
                   bool targetPositionEnabled,
                   bool velocityEnabled,
                   bool accelerationEnabled,
                   int timeBaseMs,
                   int totalSeconds,
                   double range,
                   int triggerMode);

    void start();
    void stop();
    void clear();
    bool exportImage(QWidget *parent);
    bool isRunning() const;

    void appendSample(qint32 actualPosition, qint32 targetPosition, quint32 feedbackFreq);

private:
    double visibleWindowSeconds() const;
    void setupSeries();//创建并配置四个数据系列（实际位置、目标位置、速度、加速度），
    void appendPoint(QLineSeries *series, double x, double y, bool enabled);
    void refreshAxes(double x);
    bool hasVisibleChannel() const;

    QChart *m_chart = nullptr;                   // Qt图表对象
    QChartView *m_chartView = nullptr;           // 图表视图部件
    QValueAxis *m_axisX = nullptr;               // X轴（时间轴）
    QValueAxis *m_axisY = nullptr;               // Y轴（数值轴）
    QLineSeries *m_actualSeries = nullptr;       // 实际位置数据系列
    QLineSeries *m_targetSeries = nullptr;       // 目标位置数据系列
    QLineSeries *m_velocitySeries = nullptr;     // 速度数据系列
    QLineSeries *m_accelerationSeries = nullptr; // 加速度数据系列

    QElapsedTimer m_elapsed;
    qint64 m_lastSampleMs = -1;
    qint64 m_lastUiRefreshMs = -1;
    qint32 m_lastActualPosition = 0;
    double m_lastVelocity = 0.0;
    bool m_hasLastPosition = false;
    bool m_running = false;

    bool m_showActualPosition = true; // 是否显示实际位置通道
    bool m_showTargetPosition = true; // 是否显示目标位置通道
    bool m_showVelocity = false;      // 是否显示速度通道
    bool m_showAcceleration = false;  // 是否显示加速度通道
    int m_timeBaseMs = 1000;          // 采样时间基准（毫秒）
    int m_totalSeconds = 0;           // 总显示时长（秒），0表示滚动显示
    double m_range = 1000000.0;       // Y轴显示范围
    int m_triggerMode = 0;            // 触发模式（保留字段，当前未使用）
    int m_maxPoints = 20000;          // 每个数据系列的最大点数
    int m_uiRefreshIntervalMs = 33;
};





#endif // SCOPE_H
