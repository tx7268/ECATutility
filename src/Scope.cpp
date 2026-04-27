#include "inc/Scope.h"

#include <QChart>
#include <QChartView>
#include <QFileDialog>
#include <QLegend>
#include <QLineSeries>
#include <QPainter>
#include <QPixmap>
#include <QVBoxLayout>
#include <QValueAxis>

Scope::Scope(QObject *parent)
    : QObject(parent)
{
}

void Scope::init(QWidget *chartContainer)
{
    if (!chartContainer)
    {
        return;
    }

    if (!m_chart)
    {
        m_chart = new QChart();
        m_chart->setTitle(QStringLiteral("Scope"));
        m_chart->legend()->setVisible(true);
        m_chart->legend()->setAlignment(Qt::AlignTop);

        m_axisX = new QValueAxis();
        m_axisX->setTitleText(QStringLiteral("Time (s)"));
        m_axisX->setLabelFormat("%.2f");
        m_axisX->setRange(0.0, 30.0);

        m_axisY = new QValueAxis();
        m_axisY->setTitleText(QStringLiteral("Value"));
        m_axisY->setLabelFormat("%.0f");
        m_axisY->setRange(-m_range, m_range);

        m_chart->addAxis(m_axisX, Qt::AlignBottom);
        m_chart->addAxis(m_axisY, Qt::AlignLeft);
        setupSeries();
    }

    if (!m_chartView)
    {
        m_chartView = new QChartView(m_chart, chartContainer);
        m_chartView->setRenderHint(QPainter::Antialiasing);
        m_chartView->setRubberBand(QChartView::RectangleRubberBand);
    }

    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(chartContainer->layout());
    if (!layout)
    {
        layout = new QVBoxLayout(chartContainer);
        layout->setContentsMargins(2, 2, 2, 2);
        layout->setSpacing(0);
    }

    if (m_chartView->parentWidget() != chartContainer)
    {
        m_chartView->setParent(chartContainer);
    }
    layout->addWidget(m_chartView);
}

void Scope::configure(bool actualPositionEnabled,
                      bool targetPositionEnabled,
                      bool velocityEnabled,
                      bool accelerationEnabled,
                      int timeBaseMs,
                      int totalSeconds,
                      double range,
                      int triggerMode)
{
    m_showActualPosition = actualPositionEnabled;
    m_showTargetPosition = targetPositionEnabled;
    m_showVelocity = velocityEnabled;
    m_showAcceleration = accelerationEnabled;
    m_timeBaseMs = qMax(10, timeBaseMs);
    m_totalSeconds = qMax(0, totalSeconds);
    m_range = qMax(1.0, range);
    m_triggerMode = triggerMode;
    Q_UNUSED(m_triggerMode);

    if (m_actualSeries) m_actualSeries->setVisible(m_showActualPosition);
    if (m_targetSeries) m_targetSeries->setVisible(m_showTargetPosition);
    if (m_velocitySeries) m_velocitySeries->setVisible(m_showVelocity);
    if (m_accelerationSeries) m_accelerationSeries->setVisible(m_showAcceleration);

    if (m_axisY)
    {
        m_axisY->setRange(-m_range, m_range);
    }
    if (m_axisX)
    {
        const double visibleSeconds = m_totalSeconds > 0 ? m_totalSeconds : 30.0;
        m_axisX->setRange(0.0, visibleSeconds);
    }
}

void Scope::start()
{
    if (!hasVisibleChannel())
    {
        return;
    }

    m_running = true;
    m_elapsed.restart();
    m_lastAppendMs = -1;
    m_lastSampleMs = -1;
    m_hasLastPosition = false;
    m_lastVelocity = 0.0;
}

void Scope::stop()
{
    m_running = false;
}

void Scope::clear()
{
    if (m_actualSeries) m_actualSeries->clear();
    if (m_targetSeries) m_targetSeries->clear();
    if (m_velocitySeries) m_velocitySeries->clear();
    if (m_accelerationSeries) m_accelerationSeries->clear();

    m_lastAppendMs = -1;
    m_lastSampleMs = -1;
    m_hasLastPosition = false;
    m_lastVelocity = 0.0;

    if (m_axisX)
    {
        const double visibleSeconds = m_totalSeconds > 0 ? m_totalSeconds : 30.0;
        m_axisX->setRange(0.0, visibleSeconds);
    }
}

