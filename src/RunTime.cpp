#include "inc/RunTime.h"
#include <QStringList>
#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QVBoxLayout>
#include <QPen>
#include <QColor>

#include <algorithm>
#include <cmath>

// ====================== 全局常量配置 ======================
namespace
{
    constexpr double kRuntimeDefaultMinFreq = 950.0;    // 默认最小频率
    constexpr double kRuntimeDefaultMaxFreq = 1020.0;   // 默认最大频率
    constexpr double kRuntimeRangePaddingRatio = 0.05;  // 坐标轴留白比例
    constexpr double kRuntimeRangePaddingFloor = 2.0;   // 坐标轴最小留白

    constexpr int kRuntimeMajorTickCount = 8;           // 主刻度数量
    constexpr int kRuntimeMinorTickCount = 1;           // 副刻度数量

    constexpr double kFreqFilterThreshold = 2000.0;// 频率过滤阈值：超过2000Hz的数据直接丢弃

     /**
     * @brief 配置图表坐标轴样式（刻度、网格）
     * @param axis 数值坐标轴对象
     */
    void configureRuntimeAxis(QValueAxis* axis)
    {
        if (!axis)
        {
            return;
        }

        axis->setTickCount(kRuntimeMajorTickCount);
        axis->setMinorTickCount(kRuntimeMinorTickCount);
        axis->setGridLineVisible(true);
        axis->setMinorGridLineVisible(true);
    }
}

// ====================== 图表线程实现 ======================
ChartThread::ChartThread(QObject *parent) : QThread(parent)
{}

void ChartThread::run()
{
    // 线程独立事件循环，专门处理图表数据
    exec();
}

void ChartThread::addFreqData(double freq)
{
    // 子线程抛信号给UI更新
    emit chartDataUpdated(freq, -1);
}


// ====================== RunTime 主类实现 ======================
RunTime::RunTime(QObject *parent)
    : QObject(parent)
    , m_timeoutTimer(new QTimer(this))// 创建超时检测定时器
{
    // 设置超时检测定时器
    m_timeoutTimer->setInterval(50); // 每100ms检测一次
    connect(m_timeoutTimer, &QTimer::timeout, this, &RunTime::checkTimeoutCommands);
    m_timeoutTimer->start(); // 启动定时器

    // 创建图表线程
    m_chartThread = new ChartThread(this);
    m_chartThread->start();
}

RunTime::~RunTime()
{
    m_chartThread->quit();
    m_chartThread->wait();
    m_timeoutTimer->stop();
}


/**
 * @brief 初始化RunTime模块，绑定UI控件
 * @param tableWidget 日志表格
 * @param filterComboBox 日志过滤器
 * @param dialogParent 弹窗父控件
 * @param chartParent 图表父控件
 */
