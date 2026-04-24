#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QFile>

#include <QDateTime>

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

#include "inc/Link.h"
#include "inc/Protocol.h"
#include "inc/SerialThread.h"
#include "inc/XML.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,m_link(new Link(this))
    ,proto(new Protocol(this))
    ,m_xml(new XML(this))
{
    ui->setupUi(this);
    setWindowTitle("ECATutility");
    QChart *chart = new QChart();
    ui->chartView->setChart(chart);
    setWindowIcon(QIcon(":/icons/ECAT"));
    ui->stackedWidget->hide();

    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_2->show();

    ui->btn_open_port->setCheckable(true);
    ui->btn_open_port->setText("打开串口");

    m_link->scanSerialPorts();

    updateSerialPortButtons();

    QList<QPushButton *> dioButtons =
        {
            ui->btn_do0_0, ui->btn_do0_1, ui->btn_do0_2, ui->btn_do0_3,
            ui->btn_do0_4, ui->btn_do0_5, ui->btn_do0_6, ui->btn_do0_7,
            ui->btn_do1_0, ui->btn_do1_1, ui->btn_do1_2, ui->btn_do1_3,
            ui->btn_do1_4, ui->btn_do1_5, ui->btn_do1_6, ui->btn_do1_7,
            ui->btn_do2_0, ui->btn_do2_1, ui->btn_do2_2, ui->btn_do2_3,
            ui->btn_do2_4, ui->btn_do2_5, ui->btn_do2_6, ui->btn_do2_7
        };

    for (QPushButton* btn : dioButtons)
    {
        btn->setCheckable(true);          // 允许选中/取消选中
    }

    QStringList standardBaudRates =
        {
            "1200", "2400", "4800", "9600",
            "19200", "38400", "57600", "115200",
            "230400", "460800", "921600"
        };

    ui->comboBox_baud_rate->addItems(standardBaudRates);
    ui->comboBox_baud_rate->setCurrentText("115200");

    ui->comboBox_data_type->addItem("uint8_t", 1);
    ui->comboBox_data_type->addItem("uint16_t", 2);
    ui->comboBox_data_type->addItem("uint32_t", 4);

    ui->comboBox_mode_chose->addItem("ABS", QVariant(0));  // 0: 绝对位置运动
    ui->comboBox_mode_chose->addItem("REL", QVariant(1));  // 1: 相对位置运动
    ui->comboBox_mode_chose->addItem("DEG", QVariant(2));  // 1: 相对位置运动
    ui->comboBox_mode_chose->addItem("HOME", QVariant(3)); // 2: 回零运动
    ui->comboBox_mode_chose->setCurrentIndex(0);           // 默认ABS模式
    // 限制只能输入32位有符号整数
    ui->lineEdit_motion_value->setValidator(new QIntValidator(-2147483648, 2147483647, this));

    // ======================HOME模式禁用输入框 ======================
    connect(ui->comboBox_mode_chose, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index){
    if (index == 3)
    { 
        ui->lineEdit_motion_value->setEnabled(false);
    }
    else 
    { 
        ui->lineEdit_motion_value->setEnabled(true);
        ui->lineEdit_motion_value->setText("0");
    } });

    ui->comboBox_mode->addItem("PP", QVariant(op_mode_pp));
    ui->comboBox_mode->addItem("CSP", QVariant(op_mode_csp));
    ui->comboBox_mode->addItem("HOME", QVariant(op_mode_hm));

    ui->comboBox_home_mode->addItem("33：反向回零，原点为电机Z信号", QVariant(33));
    ui->comboBox_home_mode->addItem("34：正向回零，原点为电机Z信号", QVariant(34));
    ui->comboBox_home_mode->addItem("35：以当前位置为原点", QVariant(35));

    ui->comboBox_slave_num->addItem("从站1", QVariant(1));

    //***********************************************信号槽连接***********************************************//
    // 刷新串口按钮 → 触发扫描
    connect(ui->btn_refresh_port, &QPushButton::clicked, m_link, &Link::scanSerialPorts);

    // 串口列表更新 → 填充下拉框
    connect(m_link, &Link::serialPortListUpdated, this, [this](const QList<QSerialPortInfo>& ports) {
        ui->comboBox_device_port->clear();

        for (const QSerialPortInfo& port : ports)
        {
            ui->comboBox_device_port->addItem(port.portName());
        }

        //无可用端口时禁用对应按钮
        ui->btn_open_port->setEnabled(!ports.isEmpty());
        ui->comboBox_device_port->setCurrentIndex(0);

        });

    // 打开串口按钮1 → 触发打开
    connect(ui->btn_open_port, &QPushButton::clicked, this, [this]() {
        if (m_serialPortOpen) 
        {
            closeSerialPort();
        } 
        else 
        {
            openSerialPort();
        }
    });

    // 打开串口按钮2 → 触发打开
    connect(ui->btn_open_port_2, &QPushButton::clicked, this, [this]() {
        if (m_serialPortOpen) 
        {
            closeSerialPort();
        } 
        else 
        {
            openSerialPort();
        }
    });

    connect(m_link, &Link::serialPortStatusChanged, this, [this](bool isOpen, const QString& msg) {
        m_serialPortOpen = isOpen;  // 更新状态
        updateSerialPortButtons();   // 同步按钮状态

        if (isOpen) 
        {
            appendlog("串口已打开: " + msg);
        } 
        else 
        {
            appendlog("串口已关闭: " + msg);
            m_link->scanSerialPorts(); // 串口断开后重新扫描
        }
    });

    connect(m_link, &Link::serialDataReceived, this, &Widget::serialReadData);

    connect(m_link, &Link::logMessage, this, [this](const QString &msg) {
        this->appendlog(msg);
        });

    connect(ui->btn_link_device, &QPushButton::clicked, this, [this]() {
        m_link->setSlaveNumbers(ui->textEdit_slave_numbers->toPlainText().toInt());
        m_link->openEcat();
        });

    connect(ui->btn_unlink, &QPushButton::clicked, m_link, &Link::closeEcat);

}

