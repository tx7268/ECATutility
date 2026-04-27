#include"inc/RunTime.h"
#include <QBrush>
#include <QVariant>
#include <QStringList>
#include <QStringConverter>
#include <QAbstractItemView>
#include <QComboBox>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QTimer>

RunTime::RunTime(QObject *parent)
    : QObject(parent)
    , m_timeoutTimer(new QTimer(this))
{
    // 设置超时检测定时器
    m_timeoutTimer->setInterval(100); // 每100ms检测一次
    connect(m_timeoutTimer, &QTimer::timeout, this, &RunTime::checkTimeoutCommands);
    m_timeoutTimer->start(); // 启动定时器
}

RunTime::~RunTime()
{

}


void RunTime::init(QTableWidget* tableWidget, QComboBox* filterComboBox, QWidget* dialogParent)
{
    m_tableWidget = tableWidget;
    m_filterComboBox = filterComboBox;
    m_dialogParent = dialogParent;

    if (m_tableWidget)
    {
        m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    if (m_filterComboBox)
    {
        m_filterComboBox->addItem("ALL", QVariant(0));
        m_filterComboBox->addItem("OK", QVariant(1));
        m_filterComboBox->addItem("ERROR", QVariant(2));
        m_filterComboBox->addItem("TimeOut", QVariant(3));
        connect(m_filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &RunTime::filterRunTimeLog);
    }
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

void RunTime::sendCmdWithLog(const QByteArray& data, const QString& cmdName, int sendValue)
{
    emit sendSerialDataRequested(data);

    LogSendInfo info;
    info.seq = ++m_logSeq;
    info.cmdName = cmdName;
    info.sendValue = sendValue;
    info.sendTime = QDateTime::currentMSecsSinceEpoch();
    m_sendLogQueue.enqueue(info);

    QString time = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    addLogRow(time, info.seq, info.cmdName, info.sendValue, 0, 0, "发送中");
}

void RunTime::updateLogRow(int retValue, const QString& status)
{
    if (!m_tableWidget || m_sendLogQueue.isEmpty()) return;

    LogSendInfo info = m_sendLogQueue.dequeue();
    double delay = (QDateTime::currentMSecsSinceEpoch() - info.sendTime);
    int row = info.seq - 1;
    if (row < 0 || row >= m_tableWidget->rowCount()) return;

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
        LogSendInfo& firstInfo = m_sendLogQueue.head();
        qint64 timePassed = currentTime - firstInfo.sendTime;

        if (timePassed < m_commandTimeoutMs)
            break;

        int row = firstInfo.seq - 1;
        if (row >= 0 && row < m_tableWidget->rowCount())
        {
            QTableWidgetItem* statusItem = new QTableWidgetItem("TimeOut");
            statusItem->setForeground(QBrush(Qt::red));
            m_tableWidget->setItem(row, 6, statusItem);
            m_tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(timePassed / 1000.0, 'f', 2)));
        }

        const QString cmdName = firstInfo.cmdName;
        const int seq = firstInfo.seq;
        m_sendLogQueue.dequeue();
        emit logMessage(QString("命令超时：%1（序号：%2）").arg(cmdName).arg(seq));
    }
}

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

void RunTime::clearLog()
{
    if (!m_tableWidget) return;

    m_tableWidget->setRowCount(0);
    m_logSeq = 0;
    m_sendLogQueue.clear();
    emit logMessage("RunTime表格日志已清空");
}

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