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

//封装示波器的私有辅助函数、自定义视图、状态管理
namespace
{
    constexpr int kScopeMajorTickCount = 9; // Y轴主刻度数
    constexpr int kScopeMinorTickCount = 1; // 主刻度之间再插入副刻度数
    constexpr int kScopeTimeTickCount = 6;  // X轴时间刻度数

    // 统一配置坐标轴的刻度和网格风格。
    // Scope 中所有坐标轴刷新最终都走这里，避免散落重复代码。
    void configureAxisStyle(QValueAxis* axis, int tickCount, int minorTickCount)
    {
        if (!axis)
        {
            return;
        }

        axis->setTickCount(tickCount);
        axis->setMinorTickCount(minorTickCount);
        axis->setGridLineVisible(true);      // 显示主网格线
        axis->setMinorGridLineVisible(true); // 显示副网格线
    }

    /**
     * @brief 自定义图表视图类
     * 重写鼠标事件，实现：光标测量、画布拖拽功能
     * 对 QChartView 做一层轻量封装，把鼠标事件转成回调。
     * 这样 Scope 主体不需要额外派生 QObject，也不需要改头文件新增槽函数。
     */
    class ScopeChartView final : public QChartView
    {
    public:
        explicit ScopeChartView(QChart* chart, QWidget* parent = nullptr)
            : QChartView(chart, parent)
        {
            setMouseTracking(true);// 开启鼠标追踪
        }

        // 三个回调分别对应按下、移动、释放。
        // Scope 在 init() 中把具体交互逻辑绑定到这里。
        std::function<void(Qt::MouseButton, const QPoint&)> onPress;
        std::function<void(Qt::MouseButtons, const QPoint&)> onMove;
        std::function<void(Qt::MouseButton, const QPoint&)> onRelease;

    protected:
    
        // 重写鼠标按下事件
        void mousePressEvent(QMouseEvent* event) override
        {
            if (onPress)
            {
                onPress(event->button(), event->pos());
            }
            event->accept();
        }

        // 重写鼠标移动事件
        void mouseMoveEvent(QMouseEvent* event) override
        {
            if (onMove)
            {
                onMove(event->buttons(), event->pos());
            }
            event->accept();
        }

        // 重写鼠标释放事件
        void mouseReleaseEvent(QMouseEvent* event) override
        {
            if (onRelease)
            {
                onRelease(event->button(), event->pos());
            }
            event->accept();
        }
    };

    /**
     * @brief 示波器私有状态结构体
     * 存储每个示波器实例的交互状态（光标、拖拽、视图跟随等）
     */
    struct ScopePrivateState
    {
        bool cursorEnabled = false;                     // 测量光标是否启用
        bool panning = false;                           // 是否正在拖拽画布
        bool draggingCursor = false;                    // 是否正在拖动测量光标
        QPoint dragStartPos;                            // 拖拽起始坐标
        double dragStartMinX = 0.0;                     // 拖拽起始X轴最小值
        double dragStartMaxX = 0.0;                     // 拖拽起始X轴最大值
        double dragStartMinY = 0.0;                     // 拖拽起始Y轴最小值
        double dragStartMaxY = 0.0;                     // 拖拽起始Y轴最大值
        bool followLatestData = true;                   // 视图是否跟随最新数据(滚动模式)
        QGraphicsLineItem *cursorLine = nullptr;        // 测量光标竖线
        QGraphicsSimpleTextItem *cursorLabel = nullptr; // 光标数值标签
    };

    /**
     * @brief 全局状态哈希表
     * 单例模式，存储所有Scope实例的私有状态
     * 为每个 Scope 实例维护一份外部私有状态。
     * @return 状态哈希表引用
     */
    QHash<const Scope*, ScopePrivateState*>& scopeStates()
    {
        static QHash<const Scope*, ScopePrivateState*> states;
        return states;
    }

    /**
     * @brief 取出当前 Scope 对应的私有状态；若还不存在则自动创建。
     * @param scope 示波器实例
     * @return 私有状态指针
     */
    ScopePrivateState* stateFor(const Scope* scope)
    {
        auto& states = scopeStates();
        if (!states.contains(scope))
        {
            states.insert(scope, new ScopePrivateState());
        }
        return states.value(scope);
    }

