#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QSerialPort>
#include <QMutex>
#include <QWaitCondition>
#include <QQueue>
#include <QByteArray>


class SerialThread : public QThread
{
    Q_OBJECT

public:
    explicit SerialThread(QObject *parent = nullptr);
    ~SerialThread();

    // 配置接口
    void setPortName(const QString &portName);
    void setBaudRate(qint32 baudRate);

    // 控制接口
    bool openPort();
    void closePort();
    void sendData(const QByteArray &data);
    bool isOpen() const;

signals:
    void portOpened(bool success, const QString &msg);
    void portClosed(const QString &msg);
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QString &error);
    void logMessage(const QString &msg);

protected:
    void run() override;

private slots:
    void onReadyRead();

private:
    QString byteArrayToHex(const QByteArray& data) const;
    void processReceivedData();
    void handleSerialError(QSerialPort::SerialPortError error);

    QSerialPort *m_serialPort;
    QString m_portName;
    qint32 m_baudRate;

    mutable QMutex m_mutex;
    QWaitCondition m_waitCondition;

    QQueue<QByteArray> m_sendQueue;
    bool m_running;
    bool m_isOpen;

    QByteArray m_receiveBuffer;
};



#endif // SERIALTHREAD_H
