#include "inc/Scope.h"

#include <QBrush>
#include <QChart>
#include <QChartView>
#include <QColor>
#include <QFileDialog>
#include <QGraphicsLineItem>
#include <QGraphicsSimpleTextItem>
#include <QHash>
#include <QLegend>
#include <QLineSeries>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QPointF>
#include <QValueAxis>
#include <QVBoxLayout>
#include <QtGlobal>
#include <functional>

namespace
{
    constexpr int kScopeMajorTickCount = 9;
    constexpr int kScopeMinorTickCount = 1;
    constexpr int kScopeTimeTickCount = 6;

    void configureAxisStyle(QValueAxis* axis, int tickCount, int minorTickCount)
    {
        if (!axis)
        {
            return;
        }

        axis->setTickCount(tickCount);
        axis->setMinorTickCount(minorTickCount);
        axis->setGridLineVisible(true);
        axis->setMinorGridLineVisible(true);
    }

    class ScopeChartView final : public QChartView
    {
    public:
        explicit ScopeChartView(QChart* chart, QWidget* parent = nullptr)
            : QChartView(chart, parent)
        {
            setMouseTracking(true);
        }

        std::function<void(Qt::MouseButton, const QPoint&)> onPress;
        std::function<void(Qt::MouseButtons, const QPoint&)> onMove;
        std::function<void(Qt::MouseButton, const QPoint&)> onRelease;

    protected:
        void mousePressEvent(QMouseEvent* event) override
        {
            if (onPress)
            {
                onPress(event->button(), event->pos());
            }
            event->accept();
        }

        void mouseMoveEvent(QMouseEvent* event) override
        {
            if (onMove)
            {
                onMove(event->buttons(), event->pos());
            }
            event->accept();
        }

        void mouseReleaseEvent(QMouseEvent* event) override
        {
            if (onRelease)
            {
                onRelease(event->button(), event->pos());
            }
            event->accept();
        }
    };

    struct ScopePrivateState
    {
        bool cursorEnabled = false;
        bool panning = false;
        bool draggingCursor = false;
        QPoint dragStartPos;
        double dragStartMinX = 0.0;
        double dragStartMaxX = 0.0;
        double dragStartMinY = 0.0;
        double dragStartMaxY = 0.0;
        bool followLatestData = true;
        QGraphicsLineItem* cursorLine = nullptr;
        QGraphicsSimpleTextItem* cursorLabel = nullptr;
    };

    QHash<const Scope*, ScopePrivateState*>& scopeStates()
    {
        static QHash<const Scope*, ScopePrivateState*> states;
        return states;
    }

    ScopePrivateState* stateFor(const Scope* scope)
    {
        auto& states = scopeStates();
        if (!states.contains(scope))
        {
            states.insert(scope, new ScopePrivateState());
        }
        return states.value(scope);
    }

    QPointF findNearestPoint(QLineSeries* series, double xValue)
    {
        if (!series || series->count() == 0)
        {
            return QPointF();
        }

        const QList<QPointF> points = series->points();
        QPointF bestPoint = points.first();
        double bestDistance = qAbs(bestPoint.x() - xValue);

        for (const QPointF& point : points)
        {
            const double distance = qAbs(point.x() - xValue);
            if (distance < bestDistance)
            {
                bestDistance = distance;
                bestPoint = point;
            }
        }

        return bestPoint;
    }

}

Scope::Scope(QObject* parent)
    : QObject(parent)
{
    stateFor(this);
}

