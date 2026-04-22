#ifndef LINK_H
#define LINK_H

#include <QObject>
#include <QSerialPortInfo>
#include <QString>
#include <QList>
#include "SerialThread.h"

class Link : public QObject
{
    Q_OBJECT

public:
    explicit Link(QObject *parent = nullptr);
    ~Link();

    // 配置参数（给 UI 调用的接口）
    void setSerialPortName(const QString &portName);  // 设置串口名
    void setBaudRate(qint32 baudRate);                // 设置波特率
    void setSlaveNumbers(int slaveNum);               // 设置ECAT从站数量
    QString getSerialPortName() const;
    qint32 getBaudRate() const;
    int getSlaveNumbers() const;


    bool isSerialPortOpen() const;
    bool isEcatConnected() const;

public slots:

    // 串口扫描打开初始化关闭函数
    void scanSerialPorts();
    void openSerialPorts();
    void closeSerialPort();

    // ECAT通信函数
    void scanSlaves();
    void openEcat();
    void closeEcat();

    // 串口发送数据函数
    void sendSerialData(const QByteArray& sendData);
    void sendUtfData(const QString& sendText); // 重载：文本转字节（UTF8）


signals:
    // 串口相关信号（通知 UI）
    void serialPortListUpdated(const QList<QSerialPortInfo> &portList); // 扫描到的串口列表
    void serialPortStatusChanged(bool isOpen, const QString &msg);       // 串口状态变化（打开/关闭）
    void serialPortErrorOccurred(const QString &errorMsg);               // 串口错误

    // ECAT 相关信号（通知 UI）
    void ecatConnectionStatusChanged(bool isConnected, const QString &msg); // ECAT 连接状态
    void ecatErrorOccurred(const QString &errorMsg);                         // ECAT 错误

    // 通用日志信号（给日志面板）
    void logMessage(const QString &msg);
    void serialDataReceived(const QByteArray &data);

    // 串口发送结果反馈信号（是否成功、发送字节数、备注）
    void serialDataSent(bool isSuccess, qint64 bytesSent, const QString& msg);


private slots:
    void onPortOpened(bool success, const QString& msg);
    void onPortClosed(const QString& msg);
    void onDataReceived(const QByteArray& data);
    void onThreadError(const QString& error);
    void onThreadLog(const QString& msg);

private:
    // 串口成员变量
    SerialThread* m_serialThread;
    QString m_serialPortName;
    qint32 m_baudRate;
    bool m_isSerialOpen;

    // ECAT 成员变量
    bool m_isEcatConnected;
    int m_slaveNumbers;


};

#endif // LINK_H