Widget::~Widget()
{
    delete ui;
}

//**********************************************左侧按键列表**********************************************//

//******************************连接LINK按键******************************
void Widget::on_btn_link_clicked()
{
    const int target_index = 0;

    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->btn_link->setChecked(false);
        ui->stackedWidget->hide();
    }
    else
    {
        ui->btn_link->setChecked(true);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(false);
        ui->btn_scope->setChecked(false);
        ui->btn_RunTime->setChecked(false);

        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }

}

//******************************ECAT按键******************************
void Widget::on_btn_ECAT_clicked()
{
    const int target_index = 2;

    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->btn_ECAT->setChecked(false);
        ui->stackedWidget->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(true);
        ui->btn_set->setChecked(false);
        ui->btn_scope->setChecked(false);
        ui->btn_RunTime->setChecked(false);

        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }
}

//******************************SET设置按键******************************
void Widget::on_btn_set_clicked()
{
    const int target_index = 1;

    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->btn_set->setChecked(false);
        ui->stackedWidget->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(true);
        ui->btn_scope->setChecked(false);
        ui->btn_RunTime->setChecked(false);

        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }

}

//******************************Scope设置按键******************************
void Widget::on_btn_scope_clicked()
{
    const int target_index = 3;
    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->btn_scope->setChecked(false);
        ui->stackedWidget->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(false);
        ui->btn_scope->setChecked(true);
        ui->btn_RunTime->setChecked(false);

        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }
}

//******************************RunTime设置按键******************************
void Widget::on_btn_RunTime_clicked()
{
    const int target_index = 4;
    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->btn_RunTime->setChecked(false);
        ui->stackedWidget->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(false);
        ui->btn_scope->setChecked(false);
        ui->btn_RunTime->setChecked(true);


        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }
}




//******************************enable按键******************************
void Widget::on_btn_enable_clicked()
{
    ui->btn_link->setChecked(false);
    ui->btn_ECAT->setChecked(false);
    ui->btn_set->setChecked(false);
    ui->stackedWidget->hide();

    m_link->sendSerialData(proto->enableAllAxes());
}

//******************************disable按键******************************
void Widget::on_btn_disable_clicked()
{
    ui->btn_link->setChecked(false);
    ui->btn_ECAT->setChecked(false);
    ui->btn_set->setChecked(false);
    ui->stackedWidget->hide();

    m_link->sendSerialData(proto->disableAllAxes());
}

//******************************重启伺服驱动器按键******************************
void Widget::on_btn_reboot_clicked()
{
    ui->btn_link->setChecked(false);
    ui->btn_ECAT->setChecked(false);
    ui->btn_set->setChecked(false);
    ui->stackedWidget->hide();

    m_link->sendSerialData(proto->resetAllAxes());
}

//******************************axis轴状态按键******************************
void Widget::on_btn_axis_clicked()
{
    const int target_index = 0;

    if (ui->stackedWidget->isVisible() && ui->stackedWidget_2->currentIndex() == target_index)
    {
        ui->btn_axis->setChecked(false);
        ui->stackedWidget_2->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(false);
        ui->stackedWidget_2->setCurrentIndex(target_index);
        ui->stackedWidget_2->show();
    }

}