void Scope::init(QWidget* chartContainer)
{
    if (!chartContainer)
    {
        return;
    }

    if (!m_chart)
    {
        m_chart = new QChart();
        m_chart->setTitle(QStringLiteral("Scope"));
        m_chart->setAnimationOptions(QChart::NoAnimation);
        m_chart->legend()->setVisible(true);
        m_chart->legend()->setAlignment(Qt::AlignTop);

        m_axisX = new QValueAxis();
        m_axisX->setTitleText(QStringLiteral("Time (s)"));
        m_axisX->setLabelFormat("%.2f");
        m_axisX->setRange(0.0, visibleWindowSeconds());
        configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);

        m_axisY = new QValueAxis();
        m_axisY->setTitleText(QStringLiteral("Value"));
        m_axisY->setLabelFormat("%.0f");
        m_axisY->setRange(-m_range, m_range);
        configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);

        m_chart->addAxis(m_axisX, Qt::AlignBottom);
        m_chart->addAxis(m_axisY, Qt::AlignLeft);
        setupSeries();
    }

    if (!m_chartView)
    {
        ScopeChartView* view = new ScopeChartView(m_chart, chartContainer);
        view->setRenderHint(QPainter::Antialiasing);
        view->setRubberBand(QChartView::NoRubberBand);

        view->onPress = [this](Qt::MouseButton button, const QPoint& pos)
            {
                ScopePrivateState* state = stateFor(this);
                if (state->cursorEnabled && button == Qt::LeftButton)
                {
                    state->draggingCursor = true;
                    if (m_chartView)
                    {
                        m_chartView->setCursor(Qt::SizeHorCursor);
                    }
                    if (m_chart)
                    {
                        const QRectF plotArea = m_chart->plotArea();
                        if (plotArea.contains(pos))
                        {
                            if (!state->cursorLine)
                            {
                                state->cursorLine = new QGraphicsLineItem(m_chart);
                                QPen pen(QColor(220, 80, 20));
                                pen.setWidth(1);
                                pen.setStyle(Qt::DashLine);
                                state->cursorLine->setPen(pen);
                            }
                            if (!state->cursorLabel)
                            {
                                state->cursorLabel = new QGraphicsSimpleTextItem(m_chart);
                                state->cursorLabel->setBrush(QBrush(QColor(20, 20, 20)));
                            }
                        }
                    }
                    return;
                }

                if ((!state->cursorEnabled && button == Qt::LeftButton) ||
                    (state->cursorEnabled && button == Qt::RightButton))
                {
                    if (!m_axisX || !m_axisY)
                    {
                        return;
                    }

                    state->panning = true;
                    state->followLatestData = false;
                    state->dragStartPos = pos;
                    state->dragStartMinX = m_axisX->min();
                    state->dragStartMaxX = m_axisX->max();
                    state->dragStartMinY = m_axisY->min();
                    state->dragStartMaxY = m_axisY->max();
                    if (m_chartView)
                    {
                        m_chartView->setCursor(Qt::ClosedHandCursor);
                    }
                }
            };

        view->onMove = [this](Qt::MouseButtons buttons, const QPoint& pos)
            {
                Q_UNUSED(buttons);
                ScopePrivateState* state = stateFor(this);

                if (state->draggingCursor)
                {
                    if (!m_chart || !m_axisY)
                    {
                        return;
                    }

                    const QRectF plotArea = m_chart->plotArea();
                    if (!plotArea.contains(pos))
                    {
                        return;
                    }

                    QLineSeries* referenceSeries = nullptr;
                    if (m_showActualPosition && m_actualSeries && m_actualSeries->count() > 0)
                    {
                        referenceSeries = m_actualSeries;
                    }
                    else if (m_showTargetPosition && m_targetSeries && m_targetSeries->count() > 0)
                    {
                        referenceSeries = m_targetSeries;
                    }
                    else if (m_showVelocity && m_velocitySeries && m_velocitySeries->count() > 0)
                    {
                        referenceSeries = m_velocitySeries;
                    }
                    else if (m_showAcceleration && m_accelerationSeries && m_accelerationSeries->count() > 0)
                    {
                        referenceSeries = m_accelerationSeries;
                    }

                    const QPointF chartValue = m_chart->mapToValue(pos);
                    const QPointF nearestPoint = findNearestPoint(referenceSeries, chartValue.x());
                    if (!referenceSeries || referenceSeries->count() == 0)
                    {
                        return;
                    }

                    if (!state->cursorLine)
                    {
                        state->cursorLine = new QGraphicsLineItem(m_chart);
                        QPen pen(QColor(220, 80, 20));
                        pen.setWidth(1);
                        pen.setStyle(Qt::DashLine);
                        state->cursorLine->setPen(pen);
                    }

                    if (!state->cursorLabel)
                    {
                        state->cursorLabel = new QGraphicsSimpleTextItem(m_chart);
                        state->cursorLabel->setBrush(QBrush(QColor(20, 20, 20)));
                    }

                    const QPointF top = m_chart->mapToPosition(QPointF(nearestPoint.x(), m_axisY->max()));
                    const QPointF bottom = m_chart->mapToPosition(QPointF(nearestPoint.x(), m_axisY->min()));
                    state->cursorLine->setLine(QLineF(top, bottom));
                    state->cursorLine->show();

                    state->cursorLabel->setText(QStringLiteral("t=%1s  y=%2")
                        .arg(nearestPoint.x(), 0, 'f', 3)
                        .arg(nearestPoint.y(), 0, 'f', 0));
                    state->cursorLabel->setPos(top + QPointF(6.0, 6.0));
                    state->cursorLabel->show();
                    return;
                }

                if (!state->panning || !m_chart || !m_axisX || !m_axisY)
                {
                    return;
                }

                const QRectF plotArea = m_chart->plotArea();
                if (plotArea.width() <= 0.0 || plotArea.height() <= 0.0)
                {
                    return;
                }

                const QPoint delta = pos - state->dragStartPos;
                const double spanX = state->dragStartMaxX - state->dragStartMinX;
                const double spanY = state->dragStartMaxY - state->dragStartMinY;
                const double dx = -(static_cast<double>(delta.x()) / plotArea.width()) * spanX;
                const double dy = (static_cast<double>(delta.y()) / plotArea.height()) * spanY;

                m_axisX->setRange(state->dragStartMinX + dx, state->dragStartMaxX + dx);
                m_axisY->setRange(state->dragStartMinY + dy, state->dragStartMaxY + dy);
                configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);
                configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);

                if (m_chartView)
                {
                    m_chartView->viewport()->update();
                }
            };

        view->onRelease = [this](Qt::MouseButton button, const QPoint& pos)
            {
                Q_UNUSED(pos);
                ScopePrivateState* state = stateFor(this);
                if (button == Qt::LeftButton)
                {
                    state->draggingCursor = false;
                }
                if (button == Qt::LeftButton || button == Qt::RightButton)
                {
                    state->panning = false;
                }
                if (m_chartView)
                {
                    m_chartView->unsetCursor();
                }
            };

        m_chartView = view;
    }

    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(chartContainer->layout());
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

    if (layout->indexOf(m_chartView) < 0)
    {
        layout->addWidget(m_chartView);
    }
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

    ScopePrivateState* state = stateFor(this);
    state->cursorEnabled = property("cursorEnabled").toBool();

    if (m_actualSeries) m_actualSeries->setVisible(m_showActualPosition);
    if (m_targetSeries) m_targetSeries->setVisible(m_showTargetPosition);
    if (m_velocitySeries) m_velocitySeries->setVisible(m_showVelocity);
    if (m_accelerationSeries) m_accelerationSeries->setVisible(m_showAcceleration);

    if (!state->cursorEnabled)
    {
        state->draggingCursor = false;
        if (state->cursorLine) state->cursorLine->hide();
        if (state->cursorLabel) state->cursorLabel->hide();
    }

    if (!state->panning)
    {
        if (m_axisY)
        {
            m_axisY->setRange(-m_range, m_range);
            configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);
        }

        if (m_axisX)
        {
            refreshAxes((m_running && m_elapsed.isValid()) ? m_elapsed.elapsed() / 1000.0 : 0.0);
        }
    }

    if (m_chart)
    {
        m_chart->update();
    }
    if (m_chartView)
    {
        m_chartView->viewport()->update();
    }
}