void RunTime::init(QTableWidget* tableWidget, QComboBox* filterComboBox, QWidget* dialogParent, QWidget *chartParent)
{
    m_tableWidget = tableWidget;
    m_filterComboBox = filterComboBox;
    m_dialogParent = dialogParent;
    m_chartParent = chartParent; 

    if (m_tableWidget)// 设置表格不可编辑
    {
        m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    if (m_filterComboBox)
    {
        m_filterComboBox->addItem("ALL", QVariant(0));
        m_filterComboBox->addItem("OK", QVariant(1));
        m_filterComboBox->addItem("ERROR", QVariant(2));
        m_filterComboBox->addItem("TimeOut", QVariant(3));
        // 连接过滤器的选择变化信号
        connect(m_filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &RunTime::filterRunTimeLog);
    }

    // 创建图表
    createChart();
    connect(m_chartThread, &ChartThread::chartDataUpdated, this, &RunTime::updateChart, Qt::QueuedConnection);
}


/**
 * @brief 创建实时频率监控图表
 */
void RunTime::createChart()
{
    if(!m_chartParent) return;

    // 创建图表
    m_chart = new QChart();
    m_chart->setTitle("ECAT 周期频率实时监控");
    m_chart->setTitleFont(QFont("Microsoft YaHei", 10, QFont::Bold));
    m_chart->setBackgroundBrush(QColor(248, 248, 248));
    m_chart->legend()->setVisible(true);
    m_chart->legend()->setAlignment(Qt::AlignBottom);

    // 创建曲线
    m_seriesFreq = new QLineSeries();
    QPen penFreq(QColor(0, 112, 192));
    penFreq.setWidth(1);
    m_seriesFreq->setPen(penFreq);

    // X轴（数据点序号）
    m_axisX = new QValueAxis();
    m_axisX->setRange(0, MAX_DATA_COUNT);
    m_axisX->setLabelFormat("%d");
    //m_axisX->setGridLineVisible(true);
    configureRuntimeAxis(m_axisX);

    // Y轴（频率值）
    m_axisY = new QValueAxis();
    m_axisY->setTitleText("频率(Hz)");
    m_axisY->setRange(kRuntimeDefaultMinFreq, kRuntimeDefaultMaxFreq); // 默认ECAT频率范围
    m_axisY->setLabelFormat("%d");
    configureRuntimeAxis(m_axisY);

    // 绑定坐标轴
    m_chart->addAxis(m_axisX, Qt::AlignBottom);
    m_chart->addAxis(m_axisY, Qt::AlignLeft);
    m_chart->addSeries(m_seriesFreq);
    m_seriesFreq->attachAxis(m_axisX);
    m_seriesFreq->attachAxis(m_axisY);

    // 图表视图（抗锯齿）
    m_chartView = new QChartView(m_chart, m_chartParent);
    m_chartView->setRenderHint(QPainter::Antialiasing);

    //将图表添加到父控件
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(m_chartParent->layout());
    if (!layout)
    {
        layout = new QVBoxLayout(m_chartParent);
        layout->setContentsMargins(0, 0, 0, 0);
    }
    if (layout->indexOf(m_chartView) < 0)
    {
        layout->addWidget(m_chartView);
    }
}

/**
 * @brief 外部接口：更新ECAT实时频率
 * @param freq 频率值
 */
void RunTime::onEcatFreqUpdated(quint32 freq)
{
    m_chartThread->addFreqData(freq);
}


void RunTime::updateChart(double freq)
{
    if (!m_seriesFreq || !m_axisX || !m_axisY || !m_chart)
    {
        return;
    }

    // 过滤2000Hz以上频率
    if (freq > kFreqFilterThreshold)
    {
        return;
    }

    // 追加频率数据
    m_seriesFreq->append(m_xIndex++, freq);
    m_dataHistory.append(freq);

    // 滚动显示：超过最大点数，移除旧数据
    if (m_seriesFreq->count() > MAX_DATA_COUNT)
        if (m_seriesFreq->count() > MAX_DATA_COUNT)
        {
            m_seriesFreq->removePoints(0, 1);
            if (!m_dataHistory.isEmpty())
            {
                m_dataHistory.removeFirst();
            }
        }

    // 自适应X轴范围
    if (m_xIndex > MAX_DATA_COUNT)
    {
        m_axisX->setRange(m_xIndex - MAX_DATA_COUNT, m_xIndex);
    }
    else
    {
        m_axisX->setRange(0, MAX_DATA_COUNT);
    }

    double minFreq = kRuntimeDefaultMinFreq;
    double maxFreq = kRuntimeDefaultMaxFreq;
    if (!m_dataHistory.isEmpty())
    {
        auto minmax = std::minmax_element(m_dataHistory.cbegin(), m_dataHistory.cend());
        minFreq = *minmax.first;
        maxFreq = *minmax.second;
    }

    const double span = qMax(maxFreq - minFreq, 1.0);
    const double padding = qMax(span * kRuntimeRangePaddingRatio, kRuntimeRangePaddingFloor);
    m_axisY->setRange(minFreq - padding, maxFreq + padding);

    if (maxFreq > m_maxFreq)
    {
        m_maxFreq = maxFreq;
    }

    configureRuntimeAxis(m_axisX);
    configureRuntimeAxis(m_axisY);

    m_chart->update();

    if (m_chartView)
    {
        m_chartView->viewport()->update();
    }
}


void RunTime::calculateStats()
{
    // 重置动态指标
    m_stats.maxLatency = 0;
    m_stats.minLatency = 0;
    m_stats.avgLatency = 0;
    m_stats.currentLatency = 0;
    m_stats.jitter = 0;

    if (m_stats.latencyList.isEmpty()) // 无有效延时，直接计算丢包率
    {
        if (m_stats.totalPackets > 0)
        {
            m_stats.packetLossRate = (double)m_stats.timeoutPackets / m_stats.totalPackets * 100;
        }
        else
        {
            m_stats.packetLossRate = 0;
        }
        return;
    }

    // 当前延时 = 最后一次有效延时
    m_stats.currentLatency = m_stats.latencyList.last();

    // 最大/最小延时
    m_stats.minLatency = *std::min_element(m_stats.latencyList.begin(), m_stats.latencyList.end());
    m_stats.maxLatency = *std::max_element(m_stats.latencyList.begin(), m_stats.latencyList.end());

    // 平均延时
    double sum = 0;
    for (double t : m_stats.latencyList)
        sum += t;
    m_stats.avgLatency = sum / m_stats.latencyList.size();

    // 抖动（相邻延时绝对差的平均值）
    if (m_stats.latencyList.size() >= 2)
    {
        double jitterSum = 0;
        for (int i = 1; i < m_stats.latencyList.size(); i++)
        {
            jitterSum += fabs(m_stats.latencyList[i] - m_stats.latencyList[i - 1]);
        }
        m_stats.jitter = jitterSum / (m_stats.latencyList.size() - 1);
    }

    // 丢包率
    if (m_stats.totalPackets > 0)
    {
        m_stats.packetLossRate = (double)m_stats.timeoutPackets / m_stats.totalPackets * 100;
    }
    else
    {
        m_stats.packetLossRate = 0;
    }

    // 实时把延时传给图表线程
    emit statsUpdated(m_stats);
}

void RunTime::addLogRow(QString time, int seq, QString cmd, int send, int ret, double delay, QString status)
{
    if (!m_tableWidget) return;

    int row = m_tableWidget->rowCount();
    m_tableWidget->insertRow(row);

    m_tableWidget->setItem(row, 0, new QTableWidgetItem(time));
    m_tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(seq)));
    m_tableWidget->setItem(row, 2, new QTableWidgetItem(cmd));
    m_tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(send)));
    m_tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(ret)));
    m_tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(delay, 'f', 2)));

    QTableWidgetItem* statusItem = new QTableWidgetItem(status);
    if (status == "OK")
    {
        statusItem->setForeground(QBrush(Qt::green));
    }
    else if (status == "ERROR" || status == "TimeOut")
    {
        statusItem->setForeground(QBrush(Qt::red));
    }
    m_tableWidget->setItem(row, 6, statusItem);

    m_tableWidget->scrollToBottom();
}