//******************************dio按键******************************
void Widget::on_btn_dio_clicked()
{
    const int target_index = 1;

    if (ui->btn_axis->isChecked() && ui->stackedWidget_2->currentIndex() == target_index)
    {
        ui->btn_dio->setChecked(false);
        ui->stackedWidget_2->hide();
    }
    else
    {
        ui->btn_link->setChecked(false);
        ui->btn_ECAT->setChecked(false);
        ui->btn_set->setChecked(false);
        ui->stackedWidget_2->setCurrentIndex(target_index);
        ui->stackedWidget_2->show();
    }

}
//**********************************************Link界面**********************************************//
void Widget::updateSerialPortButtons()
{
    // 更新两个按钮的状态
    ui->btn_open_port->setChecked(m_serialPortOpen);
    ui->btn_open_port_2->setChecked(m_serialPortOpen);

    // 更新按钮文本
    QString buttonText = m_serialPortOpen ? "关闭串口" : "打开串口";
    ui->btn_open_port->setText(buttonText);
    ui->btn_open_port_2->setText(buttonText);

    // 更新下拉框状态
    ui->comboBox_baud_rate->setEnabled(!m_serialPortOpen);
    ui->comboBox_device_port->setEnabled(!m_serialPortOpen);
}

// 打开串口
void Widget::openSerialPort()
{
    if (m_serialPortOpen) {
        return; // 已经打开，无需重复操作
    }

    m_link->setSerialPortName(ui->comboBox_device_port->currentText());
    m_link->setBaudRate(ui->comboBox_baud_rate->currentText().toInt());

    m_link->openSerialPorts();

}

// 关闭串口
void Widget::closeSerialPort()
{
    if (!m_serialPortOpen) {
        return; // 已经关闭，无需重复操作
    }
    m_link->closeSerialPort();

}


//**********************************************日志信息界面**********************************************//

//******************************清空日志按键******************************
void Widget::on_btn_clear_log_clicked()
{
    ui->textEdit_log_info->clear();
}

//******************************导出日志按键******************************
void Widget::on_btn_save_log_clicked()
{
    QString logmessage = ui->textEdit_log_info->toPlainText();
    if (logmessage.isEmpty())
    {
        QMessageBox::information(this, "提示", "日志为空");
        return;
    }


    QString defaultFilename = QString("ECATlog_%1.txt").arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));

    QString filePath = QFileDialog::getSaveFileName(this, "选择日志保存路径", defaultFilename, "文本文件 (*.txt);;所有文件 (*.*)");

    if (filePath.isEmpty()) 
    {
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
    {
        QMessageBox::critical(this, "导出失败", QString("文件无法打开！\n原因：%1\n路径：%2")
            .arg(file.errorString())
            .arg(filePath)
        );
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8); // 设置编码为UTF-8
    out << logmessage;     // 写入纯文本日志

    file.close();
    QMessageBox::information(this, "导出成功", QString("日志已保存到：\n%1").arg(filePath));

}

//******************************写入日志函数******************************
void Widget::appendlog(const QString& msg)
{
    // 自动生成时间戳
    QString timeStamp = QDateTime::currentDateTime().toString("hh:mm:ss.zzz");
    QString logText;

    logText = QString("[%1]  %3").arg(timeStamp, msg);

    // 输出到UI日志框
    ui->textEdit_log_info->append(logText);
}