void Scope::start()
{
    if (!hasVisibleChannel())
    {
        return;
    }

    ScopePrivateState* state = stateFor(this);
    state->followLatestData = true;
    state->panning = false;
    state->draggingCursor = false;

    m_running = true;
    m_elapsed.restart();
    m_lastSampleMs = -1;
    m_lastUiRefreshMs = -1;
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

    m_lastSampleMs = -1;
    m_lastUiRefreshMs = -1;
    m_hasLastPosition = false;
    m_lastVelocity = 0.0;

    ScopePrivateState* state = stateFor(this);
    state->followLatestData = true;
    state->panning = false;
    state->draggingCursor = false;
    if (state->cursorLine) state->cursorLine->hide();
    if (state->cursorLabel) state->cursorLabel->hide();

    if (m_axisX)
    {
        m_axisX->setRange(0.0, visibleWindowSeconds());
        configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);
    }

    if (m_axisY)
    {
        m_axisY->setRange(-m_range, m_range);
        configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);
    }

    if (m_chart)
    {
        m_chart->update();
    }
}

bool Scope::exportImage(QWidget* parent)
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

bool Scope::isRunning() const
{
    return m_running;
}

void Scope::appendSample(qint32 actualPosition, qint32 targetPosition, quint32 feedbackFreq)
{
    if (!m_running || !hasVisibleChannel())
    {
        return;
    }

    const qint64 nowMs = m_elapsed.elapsed();
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

    appendPoint(m_actualSeries, x, actualPosition, true);
    appendPoint(m_targetSeries, x, targetPosition, true);
    appendPoint(m_velocitySeries, x, velocity, true);
    appendPoint(m_accelerationSeries, x, acceleration, true);

    m_lastActualPosition = actualPosition;
    m_lastVelocity = velocity;
    m_hasLastPosition = true;
    m_lastSampleMs = nowMs;

    ScopePrivateState* state = stateFor(this);
    if (m_lastUiRefreshMs < 0 || (nowMs - m_lastUiRefreshMs) >= m_uiRefreshIntervalMs)
    {
        if (state->followLatestData && !state->panning)
        {
            refreshAxes(x);
        }
        if (m_chart)
        {
            m_chart->update();
        }
        if (m_chartView)
        {
            m_chartView->viewport()->update();
        }
        m_lastUiRefreshMs = nowMs;
    }

    if (m_totalSeconds > 0 && x >= m_totalSeconds)
    {
        stop();
    }
}