    // 在某条曲线中找到离当前光标 X 值最近的采样点。
    // 光标吸附、读数显示都依赖这个函数。
    QPointF findNearestPoint(QLineSeries* series, double xValue)
    {
        if (!series || series->count() == 0)
        {
            return QPointF();
        }

        // 遍历查找最小距离点
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
    stateFor(this);// 构造时先确保该 Scope 对应的交互状态已建立。
}

void Scope::init(QWidget* chartContainer)
{
    if (!chartContainer)
    {
        return;
    }

    if (!m_chart)
    {
        // 创建图表对象
        m_chart = new QChart();
        // m_chart->setTitle(QStringLiteral("Scope"));
        // m_chart->setAnimationOptions(QChart::NoAnimation);
        // m_chart->legend()->setVisible(true);
        // m_chart->legend()->setAlignment(Qt::AlignTop);

        // 创建X轴
        m_axisX = new QValueAxis();
        m_axisX->setTitleText(QStringLiteral("Time (s)"));
        m_axisX->setLabelFormat("%.2f");
        m_axisX->setRange(0.0, visibleWindowSeconds());
        configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);

        // 创建Y轴
        m_axisY = new QValueAxis();
        m_axisY->setTitleText(QStringLiteral("Value"));
        m_axisY->setLabelFormat("%.0f");
        m_axisY->setRange(-m_range, m_range);
        configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);