//******************************向下位机发送数据函数******************************
void Widget::serialReadData(const QByteArray &data)
{
    static QByteArray rxBuf;
    rxBuf.append(data);

    auto u8 = [](char c) -> quint8
    {
        return static_cast<quint8>(c);
    };

    auto readU16 = [&](const QByteArray &buf, int off) -> quint16
    {
        return (quint16)u8(buf[off]) | ((quint16)u8(buf[off + 1]) << 8);
    };

    auto readI16 = [&](const QByteArray &buf, int off) -> qint16
    {
        return static_cast<qint16>(readU16(buf, off));
    };

    auto readU32 = [&](const QByteArray& buf, int off) -> quint32 {
        return  (quint32)u8(buf[off])
            | ((quint32)u8(buf[off + 1]) << 8)
            | ((quint32)u8(buf[off + 2]) << 16)
            | ((quint32)u8(buf[off + 3]) << 24);
        };

    auto readI32 = [&](const QByteArray &buf, int off) -> qint32
    {
        return static_cast<qint32>(readU32(buf, off));
    };

    auto ethercatStateToString = [](quint16 st) -> QString {
        if (st & 0x08) return QString("OP (0x%1)").arg(st, 4, 16, QChar('0')).toUpper();
        if (st & 0x04) return QString("SAFE-OP (0x%1)").arg(st, 4, 16, QChar('0')).toUpper();
        if (st & 0x02) return QString("PRE-OP (0x%1)").arg(st, 4, 16, QChar('0')).toUpper();
        if (st & 0x01) return QString("INIT (0x%1)").arg(st, 4, 16, QChar('0')).toUpper();
        return QString("UNKNOWN (0x%1)").arg(st, 4, 16, QChar('0')).toUpper();
        };
    while (rxBuf.size() >= 7)
    {
        // 1 找帧头
        if (u8(rxBuf[0]) != FRAME_HEADER)
        {
            rxBuf.remove(0, 1);
            continue;
        }

        // 2 取长度
        quint8 len = u8(rxBuf[5]);
        int frameLen = 7 + len;   // 头6字节 + 数据len + CRC1字节

        if (rxBuf.size() < frameLen)
            break; // 半包，等下次

        // 3 CRC校验
        quint8 crc = 0;
        for (int i = 0; i < frameLen - 1; ++i)
            crc ^= u8(rxBuf[i]);

        if (crc != u8(rxBuf[frameLen - 1]))
        {
            rxBuf.remove(0, 1);
            continue;
        }

        quint8 type = u8(rxBuf[1]);
        quint8 cmd = u8(rxBuf[2]);
        quint8 axis = u8(rxBuf[3]);
        Q_UNUSED(axis);
        QByteArray payload = rxBuf.mid(6, len);

        // ====================== 周期监视上传帧 ======================
        if (type == FRAME_TYPE_DATA && cmd == CMD_UPLOAD_MONITOR &&
            (payload.size() == 30 || payload.size() == 32))
        {
            qint32 actpos = readI32(payload, 0);
            qint32 cmdpos = readI32(payload, 4);
            qint32 errorpos = readI32(payload, 8);
            qint16 state = readI16(payload, 12);
            quint16 stateword = readU16(payload, 14);
            qint32 targetpos = readI32(payload, 16);
            qint32 dc = readI32(payload, 20);
            quint32 freq = readU32(payload, 24);
            quint16 slavestate = readU16(payload, 28);

            ui->lineEdit_actpos->setText(QString::number(actpos));
            ui->lineEdit_cmdpos->setText(QString::number(cmdpos));
            ui->lineEdit_errorpos->setText(QString::number(errorpos));
            ui->lineEdit_state->setText(QString::number(state));
            ui->lineEdit_stateword->setText(
                QString("0x%1").arg(stateword, 4, 16, QChar('0')).toUpper());
            ui->lineEdit_targetpos->setText(QString::number(targetpos));

            ui->textEdit_dc->setPlainText(QString::number(dc));
            ui->textEdit_freq->setPlainText(QString("%1 ").arg(freq));
            ui->textEdit_slavestate->setPlainText(ethercatStateToString(slavestate));
        }
        // ====================== 普通应答/错误帧，可选记录日志 ======================
        else if (type == FRAME_TYPE_ACK)
        {

            switch (cmd)
            {
            case 0x81:
                    appendlog(QString("轴%1使能成功").arg(axis));
                    ui->checkBox_axis0enable->setChecked(true);
                break;

            case 0x82:
                    appendlog(QString("轴%1失能成功").arg(axis));
                    ui->checkBox_axis0enable->setChecked(false);
                break;

            case 0x83: // 停止成功
                appendlog(QString("轴%1停止成功").arg(axis));
                break;

            case 0x84: // 重置成功
                appendlog(QString("轴%1重置成功").arg(axis));
                break;

            case 0x85: // 回零成功
                appendlog(QString("轴%1回零成功").arg(axis));
                break;

            case 0x86: // 点动正转成功
                appendlog(QString("轴%1点动正转成功").arg(axis));
                break;

            case 0x87: // 点动反转成功
                appendlog(QString("轴%1点动反转成功").arg(axis));
                break;

            case 0x88: // 停止点动成功
                appendlog(QString("轴%1停止点动成功").arg(axis));
                break;

            case 0x90: // 绝对运动成功
                appendlog(QString("轴%1绝对运动成功").arg(axis));
                break;

            case 0x91: // 相对运动成功
                appendlog(QString("轴%1相对运动成功").arg(axis));
                break;

            case 0x92: // 相对运动成功
                appendlog(QString("轴%1角度运动成功").arg(axis));
                break;

            case 0xA0: // 速度设置成功
                appendlog(QString("轴%1速度设置成功").arg(axis));
                break;

            case 0xA1: // 加速度设置成功
                appendlog(QString("轴%1加速度设置成功").arg(axis));
                break;

            case 0xA2: // 减速度设置成功
                appendlog(QString("轴%1减速度设置成功").arg(axis));
                break;

            case 0xB0: // 位置读取成功
            {
                if (payload.size() >= 4)
                {
                    qint32 pos = readI32(payload, 0);
                    appendlog(QString("轴%1位置: %2").arg(axis).arg(pos));
                }
            }
            break;

            case 0xB1: // 速度读取成功
            {
                if (payload.size() >= 4)
                {
                    qint32 vel = readI32(payload, 0);
                    appendlog(QString("轴%1速度: %2").arg(axis).arg(vel));
                }
            }
            break;

            case 0xB2: // 状态读取成功
            {
                if (payload.size() >= 2)
                {
                    quint16 status = readU16(payload, 0);
                    appendlog(QString("轴%1状态字: 0x%2").arg(axis).arg(status, 4, 16, QChar('0')).toUpper());
                }
            }
            break;

            case 0xC0: // SDO写8位成功
                appendlog(QString("轴%1 SDO写8位成功").arg(axis));
                break;

            case 0xC1: // SDO写16位成功
                appendlog(QString("轴%1 SDO写16位成功").arg(axis));
                break;

            case 0xC2: // SDO写32位成功
                appendlog(QString("轴%1 SDO写32位成功").arg(axis));
                break;

            case 0xC3: // SDO读8位成功
            {
                if (payload.size() >= 1)
                {
                    quint8 value = u8(payload[0]);
                    appendlog(QString("轴%1 SDO读8位: 0x%2").arg(axis).arg(value, 2, 16, QChar('0')).toUpper());
                }
            }
            break;

            case 0xC4: // SDO读16位成功
            {
                if (payload.size() >= 2)
                {
                    quint16 value = readU16(payload, 0);
                    appendlog(QString("轴%1 SDO读16位: 0x%2").arg(axis).arg(value, 4, 16, QChar('0')).toUpper());
                }
            }
            break;

            case 0xC5: // SDO读32位成功
            {
                if (payload.size() >= 4)
                {
                    quint32 value = readU32(payload, 0);
                    appendlog(QString("轴%1 SDO读32位: 0x%2").arg(axis).arg(value, 8, 16, QChar('0')).toUpper());
                }
            }
            break;

            default:
                appendlog(QString("收到ACK: cmd=0x%1 axis=%2").arg(cmd, 2, 16, QChar('0')).toUpper().arg(axis));
                break;
            }
        }
        else if (type == FRAME_TYPE_ERR)
        {
            if (payload.size() >= 1)
            {
                quint8 err = u8(payload[0]);
                appendlog(QString("错误应答: cmd=0x%1 err=0x%2").arg(cmd, 2, 16, QChar('0')).arg(err, 2, 16, QChar('0')).toUpper());
            }
        }

        rxBuf.remove(0, frameLen);
    }
}

