#include "inc/SerialThread.h"

SerialThread::SerialThread(QObject* parent)
    : QThread(parent)
    , m_serialPort(new QSerialPort(this))
    , m_baudRate(115200)
    , m_running(false)
    , m_isOpen(false)
{
    // 串口有数据到达触发onReadyRead槽函数
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialThread::onReadyRead);
    // 串口发生错误触发handleSerialError槽函数
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &SerialThread::handleSerialError);
}


SerialThread::~SerialThread()
{
    closePort();

    m_mutex.lock();
    m_running = false;
    m_mutex.unlock();
    m_waitCondition.wakeAll();

    if (isRunning())
    {
        quit();
        wait(3000);
    }
}

//设置串口名称线程安全
void SerialThread::setPortName(const QString& portName)
{
    QMutexLocker locker(&m_mutex);
    m_portName = portName;
}

//设置波特率线程安全
void SerialThread::setBaudRate(qint32 baudRate)
{
    QMutexLocker locker(&m_mutex);
    m_baudRate = baudRate;
}

/**
 * @brief 打开串口：配置参数 + 打开设备
 * @return 打开结果
 */
bool SerialThread::openPort()
{
    QMutexLocker locker(&m_mutex);

    if (m_isOpen)
    {
        emit logMessage("串口已打开");
        return true;
    }

    // ====================== 配置串口参数（8N1标准配置） ======================
    m_serialPort->setPortName(m_portName);        // 串口名
    m_serialPort->setBaudRate(m_baudRate);        // 波特率
    m_serialPort->setDataBits(QSerialPort::Data8);// 数据位：8位
    m_serialPort->setParity(QSerialPort::NoParity);// 校验位：无
    m_serialPort->setStopBits(QSerialPort::OneStop);// 停止位：1位
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);// 流控制：无
    m_serialPort->setReadBufferSize(4096);        // 接收缓冲区大小4K

    if (!m_serialPort->open(QIODevice::ReadWrite))
    {
        emit portOpened(false, m_serialPort->errorString());
        emit logMessage(QString("串口打开失败: %1").arg(m_serialPort->errorString()));
        return false;
    }

    m_isOpen = true;
    m_running = true;
    m_sendQueue.clear();
    m_receiveBuffer.clear();
    m_serialPort->clear();

    // 发送打开成功信号
    emit portOpened(true, QString("串口 %1 打开成功，波特率 %2")
        .arg(m_portName)
        .arg(m_baudRate));
    emit logMessage(QString("串口 %1 打开成功").arg(m_portName));
    return true;
}

//关闭串口释放资源重置状态
void SerialThread::closePort()
{
    QMutexLocker locker(&m_mutex);

    if (!m_isOpen)
    {
        emit logMessage("串口已关闭");
        return;
    }

    m_running = false;
    m_waitCondition.wakeAll();

    if (m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }

    m_isOpen = false;
    m_sendQueue.clear();
    m_receiveBuffer.clear();

    emit portClosed(QString("串口 %1 已关闭").arg(m_portName));
    emit logMessage(QString("串口 %1 已关闭").arg(m_portName));
}

bool SerialThread::isOpen() const
{
    QMutexLocker locker(&m_mutex);
    return m_isOpen;
}

void SerialThread::sendData(const QByteArray& data)
{
    QMutexLocker locker(&m_mutex);

    if (!m_isOpen)
    {
        emit logMessage("串口未打开，发送失败");
        return;
    }

    const qint64 sent = m_serialPort->write(data);
    if (sent != data.size())
    {
        emit logMessage(QString("发送失败: %1").arg(m_serialPort->errorString()));
        return;
    }

    if (!m_serialPort->waitForBytesWritten(100))
    {
        emit logMessage(QString("发送超时: %1").arg(m_serialPort->errorString()));
        return;
    }

    emit logMessage(QString("[发送]：%1").arg(byteArrayToHex(data)));
}

void SerialThread::onReadyRead()
{
    QByteArray newData = m_serialPort->readAll();
    if (newData.isEmpty())
    {
        return;
    }

    emit dataReceived(newData);

    m_receiveBuffer.append(newData);
    int lineEndIndex = -1;
    while ((lineEndIndex = m_receiveBuffer.indexOf('\n')) != -1)
    {
        QByteArray completeLine = m_receiveBuffer.left(lineEndIndex + 1).trimmed();
        m_receiveBuffer.remove(0, lineEndIndex + 1);

        if (completeLine.isEmpty())
        {
            continue;
        }

        bool isValidText = true;
        for (const char c : completeLine)
        {
            const unsigned char uc = static_cast<unsigned char>(c);
            if (uc < 0x20 && c != '\n' && c != '\r' && c != '\t')
            {
                isValidText = false;
                break;
            }
        }

        if (isValidText)
        {
            emit logMessage(QString("[接收]%1").arg(QString::fromUtf8(completeLine)));
        }
    }
}

/**
 * @brief 线程入口函数
 * 启动Qt事件循环，让子线程能够处理信号槽
 */
void SerialThread::run()
{
    exec();
}

//串口错误处理函数，error 串口错误码
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

//字节数组转十六进制字符串（格式化显示）
QString SerialThread::byteArrayToHex(const QByteArray& data) const
{
    if (data.isEmpty())
    {
        return "[]";
    }
    return data.toHex(' ').toUpper();
}
