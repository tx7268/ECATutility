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
    void init(QWidget *chartContainer);

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

    void appendSample(qint32 actualPosition, qint32 targetPosition, quint32 feedbackFreq);

private:
    void setupSeries();
    void appendPoint(QLineSeries *series, double x, double y, bool enabled);
    void refreshAxes(double x);
    bool hasVisibleChannel() const;

    QChart *m_chart = nullptr;
    QChartView *m_chartView = nullptr;
    QValueAxis *m_axisX = nullptr;
    QValueAxis *m_axisY = nullptr;
    QLineSeries *m_actualSeries = nullptr;
    QLineSeries *m_targetSeries = nullptr;
    QLineSeries *m_velocitySeries = nullptr;
    QLineSeries *m_accelerationSeries = nullptr;

    QElapsedTimer m_elapsed;
    qint64 m_lastAppendMs = -1;
    qint64 m_lastSampleMs = -1;
    qint32 m_lastActualPosition = 0;
    double m_lastVelocity = 0.0;
    bool m_hasLastPosition = false;
    bool m_running = false;

    bool m_showActualPosition = true;
    bool m_showTargetPosition = true;
    bool m_showVelocity = false;
    bool m_showAcceleration = false;
    int m_timeBaseMs = 1000;
    int m_totalSeconds = 0;
    double m_range = 1000000.0;
    int m_triggerMode = 0;
    int m_maxPoints = 20000;
};





#endif // SCOPE_H