//**********************************************主界面轴运动设置界面**********************************************//

//******************************轴使能失能切换按键******************************
void Widget::on_checkBox_axis0enable_stateChanged(int arg1)
{
    // 根据复选框状态发送不同指令
    if (arg1 == Qt::Checked)
    {
        m_link->sendSerialData(proto->enableAxis(0));
        ui->btn_jognegative->setEnabled(true);
        ui->btn_jogpositive->setEnabled(true);
        ui->comboBox_mode_chose->setEnabled(true);
        ui->btn_run->setEnabled(true);
        ui->btn_stop->setEnabled(true);
    }
    else
    {
        m_link->sendSerialData(proto->disableAxis(0));
        ui->btn_jognegative->setEnabled(false);
        ui->btn_jogpositive->setEnabled(false);
        ui->comboBox_mode_chose->setEnabled(false);
        ui->btn_run->setEnabled(false);
        ui->btn_stop->setEnabled(false);
    }
}

//******************************JOG负方向运动******************************
void Widget::on_btn_jognegative_pressed()
{
    this->appendlog("JOG负方向运动开始...");
    m_link->sendSerialData(proto->jogbackward(0));
}

void Widget::on_btn_jognegative_released()
{
    this->appendlog("JOG停止");
    m_link->sendSerialData(proto->jogstop(0));
}


//******************************JOG正方向******************************
void Widget::on_btn_jogpositive_pressed()
{
    this->appendlog("JOG正方向运动开始...");
    m_link->sendSerialData(proto->jogforward(0));
}

void Widget::on_btn_jogpositive_released()
{
    this->appendlog("JOG停止");
    m_link->sendSerialData(proto->jogstop(0));
}

//******************************清除错误按键******************************
void Widget::on_btn_clear_alarm_clicked()
{
    this->appendlog("清除从站错误");
    m_link->sendSerialData(proto->clear_error(0));
}