// 发送命令并记录日志
void RunTime::sendCmdWithLog(const QByteArray& data, const QString& cmdName, int sendValue)
{
    emit sendSerialDataRequested(data);// 发送串口数据

    LogSendInfo info;
    info.seq = ++m_logSeq;
    info.cmdName = cmdName;
    info.sendValue = sendValue;
    info.sendTime = QDateTime::currentMSecsSinceEpoch();
    m_sendLogQueue.enqueue(info);

    // 更新统计：总包数+1
    m_stats.totalPackets++;
    calculateStats();
    emit statsUpdated(m_stats); // 发送更新信号

    QString time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    addLogRow(time, info.seq, info.cmdName, info.sendValue, 0, 0, "发送中");
}


// 接收响应 + 更新成功/错误统计
void RunTime::updateLogRow(int retValue, const QString& status)
{
    if (!m_tableWidget || m_sendLogQueue.isEmpty()) return;

    LogSendInfo info = m_sendLogQueue.dequeue();
    double delay = (QDateTime::currentMSecsSinceEpoch() - info.sendTime);
    int row = info.seq - 1;
    if (row < 0 || row >= m_tableWidget->rowCount()) return;

    // 更新统计：成功/错误包数
    if (status == "OK")
    {
        m_stats.okPackets++;
        m_stats.latencyList.append(delay); // 仅OK记录有效延时
    }
    else if (status == "ERROR")
    {
        m_stats.errorPackets++;
    }
    calculateStats();
    emit statsUpdated(m_stats); // 发送更新信号

    m_tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(retValue)));
    m_tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(delay, 'f', 2)));

    QTableWidgetItem* statusItem = new QTableWidgetItem(status);
    if (status == "OK")
    {
        statusItem->setForeground(QBrush(Qt::green));
    }
    else if (status == "ERROR" || status == "TimeOut")
    {
        statusItem->setForeground(QBrush(Qt::red));
    }
    m_tableWidget->setItem(row, 6, statusItem);
}


