#include "inc/SerialThread.h"
#include <QDebug>

SerialThread::SerialThread(QObject* parent)
    :QThread(parent)
    , m_serialPort(new QSerialPort(this))
    , m_baudRate(115200)
    , m_running(false)
    , m_isOpen(false)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialThread::onReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialThread::handleSerialError);
}


SerialThread::~SerialThread()
{
    // 先关闭串口
    closePort();

    // 停止线程
    m_mutex.lock();
    m_running = false;
    m_mutex.unlock();
    m_waitCondition.wakeOne();

    // 等待线程结束
    if (isRunning())
    {
        wait(3000);
    }
}

void SerialThread::setPortName(const QString& portName)
{
    QMutexLocker locker(&m_mutex);
    m_portName = portName;
}

void SerialThread::setBaudRate(qint32 baudRate)
{
    QMutexLocker locker(&m_mutex);
    m_baudRate = baudRate;
}

bool SerialThread::openPort()
{
    QMutexLocker locker(&m_mutex);

    if (m_isOpen)
    {
        emit logMessage("串口已打开");
        return true;
    }

    // 配置串口参数
    m_serialPort->setPortName(m_portName);
    m_serialPort->setBaudRate(m_baudRate);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadWrite))
    {
        m_isOpen = true;
        m_running = true;
        start(); //启动线程
        emit portOpened(true, QString("串口 %1 打开成功，波特率 %2")
                                  .arg(m_portName)
                                  .arg(m_baudRate));
        emit logMessage(QString("串口 %1 打开成功").arg(m_portName));
        return true;
    }
    else
    {
        emit portOpened(false, m_serialPort->errorString());
        emit logMessage(QString("串口打开失败: %1").arg(m_serialPort->errorString()));
        return false;
    }
}

void SerialThread::closePort()
{
    QMutexLocker locker(&m_mutex);

    if (!m_isOpen)
    {
        emit logMessage("串口已关闭");
        return;
    }

    m_running = false;
    m_waitCondition.wakeOne();
    m_mutex.unlock();

    // 等待线程退出
    if (isRunning())
    {
        wait(2000);
    }

    // 重新加锁
    m_mutex.lock();

    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }

    m_isOpen = false;
    m_sendQueue.clear();

    emit portClosed(QString("串口 %1 已关闭").arg(m_portName));
    emit logMessage(QString("串口 %1 已关闭").arg(m_portName));
}

bool SerialThread::isOpen() const
{
    m_mutex.lock();
    bool result = m_isOpen;
    m_mutex.unlock();
    return result;
}

void SerialThread::sendData(const QByteArray& data)
{
    QMutexLocker locker(&m_mutex);

    if (!m_isOpen)
    {
        emit logMessage("串口未打开，发送失败");
        return;
    }

    m_sendQueue.enqueue(data);
    m_waitCondition.wakeOne(); // 唤醒线程处理发送
}



void SerialThread::onReadyRead()
{
    QByteArray newData = m_serialPort->readAll();// 读取所有新到的原始数据

    if (newData.isEmpty())
    {
        return;
    }
    emit dataReceived(newData);

    m_receiveBuffer.append(newData);// 将新数据追加到累积缓冲区

    int lineEndIndex;
    // 循环查找缓冲区中的换行符 (‘\n’ )
    while ((lineEndIndex = m_receiveBuffer.indexOf('\n')) != -1)
    {
        // 提取一行数据 (包含换行符)
        QByteArray completeLine = m_receiveBuffer.left(lineEndIndex + 1);
        // 从缓冲区中移除已处理的行
        m_receiveBuffer.remove(0, lineEndIndex + 1);

        // 去除行首尾的空白字符（回车\r、换行\n）
        completeLine = completeLine.trimmed();

        if (completeLine.isEmpty())
            continue;

        bool isValidText = true;
        for (const char &c : completeLine)
        {
            if (static_cast<unsigned char>(c) < 0x20 && c != '\n' && c != '\r' && c != '\t')
            {
                isValidText = false;
                break;
            }
        }

        if (isValidText)
        {
            QString logMsg = QString::fromUtf8(completeLine);
            emit logMessage(QString("[接收]%1").arg(logMsg));
        }
    }

}

void SerialThread::run()
{
    while (true)
    {
        m_mutex.lock();

        if (!m_running)
        {
            m_mutex.unlock();
            break;
        }

        //如果发送队列为空，等待唤醒
        while (m_running && m_sendQueue.isEmpty())
        {
            m_waitCondition.wait(&m_mutex);
        }

        //处理发送队列
        if (!m_sendQueue.isEmpty())
        {
            QByteArray data = m_sendQueue.dequeue();
            m_mutex.unlock();

            //发送数据
            qint64 sent = m_serialPort->write(data);
            m_serialPort->flush();

            if (sent > 0)
            {
                emit logMessage(QString("[发送]：%2").arg(byteArrayToHex(data)));
            }
            else
            {
                emit logMessage(QString("发送失败 %1 ").arg(m_serialPort->errorString()));
            }
        }
        else
        {
            m_mutex.unlock();
        }

        // 短暂休眠，避免CPU占用过高
        msleep(10);
    }
}



void SerialThread::handleSerialError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::NoError)
    {
        return;
    }

    QString errorMsg;
    switch (error)
    {
    case QSerialPort::ResourceError:
        errorMsg = "串口连接意外断开";
        m_isOpen = false;
        m_running = false;
        break;
    case QSerialPort::PermissionError:
        errorMsg = "串口权限错误";
        break;
    case QSerialPort::OpenError:
        errorMsg = "串口打开错误";
        break;
    default:
        errorMsg = m_serialPort->errorString();
        break;
    }

    emit errorOccurred(errorMsg);
    emit logMessage(QString("串口错误: %1").arg(errorMsg));

    if (error == QSerialPort::ResourceError)
    {
        closePort();
    }
}

// 工具函数：将QByteArray转为十六进制字符串
QString SerialThread::byteArrayToHex(const QByteArray& data) const
{
    if (data.isEmpty()) {
        return "[]";
    }
    return data.toHex(' ').toUpper();
}
