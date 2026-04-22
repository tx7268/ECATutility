#include "inc/Link.h"

Link::Link(QObject *parent)
    :QObject{parent}
    , m_serialThread(new SerialThread(this))
    , m_serialPortName("")
    , m_baudRate(115200)
    , m_isSerialOpen(false)
    , m_isEcatConnected(false)
    , m_slaveNumbers(1)
{
    connect(m_serialThread, &SerialThread::portOpened, this, &Link::onPortOpened);
    connect(m_serialThread, &SerialThread::portClosed, this, &Link::onPortClosed);
    connect(m_serialThread, &SerialThread::dataReceived, this, &Link::onDataReceived);
    connect(m_serialThread, &SerialThread::errorOccurred, this, &Link::onThreadError);
    connect(m_serialThread, &SerialThread::logMessage, this, &Link::onThreadLog);
}

Link::~Link()
{
    closeSerialPort();    // 析构时自动关闭串口
    closeEcat();          // 析构时自动断开 ECAT
}

void Link::setSerialPortName(const QString& portName)
{
    m_serialPortName = portName;
    m_serialThread->setPortName(portName);
}

void Link::setBaudRate(qint32 baudRate)
{
    m_baudRate = baudRate;
    m_serialThread->setBaudRate(baudRate);
}

void Link::setSlaveNumbers(int slaveNum) { m_slaveNumbers = slaveNum; }

QString Link::getSerialPortName() const { return m_serialPortName; }
qint32 Link::getBaudRate() const { return m_baudRate; }
int Link::getSlaveNumbers() const { return m_slaveNumbers; }

bool Link::isSerialPortOpen() const { return m_isSerialOpen; }
bool Link::isEcatConnected() const { return m_isEcatConnected; }


// 扫描可用串口
void Link::scanSerialPorts()
{
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    emit serialPortListUpdated(portList);

    if(portList.size() <1)
    {
        emit logMessage(QString("未扫描到可用串口"));
    }
    else
    {
        emit logMessage(QString("扫描到 %1 个可用串口").arg(portList.size()));
    }

}

//打开串口
void Link::openSerialPorts()
{
    if(m_isSerialOpen)
    {
        emit serialPortStatusChanged(true,"串口已开启");
        return;
    }

    if(m_serialPortName.isEmpty())
    {
        emit serialPortErrorOccurred("串口端口为空");
        emit logMessage("打开串口失败：串口端口为空");
        return;
    }

    // 委托线程打开串口
    m_serialThread->openPort();
}

//关闭串口
void Link::closeSerialPort()
{
    if (!m_isSerialOpen)
    {
        emit serialPortStatusChanged(false, "串口已关闭，无需重复操作");
        return;
    }

    m_serialThread->closePort();
}


void Link::sendSerialData(const QByteArray& sendData)
{
    if (!m_isSerialOpen)
    {
        emit logMessage("串口发送失败：串口未打开");
        return;
    }
    if (sendData.isEmpty())
    {
        emit logMessage("串口发送失败：待发送数据为空");
        return;
    }

    // 通过线程发送数据
    m_serialThread->sendData(sendData);
}


void Link::sendUtfData(const QString& sendText)
{
    QByteArray data = sendText.toUtf8();
    sendSerialData(data);
}


// ==================== 线程信号槽处理 ====================

void Link::onPortOpened(bool success, const QString& msg)
{
    m_isSerialOpen = success;
    emit serialPortStatusChanged(success, msg);
}

void Link::onPortClosed(const QString& msg)
{
    m_isSerialOpen = false;
    emit serialPortStatusChanged(false, msg);
}

void Link::onDataReceived(const QByteArray& data)
{
    emit serialDataReceived(data);
}

void Link::onThreadError(const QString& error)
{
    emit serialPortErrorOccurred(error);
}

void Link::onThreadLog(const QString& msg)
{
    emit logMessage(msg);
}

//*****************************************ECAT连接处理*****************************************
//ECAT扫描从站
void Link::scanSlaves()
{

}

//打开ECAT连接
void Link::openEcat()
{
    if (m_isEcatConnected)
    {
        emit ecatConnectionStatusChanged(true, "ECAT 已连接，无需重复操作");
        return;
    }

    /*
        todo

    */

    m_isEcatConnected = true;
    emit ecatConnectionStatusChanged(true, QString("ECAT 连接成功，从站数量 %1").arg(m_slaveNumbers));
    emit logMessage(QString("ECAT 连接成功，从站数量 %1").arg(m_slaveNumbers));
}


void Link::closeEcat()
{
    if (!m_isEcatConnected)
    {
        emit ecatConnectionStatusChanged(false, "ECAT 已断开，无需重复操作");
        return;
    }

    /*
        todo

    */

    m_isEcatConnected = false;
    emit ecatConnectionStatusChanged(false, "ECAT 已断开连接");
    emit logMessage("ECAT 已断开连接");
}