//******************************执行运动按键******************************
void Widget::on_btn_run_clicked()
{
    if (!ui->checkBox_axis0enable->isChecked())
    {
        QMessageBox::warning(this, "操作错误", "轴未使能！请先勾选【enable】使能轴后再执行运动！");
        return;
    }

    // 运动模式设置
    bool mode_ok;
    int mode = ui->comboBox_mode_chose->currentData().toInt(&mode_ok);
    if (!mode_ok)
    {
        QMessageBox::warning(this, "操作错误", "运动模式选择异常！");
        return;
    }

    // 运动数据设置
    bool value_ok;
    qint32 motion_value = 0;
    if (mode != 3)
    {
        motion_value = ui->lineEdit_motion_value->text().toInt(&value_ok);
        if (!value_ok)
        {
            QMessageBox::warning(this, "输入错误", "运动数值无效！请输入合法数据！");
            return;
        }
    }

    const uint8_t axis = 0;        // 当前轴号：Axis0
    const uint16_t slaveIndex = 1; // EtherCAT从站索引

    switch (mode)
    {
    case 0: // 绝对运动
    {
        m_link->sendSerialData(proto->moveabs(0, motion_value));
        this->appendlog(QString("执行绝对运动：ABS:%1").arg(motion_value));
        break;
    }
    case 1: // 相对运动
    {
        m_link->sendSerialData(proto->moverel(0, motion_value));
        this->appendlog(QString("执行相对运动：REL:%1").arg(motion_value));
        break;
    }
    case 2: // movedeg运动
    {
        m_link->sendSerialData(proto->movedeg(0, motion_value));
        this->appendlog(QString("执行角度运动：DEG:%1 °").arg(motion_value));
        break;
    }
    case 3: // 回零运动
    {
        int8_t home_mode = static_cast<int8_t>(ui->comboBox_home_mode->currentData().toInt(&mode_ok));
        if (!mode_ok)
        {
            QMessageBox::warning(this, "错误", "回零模式选择异常");
            return;
        }
        m_link->sendSerialData(proto->homeAxis(0, home_mode));
        this->appendlog(QString("执行回零运动：mode:%1").arg(home_mode));
        break;
    }

    default:
    {
        QMessageBox::warning(this, "操作错误", "未知运动模式！");
        return;
    }
    }
}

//******************************停止运动按键******************************
void Widget::on_btn_stop_clicked()
{
    this->appendlog("停止运动");
    m_link->sendSerialData(proto->stopAxis(0));
}

//******************************设置参数按键******************************
void Widget::on_btn_set_2_clicked()
{
    const int target_index = 1;

    if (ui->stackedWidget->isVisible() && ui->stackedWidget->currentIndex() == target_index)
    {
        ui->stackedWidget->hide();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(target_index);
        ui->stackedWidget->show();
    }
}


//**********************************************设置SET界面**********************************************//

//******************************选择模式按键******************************
void Widget::on_btn_setmode_clicked()
{
    int8_t seromode = static_cast<int8_t>(ui->comboBox_mode->currentData().toInt());
    this->appendlog(QString("选择模式：%1").arg(ui->comboBox_mode->currentText()));
    if (seromode < 0 || seromode > 10) // 宏定义模式范围：0~10
    {
        qWarning() << "[ERROR] Invalid mode value:" << seromode;
        seromode = op_mode_no; // 重置为无模式
    }
    m_link->sendSerialData(proto->writeSDO8(1, 0x6060, 0x00, seromode));
}

//******************************设置速度参数按键******************************
void Widget::on_btn_setpara_clicked()
{
    bool convert_ok;
    const uint8_t axis = 0; // 轴号，对应协议函数的轴参数
    const uint16_t slaveIndex = axis + 1;


    int32_t vel = ui->lineEdit_vel->text().toInt(&convert_ok);
    if (!convert_ok || vel <= 0 || vel >= 41835040)//41835040 = 40r/s
    {
        QMessageBox::warning(this, "输入错误", "速度无效！请输入有效的正整数");
        return;
    }

    int32_t dec = ui->lineEdit_dec->text().toInt(&convert_ok);
    if (!convert_ok || dec <= 0 || dec >= 418350400)//41835040 = 40r/s
    {
        QMessageBox::warning(this, "输入错误", "减速度无效！请输入有效的正整数");
        return;
    }

    int32_t acc = ui->lineEdit_acc->text().toInt(&convert_ok);
    if (!convert_ok || acc <= 0 || acc >= 418350400)//41835040 = 40r/s
    {
        QMessageBox::warning(this, "输入错误", "加速度无效！请输入有效的正整数");
        return;
    }

    bool ret = set_motion_para(slaveIndex, vel, acc, dec);
    if (ret)
    {
        QMessageBox::information(this, "操作成功", "运动参数已成功写入伺服！");
    }
}

//******************************设置回零参数按键******************************
void Widget::on_btn_set_homepara_clicked()
{
    bool convert_ok;
    const uint8_t axis = 0; // 轴号，对应协议函数的轴参数
    const uint16_t slaveIndex = axis + 1;

    int8_t home_mode = static_cast<int8_t>(ui->comboBox_home_mode->currentData().toInt(&convert_ok));
    if (!convert_ok)
    {
        QMessageBox::warning(this, "错误", "回零模式选择异常");
        return;
    }

    int32_t sw_vel = ui->lineEdit_sw_vel->text().toInt(&convert_ok);
    if (!convert_ok || sw_vel <= 0 || sw_vel >= 1058760)
    {
        QMessageBox::warning(this, "输入错误", "回零搜索速度无效！请输入0~1058760之间的正整数");
        return;
    }

    int32_t zero_vel = ui->lineEdit_zero_vel->text().toInt(&convert_ok);
    if (!convert_ok || zero_vel <= 0 || zero_vel >= 500000)
    {
        QMessageBox::warning(this, "输入错误", "回零精确定位速度无效！请输入0~500000之间的正整数");
        return;
    }

    bool ret = set_home_para(slaveIndex, home_mode, sw_vel, zero_vel);
    if (ret)
    {
        QMessageBox::information(this, "操作成功", "已切换回零模式，回零运动参数已成功写入伺服！");
    }
}