void RunTime::checkTimeoutCommands()
{
    if (!m_tableWidget || m_sendLogQueue.isEmpty())
        return;

    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();

    while (!m_sendLogQueue.isEmpty())
    {
        LogSendInfo& firstInfo = m_sendLogQueue.first();
        qint64 timePassed = currentTime - firstInfo.sendTime;

        if (timePassed < m_commandTimeoutMs)
            break;

        // 更新统计：超时包数+1
        m_stats.timeoutPackets++;
        calculateStats();
        emit statsUpdated(m_stats); // 发送更新信号

        int row = firstInfo.seq - 1;
        if (row >= 0 && row < m_tableWidget->rowCount())
        {
            QTableWidgetItem* statusItem = new QTableWidgetItem("TimeOut");
            statusItem->setForeground(QBrush(Qt::red));
            m_tableWidget->setItem(row, 6, statusItem);
            m_tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(timePassed, 'f', 2)));
        }

        const QString cmdName = firstInfo.cmdName;
        const int seq = firstInfo.seq;
        m_sendLogQueue.dequeue();
        emit logMessage(QString("命令超时：%1（序号：%2）").arg(cmdName).arg(seq));
    }
}


// 过滤运行时日志
void RunTime::filterRunTimeLog(int index)
{
    Q_UNUSED(index)

    if (!m_tableWidget || !m_filterComboBox) return;

    int filterType = m_filterComboBox->currentData().toInt();
    int rowCount = m_tableWidget->rowCount();
    for (int i = 0; i < rowCount; i++)
    {
        QTableWidgetItem* statusItem = m_tableWidget->item(i, 6);
        if (!statusItem) continue;

        QString status = statusItem->text();
        bool showRow = false;

        switch (filterType)
        {
        case 0:
            showRow = true;
            break;
        case 1:
            showRow = (status == "OK");
            break;
        case 2:
            showRow = (status == "ERROR");
            break;
        case 3:
            showRow = (status == "TimeOut");
            break;
        default:
            showRow = true;
        }

        m_tableWidget->setRowHidden(i, !showRow);
    }
}

// 清空日志
void RunTime::clearLog()
{
    if (!m_tableWidget)
        return;

    m_tableWidget->setRowCount(0);
    m_logSeq = 0;
    m_sendLogQueue.clear();

    // ====================== 重置图表 ======================
    if(m_seriesFreq)
    {
        m_seriesFreq->clear();
        m_xIndex = 0;
        m_maxFreq = 0;
        m_axisX->setRange(0, MAX_DATA_COUNT);
        m_axisY->setRange(980, 1000);
        m_chart->update();
    }
    // 重置统计数据
    m_stats = RunTimeStats();
    emit statsUpdated(m_stats); // 发送清空信号

    emit logMessage("RunTime表格日志已清空");
}

// 导出日志
void RunTime::exportLog()
{
    if (!m_tableWidget) return;

    int rowCount = m_tableWidget->rowCount();
    if (rowCount == 0)
    {
        QMessageBox::information(m_dialogParent, "提示", "表格日志为空，无需导出");
        return;
    }

    QString defaultFileName = QString("RunTimeLog_%1.csv").arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));

    QString filePath = QFileDialog::getSaveFileName(
        m_dialogParent,
        "导出表格日志",
        defaultFileName,
        "CSV文件 (*.csv);;文本文件 (*.txt);;所有文件 (*.*)"
    );

    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(m_dialogParent, "导出失败",
            QString("文件无法打开！%1").arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out.setGenerateByteOrderMark(true);

    out << "时间戳,序号(Seq),命令,发送值,返回值,延时(ms),状态\n";

    for (int i = 0; i < rowCount; i++)
    {
        QStringList rowData;
        for (int col = 0; col < 7; col++)
        {
            QTableWidgetItem* item = m_tableWidget->item(i, col);
            rowData << (item ? item->text() : "");
        }

        out << rowData.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(m_dialogParent, "导出成功",
        QString("日志已导出到：\n%1").arg(filePath));
    emit logMessage(QString("RunTime表格日志已导出到：%1").arg(filePath));
}


