#ifndef WIDGET_H
#define WIDGET_H

#include <QHash>
#include <QWidget>
#include <QString>
#include <QVector>
#include <QSerialPort>
#include <QSerialPortInfo>


QT_BEGIN_NAMESPACE

class Link;
class Protocol;
class XML;

#define op_mode_no   0            // 无模式
#define op_mode_pp   1            // Profile Position（位置规划）
#define op_mode_vl   2            // Profile Velocity（速度规划）	
#define op_mode_pv   3            // Profile Torque（扭矩规划）
#define op_mode_hm   6            // Homing（原点复归）
#define op_mode_ip   7            // IP（插值位置）
#define op_mode_csp  8            // Cyclic Synchronous Position（周期同步位置）
#define op_mode_csv  9            // Cyclic Synchronous Velocity（周期同步速度）
#define op_mode_cst  10           // Cyclic Synchronous Torque（周期同步扭矩）

namespace Ui
{
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    //**********************************************左侧按键界面函数**********************************************//
    void on_btn_link_clicked();
    void on_btn_ECAT_clicked();
    void on_btn_set_clicked();
    void on_btn_enable_clicked();
    void on_btn_disable_clicked();
    void on_btn_reboot_clicked();
    void on_btn_axis_clicked();
    void on_btn_dio_clicked();


    //**********************************************日志信息界面函数**********************************************//
    void on_btn_clear_log_clicked();
    void serialReadData(const QByteArray& data);      // 串口接收数据
    void on_btn_save_log_clicked();

    //**********************************************主界面轴运动函数**********************************************//
    void on_checkBox_axis0enable_stateChanged(int arg1);
    void on_btn_jognegative_pressed();
    void on_btn_jognegative_released();
    void on_btn_jogpositive_pressed();
    void on_btn_jogpositive_released();
    void on_btn_set_2_clicked();
    void on_btn_run_clicked();
    void on_btn_stop_clicked();

    //**********************************************SET界面函数**********************************************//
    void on_btn_setmode_clicked();
    void on_btn_setpara_clicked();
    void on_btn_set_homepara_clicked();


    //**********************************************ECAT监视界面函数**********************************************//
    void on_btn_read_slaveinfo_clicked();
    void on_btn_clear_ECATerror_clicked();
    void on_btn_to_safeop_clicked();
    void on_btn_to_op_clicked();
    void on_btn_read_sdo_clicked();
    void on_btn_write_sdo_clicked();


    //**********************************************axis界面函数**********************************************//
    void on_btn_clear_alarm_clicked();

    //**********************************************XML函数**********************************************//
    void on_btn_read_XMLfile_clicked();

    void on_btn_clear_XMLfile_clicked();

    void on_btn_scope_clicked();

    void on_btn_RunTime_clicked();

private:
    Ui::Widget* ui;
    Link* m_link;
    Protocol* proto;
    XML* m_xml;

    int8_t home_mode;
    int32_t vel,acc,dec, sw_vel, zero_vel;
    bool m_serialPortOpen = false;

    void appendlog(const QString& msg);
    void updateSerialPortButtons();
    void openSerialPort();
    void closeSerialPort();
    bool set_motion_para(uint16_t slaveIndex, int32_t vel, int32_t acc, int32_t dec);
    bool set_home_para(uint16_t slaveIndex, int8_t home_mode, int32_t sw_vel, int32_t zero_vel);

};



#endif // WIDGET_H