//**********************************************ECAT界面**********************************************//

//******************************读取从站信息按键******************************
void Widget::on_btn_read_slaveinfo_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("从站号选择异常");
        this->appendlog("从站号选择异常");
        return;
    }

    this->appendlog(QString("读取从站 %1 信息").arg(slave));
    m_link->sendSerialData(proto->read_slaveinfo(slave));
}

//******************************清除ECAT错误按键******************************
void Widget::on_btn_clear_ECATerror_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("从站号选择异常");
        this->appendlog("从站号选择异常");
        return;
    }

    this->appendlog(QString("清除从站 %1 错误").arg(slave));
    m_link->sendSerialData(proto->clear_error(slave));
}

//******************************切换至safeop按键******************************
void Widget::on_btn_to_safeop_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("从站号选择异常");
        this->appendlog("从站号选择异常");
        return;
    }
    this->appendlog(QString("切换从站 %1 至safeop").arg(slave));
    m_link->sendSerialData(proto->switch_safeop(slave));
}

//******************************切换至op按键******************************
void Widget::on_btn_to_op_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("从站号选择异常");
        this->appendlog("从站号选择异常");
        return;
    }

    this->appendlog(QString("切换从站 %1 至op").arg(slave));
    m_link->sendSerialData(proto->switch_op(slave));
}

//******************************读取sdo按键******************************
void Widget::on_btn_read_sdo_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("从站号选择异常");
        this->appendlog("从站号选择异常");
        return;
    }

    int byteSize = ui->comboBox_data_type->currentData().toInt(&ok);
    if (!ok) 
    {
        ui->textEdit_SDO_log->append("数据类型读取异常");
        this->appendlog("数据类型读取异常");
        return;
    }

    uint16_t index = ui->textEdit_sdo_index->toPlainText().toUInt(&ok, 16);
    if (!ok) 
    {
        ui->textEdit_SDO_log->append("[错误] SDO索引格式错误（示例：6060）");
        this->appendlog("[错误] SDO索引格式错误（示例：6060）");
        return;
    }

    uint8_t subindex = ui->textEdit_sdo_subindex->toPlainText().toUInt(&ok, 16);
    if (!ok) 
    {
        ui->textEdit_SDO_log->append("[错误] 子索引格式错误（示例：00）");
        this->appendlog("[错误] 子索引格式错误（示例：00）");
        return;
    }

    switch (byteSize)
    {
    case 1:
        m_link->sendSerialData(proto->readSDO8(slave, index, subindex));
        this->appendlog(QString("读取 SDO8 (0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + ")"));
        break;
    case 2:
        m_link->sendSerialData(proto->readSDO16(slave, index, subindex));
        this->appendlog(QString("读取 SDO16 (0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + ")"));
        break;
    case 4:
        m_link->sendSerialData(proto->readSDO32(slave, index, subindex));
        this->appendlog(QString("读取 SDO32 (0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + ")"));
        break;
    default:
        ui->textEdit_SDO_log->append("数据类型读取异常");
        this->appendlog("数据类型读取异常");
        return;
    }
}

//******************************写入sdo按键******************************
void Widget::on_btn_write_sdo_clicked()
{
    bool ok;
    uint16_t slave = ui->comboBox_slave_num->currentData().toInt(&ok);
    if (!ok) 
    {
        this->appendlog("从站号异常");
        ui->textEdit_SDO_log->append("从站号异常");
        return;
    }

    int byteSize = ui->comboBox_data_type->currentData().toInt(&ok);
    if (!ok) 
    {
        ui->textEdit_SDO_log->append("数据类型异常");
        this->appendlog("数据类型异常");
        return;
    }

    uint16_t index = ui->textEdit_sdo_index->toPlainText().toUInt(&ok, 16);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("[错误] SDO索引格式错误（示例：6060）");
        this->appendlog("[错误] SDO索引格式错误（示例：6060）");
        return;
    }

    uint8_t subindex = ui->textEdit_sdo_subindex->toPlainText().toUInt(&ok, 16);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("[错误] SDO子索引格式错误（示例：00）");
        this->appendlog("[错误] SDO子索引格式错误（示例：00）");
        return;
    }

    uint32_t value = ui->textEdit_sdo_value->toPlainText().toUInt(&ok);
    if (!ok)
    {
        ui->textEdit_SDO_log->append("[错误] SDO数值错误");
        this->appendlog("[错误] SDO数值错误,请输入整数");
        return;
    }

    switch (byteSize)
    {
    case 1:
        m_link->sendSerialData(proto->writeSDO8(slave, index, subindex, (uint8_t)value));
        this->appendlog("写入SDO8 ：0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + "  value : " + QString::number(value));
        break;
    case 2:
        m_link->sendSerialData(proto->writeSDO16(slave, index, subindex, (uint16_t)value));
        this->appendlog("写入SDO16 ：0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + "  value : " + QString::number(value));
        break;
    case 4:
        m_link->sendSerialData(proto->writeSDO32(slave, index, subindex, value));
        this->appendlog("写入SDO32 ：0x" + QString::number(index, 16).toUpper() + ":" + QString::number(subindex, 16).toUpper() + "  value : " + QString::number(value));
        break;
    }
}


//**********************************************功能辅助函数**********************************************//

//******************************设置运动参数******************************
bool Widget::set_motion_para(uint16_t slaveIndex, int32_t vel, int32_t acc, int32_t dec)
{
    // 参数合法性校验
    if (vel <= 0 || vel >= 41835040) // 41835040 = 40r/s
    {
        QMessageBox::warning(this, "输入错误", "速度无效！请输入有效的正整数");
        return false;
    }
    if (dec <= 0 || dec >= 418350400)
    {
        QMessageBox::warning(this, "输入错误", "减速度无效！请输入有效的正整数");
        return false;
    }
    if (acc <= 0 || acc >= 418350400)
    {
        QMessageBox::warning(this, "输入错误", "加速度无效！请输入有效的正整数");
        return false;
    }

    // 发送SDO设置运动参数
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6081, 0x00, static_cast<uint32_t>(vel)));
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6083, 0x00, static_cast<uint32_t>(acc)));
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6084, 0x00, static_cast<uint32_t>(dec)));

    // 日志记录
    this->appendlog(QString("速度: %1   加速度: %2   减速度: %3 ").arg(vel).arg(acc).arg(dec));

    return true;
}