bool Scope::exportImage(QWidget *parent)
{
    if (!m_chartView)
    {
        return false;
    }

    const QString filePath = QFileDialog::getSaveFileName(
        parent,
        QStringLiteral("Export Scope Image"),
        QStringLiteral("scope.png"),
        QStringLiteral("PNG Image (*.png);;JPEG Image (*.jpg);;BMP Image (*.bmp);;All Files (*.*)"));

    if (filePath.isEmpty())
    {
        return false;
    }

    return m_chartView->grab().save(filePath);
}

void Scope::appendSample(qint32 actualPosition, qint32 targetPosition, quint32 feedbackFreq)
{
    if (!m_running || !hasVisibleChannel())
    {
        return;
    }

    const qint64 nowMs = m_elapsed.elapsed();
    if (m_lastAppendMs >= 0 && (nowMs - m_lastAppendMs) < m_timeBaseMs)
    {
        return;
    }

    const double x = nowMs / 1000.0;
    double dt = 0.0;
    if (m_lastSampleMs >= 0)
    {
        dt = (nowMs - m_lastSampleMs) / 1000.0;
    }
    else if (feedbackFreq > 0)
    {
        dt = 1.0 / static_cast<double>(feedbackFreq);
    }

    double velocity = 0.0;
    double acceleration = 0.0;
    if (m_hasLastPosition && dt > 0.0)
    {
        velocity = (static_cast<double>(actualPosition) - static_cast<double>(m_lastActualPosition)) / dt;
        acceleration = (velocity - m_lastVelocity) / dt;
    }

    appendPoint(m_actualSeries, x, actualPosition, m_showActualPosition);
    appendPoint(m_targetSeries, x, targetPosition, m_showTargetPosition);
    appendPoint(m_velocitySeries, x, velocity, m_showVelocity);
    appendPoint(m_accelerationSeries, x, acceleration, m_showAcceleration);

    m_lastActualPosition = actualPosition;
    m_lastVelocity = velocity;
    m_hasLastPosition = true;
    m_lastAppendMs = nowMs;
    m_lastSampleMs = nowMs;

    refreshAxes(x);

    if (m_totalSeconds > 0 && x >= m_totalSeconds)
    {
        stop();
    }
}

void Scope::setupSeries()
{
    m_actualSeries = new QLineSeries();
    m_actualSeries->setName(QStringLiteral("actpos"));

    m_targetSeries = new QLineSeries();
    m_targetSeries->setName(QStringLiteral("target pos"));

    m_velocitySeries = new QLineSeries();
    m_velocitySeries->setName(QStringLiteral("vel"));

    m_accelerationSeries = new QLineSeries();
    m_accelerationSeries->setName(QStringLiteral("acc"));

    const QList<QLineSeries *> seriesList = {
        m_actualSeries,
        m_targetSeries,
        m_velocitySeries,
        m_accelerationSeries
    };

    for (QLineSeries *series : seriesList)
    {
        m_chart->addSeries(series);
        series->attachAxis(m_axisX);
        series->attachAxis(m_axisY);
    }

    m_velocitySeries->setVisible(m_showVelocity);
    m_accelerationSeries->setVisible(m_showAcceleration);
}

void Scope::appendPoint(QLineSeries *series, double x, double y, bool enabled)
{
    if (!series || !enabled)
    {
        return;
    }

    series->append(x, y);
    if (series->count() > m_maxPoints)
    {
        series->removePoints(0, series->count() - m_maxPoints);
    }
}

void Scope::refreshAxes(double x)
{
    if (!m_axisX || !m_axisY)
    {
        return;
    }

    const double visibleSeconds = m_totalSeconds > 0 ? m_totalSeconds : 30.0;
    if (m_totalSeconds > 0)
    {
        m_axisX->setRange(0.0, visibleSeconds);
    }
    else if (x > visibleSeconds)
    {
        m_axisX->setRange(x - visibleSeconds, x);
    }
    else
    {
        m_axisX->setRange(0.0, visibleSeconds);
    }

    m_axisY->setRange(-m_range, m_range);
}

bool Scope::hasVisibleChannel() const
{
    return m_showActualPosition || m_showTargetPosition || m_showVelocity || m_showAcceleration;
}