        // 将坐标轴添加到图表
        m_chart->addAxis(m_axisX, Qt::AlignBottom);
        m_chart->addAxis(m_axisY, Qt::AlignLeft);
        setupSeries();// 创建4条数据曲线
    }

    // 创建自定义图表视图
    if (!m_chartView)
    {
        ScopeChartView* view = new ScopeChartView(m_chart, chartContainer);
        view->setRenderHint(QPainter::Antialiasing);
        view->setRubberBand(QChartView::NoRubberBand);

        // ==================== 绑定鼠标按下事件 ====================
        // 1. cursor 模式开启时，左键用于拖光标
        // 2. cursor 模式关闭时，左键用于拖动画布
        // 3. cursor 模式开启时，右键用于拖动画布
        view->onPress = [this](Qt::MouseButton button, const QPoint& pos)
            {
                ScopePrivateState* state = stateFor(this);
                // 左键：拖动测量光标，不改坐标轴范围
                if (state->cursorEnabled && button == Qt::LeftButton)
                {
                    state->draggingCursor = true;
                    if (m_chartView)
                    {
                        m_chartView->setCursor(Qt::SizeHorCursor);// 创建光标线条和标签
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

                // 左键/右键：拖拽画布平移
                if ((!state->cursorEnabled && button == Qt::LeftButton) ||
                    (state->cursorEnabled && button == Qt::RightButton))
                {
                    // 进入“拖动画布”模式。
                    // 这里记录拖动开始瞬间的坐标轴范围，
                    // 后续通过鼠标位移把像素位移映射回坐标轴偏移量。
                    if (!m_axisX || !m_axisY)
                    {
                        return;
                    }

                    state->panning = true;
                    state->followLatestData = false;// 停止跟随最新数据
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

        // ==================== 绑定鼠标移动事件 ====================
        // 优先处理光标拖动；如果当前不在拖光标，再判断是否在拖动画布。
        view->onMove = [this](Qt::MouseButtons buttons, const QPoint& pos)
            {
                Q_UNUSED(buttons);
                ScopePrivateState* state = stateFor(this);

                // 光标模式下，把鼠标位置换算成图表 X 值，
                // 然后吸附到最近的数据点上显示读数。
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

                    // 选择优先级最高的可见曲线作为参考
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

                    // 先把鼠标像素坐标转成图表值坐标，再在曲线中找最近点。
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

                    // 文本显示当前吸附点的时间和值。
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

                // 鼠标位移（像素）转换为坐标轴位移（数据值）。
                // X 方向为左右平移时间轴，Y 方向为上下平移量程窗口。
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

        // 鼠标释放时退出当前交互态并恢复光标外观。
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

    // 保证容器上有布局，并把图表视图加入进去。
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

    // cursorEnabled 通过外部 setProperty("cursorEnabled", ...) 注入，
    // 这里读取后写入交互私有状态。
    ScopePrivateState* state = stateFor(this);
    state->cursorEnabled = property("cursorEnabled").toBool();

    // 根据外部配置更新四条曲线的显示开关。
    if (m_actualSeries) m_actualSeries->setVisible(m_showActualPosition);
    if (m_targetSeries) m_targetSeries->setVisible(m_showTargetPosition);
    if (m_velocitySeries) m_velocitySeries->setVisible(m_showVelocity);
    if (m_accelerationSeries) m_accelerationSeries->setVisible(m_showAcceleration);

    if (!state->cursorEnabled)
    {
        // 光标模式关闭时，立即停止拖光标并隐藏图形元素。
        state->draggingCursor = false;
        if (state->cursorLine) state->cursorLine->hide();
        if (state->cursorLabel) state->cursorLabel->hide();
    }

    if (!state->panning)
    {
        // 只有当前不在手动拖动画布时，才允许 configure() 改写坐标轴范围。
        // 否则用户拖动中的视图会被实时配置打断。
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
        return;// 没有任何可见通道时，不进入运行态。
    }

    // 开始采样时重新进入“跟随最新数据”模式。
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
    m_running = false;// stop 只停止后续采样追加，不清空历史曲线。
}

void Scope::clear()
{
    // 清除四条曲线缓存点。
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

    // 清空后隐藏光标相关图形。
    if (state->cursorLine) state->cursorLine->hide();
    if (state->cursorLabel) state->cursorLabel->hide();

    if (m_axisX)
    {
        // X 轴恢复到当前时基下的初始窗口。
        m_axisX->setRange(0.0, visibleWindowSeconds());
        configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);
    }

    if (m_axisY)
    {
        // Y 轴恢复到当前量程。
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
    return m_running;// 仅返回当前运行态标志，不代表图上是否已有历史数据。
}

void Scope::appendSample(qint32 actualPosition, qint32 targetPosition, quint32 feedbackFreq)
{
    if (!m_running || !hasVisibleChannel())
    {
        return;// 未运行或没有可见通道时，直接忽略采样。
    }

    // 以 start() 之后经过的时间作为 X 轴时间戳
    const qint64 nowMs = m_elapsed.elapsed();
    const double x = nowMs / 1000.0;

    // dt 用于推导速度和加速度。
    // 正常情况下由相邻两帧时间差得到；
    // 第一帧没有历史时间时，可用反馈频率估算一个 dt。
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
        // 速度 = 位置差 / 时间差
        // 加速度 = 速度差 / 时间差
        velocity = (static_cast<double>(actualPosition) - static_cast<double>(m_lastActualPosition)) / dt;
        acceleration = (velocity - m_lastVelocity) / dt;
    }

    // 四条曲线统一追加，是否真正落点由 appendPoint() 内的 enabled 决定。
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
        // 若当前仍处于“跟随最新数据”模式，且用户没有手动拖动画布，
        // 就自动滚动 X 轴到最新位置。
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
        stop();// 固定总时长模式下，到达终点后自动停止采样。
    }
}

double Scope::visibleWindowSeconds() const
{
    if (m_totalSeconds > 0)// 固定总时长模式：窗口宽度就是总时长。
    {
        return static_cast<double>(m_totalSeconds);
    }

    // 滚动模式：窗口宽度由时基决定。
    return qMax(1.0, static_cast<double>(m_timeBaseMs) / 1000.0);
}

// 创建四条曲线并设置图例名称。
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

    // 统一把曲线加入图表并绑定到同一组坐标轴。
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

    series->append(x, y);// 追加新点
    if (series->count() > m_maxPoints)
    {
        // 只保留最近 m_maxPoints 个点，限制内存占用。
        series->removePoints(0, series->count() - m_maxPoints);
    }
}

void Scope::refreshAxes(double x)
{
    if (!m_axisX || !m_axisY)
    {
        return;
    }

    // X 轴分两种模式：
    // 1. 固定总时长模式：始终显示 [0, totalSeconds]
    // 2. 滚动模式：开始阶段显示 [0, window]，超过窗口后随最新点右移
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

    // 每次刷新时同步重新设置坐标轴风格，保证拖动和重配后刻度稳定。
    configureAxisStyle(m_axisX, kScopeTimeTickCount, kScopeMinorTickCount);
    m_axisY->setRange(-m_range, m_range);
    configureAxisStyle(m_axisY, kScopeMajorTickCount, kScopeMinorTickCount);
}

// 至少有一条曲线可见时，Scope 才有实际绘图意义。
bool Scope::hasVisibleChannel() const
{
    return m_showActualPosition || m_showTargetPosition || m_showVelocity || m_showAcceleration;
}