//******************************设置回零参数******************************
bool Widget::set_home_para(uint16_t slaveIndex, int8_t home_mode, int32_t sw_vel, int32_t zero_vel)
{
    // 参数合法性校验
    if (sw_vel <= 0 || sw_vel >= 1058760)
    {
        QMessageBox::warning(this, "输入错误", "回零搜索速度无效！请输入0~1058760之间的正整数");
        return false;
    }
    if (zero_vel <= 0 || zero_vel >= 500000)
    {
        QMessageBox::warning(this, "输入错误", "回零精确定位速度无效！请输入0~500000之间的正整数");
        return false;
    }

    //发送SDO设置回零参数
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6098, 0x00, static_cast<uint32_t>(home_mode)));
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6099, 0x01, static_cast<uint32_t>(sw_vel)));
    m_link->sendSerialData(proto->writeSDO32(slaveIndex, 0x6099, 0x02, static_cast<uint32_t>(zero_vel)));

    // 日志记录
    this->appendlog(QString("模式: %1   回零搜索速度（sw_vel）: %2   回零精确定位速度(zero_vel): %3 ").arg(home_mode).arg(sw_vel).arg(zero_vel));

    return true;
}


//****************************************************XML****************************************************
void Widget::on_btn_read_XMLfile_clicked()
{
    const QString defaultPath =
        m_xml->xmlFilePath().isEmpty() ? QDir::currentPath() : QFileInfo(m_xml->xmlFilePath()).absolutePath();

    const QString filePath = QFileDialog::getOpenFileName(
        this,
        "选择 EtherCAT XML 文件",
        defaultPath,
        "EtherCAT XML (*.xml);;所有文件 (*.*)");

    if (filePath.isEmpty())
    {
        return;
    }

    QString errorMessage;
    if (!m_xml->loadXmlDescription(filePath, errorMessage))
    {
        appendlog(QString("[XML] %1").arg(errorMessage));
        appendlog(errorMessage);
        QMessageBox::warning(this, "XML导入失败", errorMessage);
        return;
    }

    appendlog("========== XML 摘要 ==========");
    for (const QString& line : m_xml->xmlSummaryLines())
    {
        appendlog(line);
    }

    appendlog("========== RxPDO ==========");
    for (const QString& line : m_xml->xmlRxPdoLines())
    {
        appendlog(line);
    }

    appendlog("========== TxPDO ==========");
    for (const QString& line : m_xml->xmlTxPdoLines())
    {
        appendlog(line);
    }

    appendlog(QString("已导入 XML 文件: %1").arg(filePath));
    QMessageBox::information(this, "XML导入成功", QString("已成功导入并解析:\n%1").arg(filePath));
}


void Widget::on_btn_clear_XMLfile_clicked()
{
    m_xml->clearXMLData();
    appendlog("[XML] 已清除当前导入的 XML 缓存与从站提示信息");
    appendlog("已清除 XML 文件缓存");
}