double Scope::visibleWindowSeconds() const
{
    if (m_totalSeconds > 0)
    {
        return static_cast<double>(m_totalSeconds);
    }

    return qMax(1.0, static_cast<double>(m_timeBaseMs) / 1000.0);
}

void Scope::setupSeries()
{
    m_actualSeries = new QLineSeries();
    m_actualSeries->setName(QStringLiteral("actpos"));

    m_targetSeries = new QLineSeries();
    m_targetSeries->setName(QStringLiteral("cmd pos"));

    m_velocitySeries = new QLineSeries();
    m_velocitySeries->setName(QStringLiteral("vel"));

    m_accelerationSeries = new QLineSeries();
    m_accelerationSeries->setName(QStringLiteral("acc"));

    const QList<QLineSeries*> seriesList = {
        m_actualSeries,
        m_targetSeries,
        m_velocitySeries,
        m_accelerationSeries
    };

    for (QLineSeries* series : seriesList)
    {
        m_chart->addSeries(series);
        series->attachAxis(m_axisX);
        series->attachAxis(m_axisY);
    }

    m_velocitySeries->setVisible(m_showVelocity);
    m_accelerationSeries->setVisible(m_showAcceleration);
}

void Scope::appendPoint(QLineSeries* series, double x, double y, bool enabled)
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

    const double visibleSeconds = visibleWindowSeconds();
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

    configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);
    m_axisY->setRange(-m_range, m_range);
    configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);
}

bool Scope::hasVisibleChannel() const
{
    return m_showActualPosition || m_showTargetPosition || m_showVelocity || m_showAcceleration;
}
