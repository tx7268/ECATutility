/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit_log_info;
    QPushButton *btn_link;
    QPushButton *btn_enable;
    QPushButton *btn_disable;
    QPushButton *btn_reboot;
    QPushButton *btn_axis;
    QPushButton *btn_dio;
    QLabel *label;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QCheckBox *checkBox_axis0enable;
    QPushButton *btn_jognegative;
    QPushButton *btn_jogpositive;
    QComboBox *comboBox_mode_chose;
    QLineEdit *lineEdit_motion_value;
    QPushButton *btn_run;
    QPushButton *btn_stop;
    QPushButton *btn_set_2;
    QPushButton *btn_ECAT;
    QPushButton *btn_set;
    QPushButton *btn_save_log;
    QPushButton *btn_clear_log;
    QStackedWidget *stackedWidget;
    QWidget *page_Link;
    QGroupBox *groupBox_3;
    QLabel *label_device_name;
    QLabel *label_device_port;
    QLabel *label_slave_numbers;
    QTextEdit *textEdit_device_name;
    QTextEdit *textEdit_slave_numbers;
    QComboBox *comboBox_device_port;
    QLabel *label_baud_rate;
    QComboBox *comboBox_baud_rate;
    QPushButton *btn_open_port;
    QPushButton *btn_refresh_port;
    QLabel *label_linkset;
    QPushButton *btn_link_device;
    QPushButton *btn_unlink;
    QPushButton *btn_rescan;
    QWidget *page_Set;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_vel;
    QLineEdit *lineEdit_acc;
    QLabel *label_16;
    QLineEdit *lineEdit_dec;
    QLabel *label_18;
    QLabel *label_17;
    QLineEdit *lineEdit_zero_vel;
    QLineEdit *lineEdit_sw_vel;
    QLabel *label_19;
    QLabel *label_20;
    QComboBox *comboBox_home_mode;
    QPushButton *btn_setpara;
    QComboBox *comboBox_mode;
    QLabel *label_33;
    QPushButton *btn_setmode;
    QPushButton *btn_set_homepara;
    QWidget *page_ECAT;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *textEdit_cycle;
    QTextEdit *textEdit_freq;
    QTextEdit *textEdit_slavestate;
    QTextEdit *textEdit_dc;
    QGroupBox *groupBox_5;
    QPushButton *btn_read_slaveinfo;
    QPushButton *btn_clear_slave_error;
    QPushButton *btn_to_op;
    QPushButton *btn_to_safeop;
    QPushButton *btn_read_XMLfile;
    QPushButton *btn_clear_XMLfile;
    QGroupBox *groupBox_6;
    QTextEdit *textEdit_sdo_index;
    QLabel *label_8;
    QTextEdit *textEdit_sdo_subindex;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QComboBox *comboBox_data_type;
    QComboBox *comboBox_slave_num;
    QTextEdit *textEdit_sdo_value;
    QLabel *label_13;
    QPushButton *btn_read_sdo;
    QPushButton *btn_write_sdo;
    QTextEdit *textEdit_SDO_log;
    QWidget *page_Scope;
    QTabWidget *tabWidget;
    QWidget *x_t;
    QChartView *chartView;
    QWidget *x_v;
    QWidget *ECAT;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_actpos;
    QCheckBox *checkBox_targetpos;
    QCheckBox *checkBox_vel;
    QCheckBox *checkBox_acc;
    QFrame *line;
    QLabel *label_54;
    QComboBox *comboBox_axischose;
    QPushButton *btn_begin_scope;
    QPushButton *btn_stop_scope;
    QPushButton *btn_clear_scope;
    QPushButton *btn_out_scope;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_57;
    QLabel *label_55;
    QComboBox *comboBox_posall;
    QComboBox *comboBox_trigger;
    QComboBox *comboBox_timebase;
    QLabel *label_56;
    QLabel *label_58;
    QComboBox *comboBox_timeall;
    QWidget *page_RunTime;
    QGroupBox *groupBox_13;
    QLabel *label_59;
    QLineEdit *lineEdit_current_delay;
    QGroupBox *groupBox_14;
    QLabel *label_63;
    QGroupBox *groupBox_15;
    QLabel *label_64;
    QGroupBox *groupBox_16;
    QLabel *label_65;
    QGroupBox *groupBox_17;
    QLabel *label_70;
    QGroupBox *groupBox_18;
    QLabel *label_71;
    QGroupBox *groupBox_19;
    QLabel *label_72;
    QGroupBox *groupBox_20;
    QLabel *label_73;
    QLineEdit *lineEdit_average_delay;
    QLineEdit *lineEdit_loss_rate;
    QLineEdit *lineEdit_jitter;
    QLineEdit *lineEdit_min_delay;
    QLineEdit *lineEdit_error_packet;
    QLineEdit *lineEdit_exchange_fre;
    QLineEdit *lineEdit_max_delay;
    QStackedWidget *stackedWidget_2;
    QWidget *page_axis;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_21;
    QLabel *label_12;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_23;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *btn_clear_alarm;
    QLineEdit *lineEdit_errorpos;
    QLineEdit *lineEdit_targetpos;
    QLineEdit *lineEdit_actpos;
    QLineEdit *lineEdit_cmdpos;
    QLineEdit *lineEdit_stateword;
    QLineEdit *lineEdit_state;
    QWidget *page_dio;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QPushButton *btn_do1_1;
    QPushButton *btn_do0_1;
    QPushButton *btn_do1_7;
    QPushButton *btn_do1_6;
    QPushButton *btn_do0_5;
    QPushButton *btn_do2_5;
    QPushButton *btn_do0_0;
    QPushButton *btn_do0_6;
    QPushButton *btn_do2_1;
    QPushButton *btn_do0_4;
    QPushButton *btn_do2_4;
    QPushButton *btn_do2_6;
    QPushButton *btn_do2_7;
    QPushButton *btn_do2_0;
    QPushButton *btn_do1_0;
    QPushButton *btn_do1_2;
    QPushButton *btn_do0_3;
    QPushButton *btn_do1_4;
    QPushButton *btn_do2_3;
    QPushButton *btn_do2_2;
    QPushButton *btn_do0_2;
    QPushButton *btn_do0_7;
    QPushButton *btn_do1_3;
    QPushButton *btn_do1_5;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_58;
    QPushButton *pushButton_62;
    QPushButton *pushButton_51;
    QPushButton *pushButton_68;
    QPushButton *pushButton_53;
    QPushButton *pushButton_60;
    QPushButton *pushButton_72;
    QPushButton *pushButton_54;
    QPushButton *pushButton_50;
    QPushButton *pushButton_64;
    QPushButton *pushButton_71;
    QPushButton *pushButton_57;
    QPushButton *pushButton_67;
    QPushButton *pushButton_56;
    QPushButton *pushButton_70;
    QPushButton *pushButton_55;
    QPushButton *pushButton_49;
    QPushButton *pushButton_52;
    QPushButton *pushButton_59;
    QPushButton *pushButton_63;
    QPushButton *pushButton_61;
    QPushButton *pushButton_65;
    QPushButton *pushButton_69;
    QPushButton *pushButton_66;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_39;
    QLabel *label_41;
    QLabel *label_40;
    QPushButton *btn_open_port_2;
    QPushButton *btn_scope;
    QPushButton *btn_RunTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1500, 950);
        textEdit_log_info = new QTextEdit(Widget);
        textEdit_log_info->setObjectName("textEdit_log_info");
        textEdit_log_info->setGeometry(QRect(1010, 50, 471, 651));
        btn_link = new QPushButton(Widget);
        btn_link->setObjectName("btn_link");
        btn_link->setGeometry(QRect(20, 20, 120, 55));
        btn_link->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 5px 5px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"    border: 1px solid #9e9e9e;\n"
"    /* \350\275\273\345\276\256\345\206\205\351\231\267\346\225\210\346\236\234\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213 */\n"
""
                        "    padding: 10px 10px 10px 10px;\n"
"}\n"
"\n"
"/* ==================================\n"
"   \345\257\274\350\210\252\346\214\211\351\222\256\357\274\210Link/ECAT/Setting\357\274\211\351\200\211\344\270\255\351\253\230\344\272\256\346\240\267\345\274\217\n"
"   \351\234\200\345\205\210\345\234\250Qt Designer\344\270\255\345\213\276\351\200\211\346\214\211\351\222\256\347\232\204 checkable \345\261\236\346\200\247\n"
"================================== */\n"
"QPushButton#btn_link:checked\n"
"{\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\351\253\230\344\272\256 */\n"
"    border: 1px solid #1976D2;\n"
"    color: #ffffff;             /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
"/* \345\257\274\350\210\252\346\214\211\351\222\256\351\200\211\344\270\255\346\227\266\347\232\204\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton#btn_link:checked:hover\n"
" {\n"
"    background-color: #1976D2;\n"
"}\n"
""));
        btn_link->setCheckable(true);
        btn_link->setChecked(false);
        btn_enable = new QPushButton(Widget);
        btn_enable->setObjectName("btn_enable");
        btn_enable->setEnabled(true);
        btn_enable->setGeometry(QRect(20, 230, 120, 55));
        btn_enable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"QPushButton#btn_enable:pressed {\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""));
        btn_disable = new QPushButton(Widget);
        btn_disable->setObjectName("btn_disable");
        btn_disable->setEnabled(true);
        btn_disable->setGeometry(QRect(20, 300, 120, 55));
        btn_disable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"QPushButton#btn_disable:pressed {\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""));
        btn_reboot = new QPushButton(Widget);
        btn_reboot->setObjectName("btn_reboot");
        btn_reboot->setEnabled(true);
        btn_reboot->setGeometry(QRect(20, 370, 120, 55));
        btn_reboot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"QPushButton#btn_reboot:pressed {\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""));
        btn_axis = new QPushButton(Widget);
        btn_axis->setObjectName("btn_axis");
        btn_axis->setEnabled(true);
        btn_axis->setGeometry(QRect(20, 440, 120, 55));
        btn_axis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""));
        btn_axis->setCheckable(false);
        btn_dio = new QPushButton(Widget);
        btn_dio->setObjectName("btn_dio");
        btn_dio->setEnabled(true);
        btn_dio->setGeometry(QRect(20, 510, 120, 55));
        btn_dio->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""));
        btn_dio->setCheckable(false);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(1010, 20, 101, 21));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(160, 60, 831, 111));
        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 801, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        checkBox_axis0enable = new QCheckBox(horizontalLayoutWidget);
        checkBox_axis0enable->setObjectName("checkBox_axis0enable");
        checkBox_axis0enable->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(checkBox_axis0enable);

        btn_jognegative = new QPushButton(horizontalLayoutWidget);
        btn_jognegative->setObjectName("btn_jognegative");
        btn_jognegative->setEnabled(false);

        horizontalLayout->addWidget(btn_jognegative);

        btn_jogpositive = new QPushButton(horizontalLayoutWidget);
        btn_jogpositive->setObjectName("btn_jogpositive");
        btn_jogpositive->setEnabled(false);

        horizontalLayout->addWidget(btn_jogpositive);

        comboBox_mode_chose = new QComboBox(horizontalLayoutWidget);
        comboBox_mode_chose->setObjectName("comboBox_mode_chose");
        comboBox_mode_chose->setEnabled(false);

        horizontalLayout->addWidget(comboBox_mode_chose);

        lineEdit_motion_value = new QLineEdit(horizontalLayoutWidget);
        lineEdit_motion_value->setObjectName("lineEdit_motion_value");
        lineEdit_motion_value->setMaximumSize(QSize(120, 20));

        horizontalLayout->addWidget(lineEdit_motion_value);

        btn_run = new QPushButton(horizontalLayoutWidget);
        btn_run->setObjectName("btn_run");
        btn_run->setEnabled(false);

        horizontalLayout->addWidget(btn_run);

        btn_stop = new QPushButton(horizontalLayoutWidget);
        btn_stop->setObjectName("btn_stop");
        btn_stop->setEnabled(false);

        horizontalLayout->addWidget(btn_stop);

        btn_set_2 = new QPushButton(horizontalLayoutWidget);
        btn_set_2->setObjectName("btn_set_2");

        horizontalLayout->addWidget(btn_set_2);

        btn_ECAT = new QPushButton(Widget);
        btn_ECAT->setObjectName("btn_ECAT");
        btn_ECAT->setGeometry(QRect(20, 90, 120, 55));
        btn_ECAT->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"    border: 1px solid #9e9e9e;\n"
"    /* \350\275\273\345\276\256\345\206\205\351\231\267\346\225\210\346\236\234\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213 */\n"
"    padding: 10px 10px 10px 10px;\n"
""
                        "}\n"
"\n"
"QPushButton#btn_ECAT:checked\n"
"{\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\351\253\230\344\272\256 */\n"
"    border: 1px solid #1976D2;\n"
"    color: #ffffff;             /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
"/* \345\257\274\350\210\252\346\214\211\351\222\256\351\200\211\344\270\255\346\227\266\347\232\204\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton#btn_ECAT:checked:hover\n"
" {\n"
"    background-color: #1976D2;\n"
"}"));
        btn_ECAT->setCheckable(true);
        btn_set = new QPushButton(Widget);
        btn_set->setObjectName("btn_set");
        btn_set->setGeometry(QRect(20, 160, 120, 55));
        btn_set->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 12px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"    border: 1px solid #9e9e9e;\n"
"    /* \350\275\273\345\276\256\345\206\205\351\231\267\346\225\210\346\236\234\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213 */\n"
"    padding: 10px 10px 10px 10px;\n"
"}\n"
""
                        "\n"
"\n"
"QPushButton#btn_set:checked\n"
"{\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\351\253\230\344\272\256 */\n"
"    border: 1px solid #1976D2;\n"
"    color: #ffffff;             /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
"/* \345\257\274\350\210\252\346\214\211\351\222\256\351\200\211\344\270\255\346\227\266\347\232\204\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton#btn_set:checked:hover\n"
" {\n"
"    background-color: #1976D2;\n"
"}\n"
""));
        btn_set->setCheckable(true);
        btn_save_log = new QPushButton(Widget);
        btn_save_log->setObjectName("btn_save_log");
        btn_save_log->setGeometry(QRect(1070, 10, 120, 35));
        btn_clear_log = new QPushButton(Widget);
        btn_clear_log->setObjectName("btn_clear_log");
        btn_clear_log->setGeometry(QRect(1220, 10, 120, 35));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(150, 20, 851, 681));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget {\n"
"    background-color: #f0f0f0; \n"
"    border: 1px solid #dcdcdc;\n"
"}"));
        page_Link = new QWidget();
        page_Link->setObjectName("page_Link");
        groupBox_3 = new QGroupBox(page_Link);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 80, 661, 371));
        label_device_name = new QLabel(groupBox_3);
        label_device_name->setObjectName("label_device_name");
        label_device_name->setGeometry(QRect(30, 30, 54, 16));
        label_device_port = new QLabel(groupBox_3);
        label_device_port->setObjectName("label_device_port");
        label_device_port->setGeometry(QRect(30, 80, 54, 16));
        label_slave_numbers = new QLabel(groupBox_3);
        label_slave_numbers->setObjectName("label_slave_numbers");
        label_slave_numbers->setGeometry(QRect(30, 190, 54, 16));
        textEdit_device_name = new QTextEdit(groupBox_3);
        textEdit_device_name->setObjectName("textEdit_device_name");
        textEdit_device_name->setEnabled(false);
        textEdit_device_name->setGeometry(QRect(100, 20, 201, 31));
        textEdit_slave_numbers = new QTextEdit(groupBox_3);
        textEdit_slave_numbers->setObjectName("textEdit_slave_numbers");
        textEdit_slave_numbers->setGeometry(QRect(100, 180, 201, 31));
        comboBox_device_port = new QComboBox(groupBox_3);
        comboBox_device_port->setObjectName("comboBox_device_port");
        comboBox_device_port->setGeometry(QRect(100, 70, 201, 31));
        label_baud_rate = new QLabel(groupBox_3);
        label_baud_rate->setObjectName("label_baud_rate");
        label_baud_rate->setGeometry(QRect(30, 130, 54, 16));
        comboBox_baud_rate = new QComboBox(groupBox_3);
        comboBox_baud_rate->setObjectName("comboBox_baud_rate");
        comboBox_baud_rate->setGeometry(QRect(100, 120, 201, 31));
        btn_open_port = new QPushButton(groupBox_3);
        btn_open_port->setObjectName("btn_open_port");
        btn_open_port->setEnabled(false);
        btn_open_port->setGeometry(QRect(20, 260, 131, 51));
        btn_open_port->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"QPushButton#btn_disable:pressed {\n"
"    padding: 27px 23px 23px 27px;\n"
"}\n"
""));
        btn_open_port->setCheckable(true);
        btn_refresh_port = new QPushButton(groupBox_3);
        btn_refresh_port->setObjectName("btn_refresh_port");
        btn_refresh_port->setGeometry(QRect(340, 70, 121, 31));
        label_linkset = new QLabel(page_Link);
        label_linkset->setObjectName("label_linkset");
        label_linkset->setGeometry(QRect(30, 30, 101, 31));
        btn_link_device = new QPushButton(page_Link);
        btn_link_device->setObjectName("btn_link_device");
        btn_link_device->setEnabled(false);
        btn_link_device->setGeometry(QRect(200, 340, 131, 51));
        btn_unlink = new QPushButton(page_Link);
        btn_unlink->setObjectName("btn_unlink");
        btn_unlink->setEnabled(false);
        btn_unlink->setGeometry(QRect(360, 340, 131, 51));
        btn_rescan = new QPushButton(page_Link);
        btn_rescan->setObjectName("btn_rescan");
        btn_rescan->setEnabled(false);
        btn_rescan->setGeometry(QRect(520, 340, 131, 51));
        stackedWidget->addWidget(page_Link);
        page_Set = new QWidget();
        page_Set->setObjectName("page_Set");
        label_14 = new QLabel(page_Set);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 120, 101, 31));
        label_15 = new QLabel(page_Set);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 170, 141, 21));
        lineEdit_vel = new QLineEdit(page_Set);
        lineEdit_vel->setObjectName("lineEdit_vel");
        lineEdit_vel->setGeometry(QRect(20, 200, 320, 40));
        lineEdit_acc = new QLineEdit(page_Set);
        lineEdit_acc->setObjectName("lineEdit_acc");
        lineEdit_acc->setGeometry(QRect(20, 295, 320, 40));
        label_16 = new QLabel(page_Set);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 270, 161, 21));
        lineEdit_dec = new QLineEdit(page_Set);
        lineEdit_dec->setObjectName("lineEdit_dec");
        lineEdit_dec->setGeometry(QRect(20, 385, 320, 40));
        label_18 = new QLabel(page_Set);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 360, 161, 21));
        label_17 = new QLabel(page_Set);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(380, 270, 151, 21));
        lineEdit_zero_vel = new QLineEdit(page_Set);
        lineEdit_zero_vel->setObjectName("lineEdit_zero_vel");
        lineEdit_zero_vel->setGeometry(QRect(380, 385, 320, 40));
        lineEdit_sw_vel = new QLineEdit(page_Set);
        lineEdit_sw_vel->setObjectName("lineEdit_sw_vel");
        lineEdit_sw_vel->setGeometry(QRect(380, 295, 320, 40));
        label_19 = new QLabel(page_Set);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(380, 170, 161, 21));
        label_20 = new QLabel(page_Set);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(380, 360, 161, 21));
        comboBox_home_mode = new QComboBox(page_Set);
        comboBox_home_mode->setObjectName("comboBox_home_mode");
        comboBox_home_mode->setGeometry(QRect(380, 200, 320, 40));
        btn_setpara = new QPushButton(page_Set);
        btn_setpara->setObjectName("btn_setpara");
        btn_setpara->setGeometry(QRect(20, 480, 191, 61));
        comboBox_mode = new QComboBox(page_Set);
        comboBox_mode->setObjectName("comboBox_mode");
        comboBox_mode->setGeometry(QRect(19, 51, 320, 40));
        label_33 = new QLabel(page_Set);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(19, 20, 81, 31));
        btn_setmode = new QPushButton(page_Set);
        btn_setmode->setObjectName("btn_setmode");
        btn_setmode->setGeometry(QRect(380, 40, 191, 61));
        btn_set_homepara = new QPushButton(page_Set);
        btn_set_homepara->setObjectName("btn_set_homepara");
        btn_set_homepara->setGeometry(QRect(380, 480, 191, 61));
        stackedWidget->addWidget(page_Set);
        page_ECAT = new QWidget();
        page_ECAT->setObjectName("page_ECAT");
        label_3 = new QLabel(page_ECAT);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 20, 161, 16));
        groupBox_4 = new QGroupBox(page_ECAT);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(20, 60, 381, 241));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 30, 54, 16));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(210, 30, 101, 16));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 120, 54, 16));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(210, 120, 54, 16));
        textEdit_cycle = new QTextEdit(groupBox_4);
        textEdit_cycle->setObjectName("textEdit_cycle");
        textEdit_cycle->setEnabled(false);
        textEdit_cycle->setGeometry(QRect(30, 50, 91, 41));
        textEdit_freq = new QTextEdit(groupBox_4);
        textEdit_freq->setObjectName("textEdit_freq");
        textEdit_freq->setEnabled(false);
        textEdit_freq->setGeometry(QRect(210, 50, 91, 41));
        textEdit_slavestate = new QTextEdit(groupBox_4);
        textEdit_slavestate->setObjectName("textEdit_slavestate");
        textEdit_slavestate->setEnabled(false);
        textEdit_slavestate->setGeometry(QRect(210, 140, 91, 41));
        textEdit_dc = new QTextEdit(groupBox_4);
        textEdit_dc->setObjectName("textEdit_dc");
        textEdit_dc->setEnabled(false);
        textEdit_dc->setGeometry(QRect(30, 140, 91, 41));
        groupBox_5 = new QGroupBox(page_ECAT);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(20, 310, 381, 331));
        btn_read_slaveinfo = new QPushButton(groupBox_5);
        btn_read_slaveinfo->setObjectName("btn_read_slaveinfo");
        btn_read_slaveinfo->setGeometry(QRect(20, 110, 111, 71));
        btn_clear_slave_error = new QPushButton(groupBox_5);
        btn_clear_slave_error->setObjectName("btn_clear_slave_error");
        btn_clear_slave_error->setGeometry(QRect(190, 110, 111, 71));
        btn_to_op = new QPushButton(groupBox_5);
        btn_to_op->setObjectName("btn_to_op");
        btn_to_op->setGeometry(QRect(190, 210, 111, 71));
        btn_to_safeop = new QPushButton(groupBox_5);
        btn_to_safeop->setObjectName("btn_to_safeop");
        btn_to_safeop->setGeometry(QRect(20, 210, 111, 71));
        btn_read_XMLfile = new QPushButton(groupBox_5);
        btn_read_XMLfile->setObjectName("btn_read_XMLfile");
        btn_read_XMLfile->setGeometry(QRect(20, 20, 111, 71));
        btn_clear_XMLfile = new QPushButton(groupBox_5);
        btn_clear_XMLfile->setObjectName("btn_clear_XMLfile");
        btn_clear_XMLfile->setGeometry(QRect(190, 20, 111, 71));
        groupBox_6 = new QGroupBox(page_ECAT);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(420, 60, 411, 581));
        textEdit_sdo_index = new QTextEdit(groupBox_6);
        textEdit_sdo_index->setObjectName("textEdit_sdo_index");
        textEdit_sdo_index->setGeometry(QRect(20, 140, 121, 31));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(170, 120, 121, 16));
        textEdit_sdo_subindex = new QTextEdit(groupBox_6);
        textEdit_sdo_subindex->setObjectName("textEdit_sdo_subindex");
        textEdit_sdo_subindex->setGeometry(QRect(170, 140, 131, 31));
        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 120, 121, 16));
        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 30, 111, 16));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(170, 30, 54, 16));
        comboBox_data_type = new QComboBox(groupBox_6);
        comboBox_data_type->setObjectName("comboBox_data_type");
        comboBox_data_type->setGeometry(QRect(170, 50, 131, 31));
        comboBox_slave_num = new QComboBox(groupBox_6);
        comboBox_slave_num->setObjectName("comboBox_slave_num");
        comboBox_slave_num->setGeometry(QRect(20, 50, 131, 31));
        textEdit_sdo_value = new QTextEdit(groupBox_6);
        textEdit_sdo_value->setObjectName("textEdit_sdo_value");
        textEdit_sdo_value->setGeometry(QRect(20, 210, 271, 31));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 190, 171, 16));
        btn_read_sdo = new QPushButton(groupBox_6);
        btn_read_sdo->setObjectName("btn_read_sdo");
        btn_read_sdo->setGeometry(QRect(20, 290, 111, 72));
        btn_write_sdo = new QPushButton(groupBox_6);
        btn_write_sdo->setObjectName("btn_write_sdo");
        btn_write_sdo->setGeometry(QRect(170, 290, 111, 72));
        textEdit_SDO_log = new QTextEdit(groupBox_6);
        textEdit_SDO_log->setObjectName("textEdit_SDO_log");
        textEdit_SDO_log->setGeometry(QRect(20, 380, 261, 141));
        stackedWidget->addWidget(page_ECAT);
        groupBox_6->raise();
        label_3->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        page_Scope = new QWidget();
        page_Scope->setObjectName("page_Scope");
        tabWidget = new QTabWidget(page_Scope);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(180, 10, 661, 661));
        x_t = new QWidget();
        x_t->setObjectName("x_t");
        chartView = new QChartView(x_t);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(9, 9, 631, 621));
        tabWidget->addTab(x_t, QString());
        x_v = new QWidget();
        x_v->setObjectName("x_v");
        tabWidget->addTab(x_v, QString());
        ECAT = new QWidget();
        ECAT->setObjectName("ECAT");
        tabWidget->addTab(ECAT, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        verticalLayoutWidget = new QWidget(page_Scope);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 100, 147, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox_actpos = new QCheckBox(verticalLayoutWidget);
        checkBox_actpos->setObjectName("checkBox_actpos");

        verticalLayout_2->addWidget(checkBox_actpos);

        checkBox_targetpos = new QCheckBox(verticalLayoutWidget);
        checkBox_targetpos->setObjectName("checkBox_targetpos");

        verticalLayout_2->addWidget(checkBox_targetpos);

        checkBox_vel = new QCheckBox(verticalLayoutWidget);
        checkBox_vel->setObjectName("checkBox_vel");

        verticalLayout_2->addWidget(checkBox_vel);

        checkBox_acc = new QCheckBox(verticalLayoutWidget);
        checkBox_acc->setObjectName("checkBox_acc");

        verticalLayout_2->addWidget(checkBox_acc);

        line = new QFrame(page_Scope);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 20, 161, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        label_54 = new QLabel(page_Scope);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(10, 6, 101, 20));
        comboBox_axischose = new QComboBox(page_Scope);
        comboBox_axischose->setObjectName("comboBox_axischose");
        comboBox_axischose->setGeometry(QRect(10, 40, 161, 41));
        btn_begin_scope = new QPushButton(page_Scope);
        btn_begin_scope->setObjectName("btn_begin_scope");
        btn_begin_scope->setGeometry(QRect(10, 480, 151, 41));
        btn_stop_scope = new QPushButton(page_Scope);
        btn_stop_scope->setObjectName("btn_stop_scope");
        btn_stop_scope->setGeometry(QRect(10, 530, 151, 41));
        btn_clear_scope = new QPushButton(page_Scope);
        btn_clear_scope->setObjectName("btn_clear_scope");
        btn_clear_scope->setGeometry(QRect(10, 580, 151, 41));
        btn_out_scope = new QPushButton(page_Scope);
        btn_out_scope->setObjectName("btn_out_scope");
        btn_out_scope->setGeometry(QRect(10, 630, 151, 41));
        layoutWidget = new QWidget(page_Scope);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 270, 161, 201));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_57 = new QLabel(layoutWidget);
        label_57->setObjectName("label_57");

        gridLayout_3->addWidget(label_57, 3, 0, 1, 1);

        label_55 = new QLabel(layoutWidget);
        label_55->setObjectName("label_55");
        label_55->setMinimumSize(QSize(30, 0));

        gridLayout_3->addWidget(label_55, 0, 0, 1, 1);

        comboBox_posall = new QComboBox(layoutWidget);
        comboBox_posall->setObjectName("comboBox_posall");

        gridLayout_3->addWidget(comboBox_posall, 2, 1, 1, 1);

        comboBox_trigger = new QComboBox(layoutWidget);
        comboBox_trigger->setObjectName("comboBox_trigger");

        gridLayout_3->addWidget(comboBox_trigger, 3, 1, 1, 1);

        comboBox_timebase = new QComboBox(layoutWidget);
        comboBox_timebase->setObjectName("comboBox_timebase");
        comboBox_timebase->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(comboBox_timebase, 0, 1, 1, 1);

        label_56 = new QLabel(layoutWidget);
        label_56->setObjectName("label_56");

        gridLayout_3->addWidget(label_56, 2, 0, 1, 1);

        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName("label_58");

        gridLayout_3->addWidget(label_58, 1, 0, 1, 1);

        comboBox_timeall = new QComboBox(layoutWidget);
        comboBox_timeall->setObjectName("comboBox_timeall");

        gridLayout_3->addWidget(comboBox_timeall, 1, 1, 1, 1);

        stackedWidget->addWidget(page_Scope);
        page_RunTime = new QWidget();
        page_RunTime->setObjectName("page_RunTime");
        groupBox_13 = new QGroupBox(page_RunTime);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(20, 20, 161, 71));
        label_59 = new QLabel(groupBox_13);
        label_59->setObjectName("label_59");
        label_59->setGeometry(QRect(120, 20, 41, 41));
        label_59->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        lineEdit_current_delay = new QLineEdit(groupBox_13);
        lineEdit_current_delay->setObjectName("lineEdit_current_delay");
        lineEdit_current_delay->setEnabled(false);
        lineEdit_current_delay->setGeometry(QRect(10, 20, 110, 40));
        groupBox_14 = new QGroupBox(page_RunTime);
        groupBox_14->setObjectName("groupBox_14");
        groupBox_14->setGeometry(QRect(220, 20, 161, 71));
        label_63 = new QLabel(groupBox_14);
        label_63->setObjectName("label_63");
        label_63->setGeometry(QRect(120, 20, 41, 41));
        label_63->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_15 = new QGroupBox(page_RunTime);
        groupBox_15->setObjectName("groupBox_15");
        groupBox_15->setGeometry(QRect(620, 20, 161, 71));
        label_64 = new QLabel(groupBox_15);
        label_64->setObjectName("label_64");
        label_64->setGeometry(QRect(120, 20, 41, 41));
        label_64->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_16 = new QGroupBox(page_RunTime);
        groupBox_16->setObjectName("groupBox_16");
        groupBox_16->setGeometry(QRect(420, 20, 161, 71));
        label_65 = new QLabel(groupBox_16);
        label_65->setObjectName("label_65");
        label_65->setGeometry(QRect(120, 20, 41, 41));
        label_65->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_17 = new QGroupBox(page_RunTime);
        groupBox_17->setObjectName("groupBox_17");
        groupBox_17->setGeometry(QRect(220, 100, 161, 71));
        label_70 = new QLabel(groupBox_17);
        label_70->setObjectName("label_70");
        label_70->setGeometry(QRect(120, 20, 41, 41));
        label_70->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_18 = new QGroupBox(page_RunTime);
        groupBox_18->setObjectName("groupBox_18");
        groupBox_18->setGeometry(QRect(420, 100, 161, 71));
        label_71 = new QLabel(groupBox_18);
        label_71->setObjectName("label_71");
        label_71->setGeometry(QRect(120, 20, 41, 41));
        label_71->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_19 = new QGroupBox(page_RunTime);
        groupBox_19->setObjectName("groupBox_19");
        groupBox_19->setGeometry(QRect(20, 100, 161, 71));
        label_72 = new QLabel(groupBox_19);
        label_72->setObjectName("label_72");
        label_72->setGeometry(QRect(120, 20, 41, 41));
        label_72->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        groupBox_20 = new QGroupBox(page_RunTime);
        groupBox_20->setObjectName("groupBox_20");
        groupBox_20->setGeometry(QRect(620, 100, 161, 71));
        label_73 = new QLabel(groupBox_20);
        label_73->setObjectName("label_73");
        label_73->setGeometry(QRect(120, 20, 41, 41));
        label_73->setStyleSheet(QString::fromUtf8("font: 10pt \"Microsoft YaHei UI\";"));
        lineEdit_average_delay = new QLineEdit(page_RunTime);
        lineEdit_average_delay->setObjectName("lineEdit_average_delay");
        lineEdit_average_delay->setEnabled(false);
        lineEdit_average_delay->setGeometry(QRect(230, 40, 110, 40));
        lineEdit_loss_rate = new QLineEdit(page_RunTime);
        lineEdit_loss_rate->setObjectName("lineEdit_loss_rate");
        lineEdit_loss_rate->setEnabled(false);
        lineEdit_loss_rate->setGeometry(QRect(230, 120, 110, 40));
        lineEdit_jitter = new QLineEdit(page_RunTime);
        lineEdit_jitter->setObjectName("lineEdit_jitter");
        lineEdit_jitter->setEnabled(false);
        lineEdit_jitter->setGeometry(QRect(30, 120, 110, 40));
        lineEdit_min_delay = new QLineEdit(page_RunTime);
        lineEdit_min_delay->setObjectName("lineEdit_min_delay");
        lineEdit_min_delay->setEnabled(false);
        lineEdit_min_delay->setGeometry(QRect(630, 40, 110, 40));
        lineEdit_error_packet = new QLineEdit(page_RunTime);
        lineEdit_error_packet->setObjectName("lineEdit_error_packet");
        lineEdit_error_packet->setEnabled(false);
        lineEdit_error_packet->setGeometry(QRect(430, 120, 110, 40));
        lineEdit_exchange_fre = new QLineEdit(page_RunTime);
        lineEdit_exchange_fre->setObjectName("lineEdit_exchange_fre");
        lineEdit_exchange_fre->setEnabled(false);
        lineEdit_exchange_fre->setGeometry(QRect(630, 120, 110, 40));
        lineEdit_max_delay = new QLineEdit(page_RunTime);
        lineEdit_max_delay->setObjectName("lineEdit_max_delay");
        lineEdit_max_delay->setEnabled(false);
        lineEdit_max_delay->setGeometry(QRect(430, 40, 110, 40));
        stackedWidget->addWidget(page_RunTime);
        stackedWidget_2 = new QStackedWidget(Widget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 710, 1491, 241));
        page_axis = new QWidget();
        page_axis->setObjectName("page_axis");
        groupBox = new QGroupBox(page_axis);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 10, 1471, 211));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, -20, 1441, 201));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName("label_21");

        gridLayout->addWidget(label_21, 1, 0, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName("label_12");

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName("label_25");

        gridLayout->addWidget(label_25, 0, 5, 1, 1);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 0, 4, 1, 1);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName("label_22");

        gridLayout->addWidget(label_22, 0, 1, 1, 1);

        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName("label_27");

        gridLayout->addWidget(label_27, 0, 7, 1, 1);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName("label_26");

        gridLayout->addWidget(label_26, 0, 6, 1, 1);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName("label_23");

        gridLayout->addWidget(label_23, 0, 2, 1, 1);

        label_28 = new QLabel(layoutWidget1);
        label_28->setObjectName("label_28");

        gridLayout->addWidget(label_28, 0, 3, 1, 1);

        label_29 = new QLabel(layoutWidget1);
        label_29->setObjectName("label_29");
        label_29->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_29, 0, 8, 1, 1);

        btn_clear_alarm = new QPushButton(layoutWidget1);
        btn_clear_alarm->setObjectName("btn_clear_alarm");
        btn_clear_alarm->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(btn_clear_alarm, 1, 8, 1, 1);

        lineEdit_errorpos = new QLineEdit(layoutWidget1);
        lineEdit_errorpos->setObjectName("lineEdit_errorpos");
        lineEdit_errorpos->setEnabled(false);
        lineEdit_errorpos->setMinimumSize(QSize(0, 50));
        lineEdit_errorpos->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_errorpos, 1, 7, 1, 1);

        lineEdit_targetpos = new QLineEdit(layoutWidget1);
        lineEdit_targetpos->setObjectName("lineEdit_targetpos");
        lineEdit_targetpos->setEnabled(false);
        lineEdit_targetpos->setMinimumSize(QSize(0, 50));
        lineEdit_targetpos->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_targetpos, 1, 6, 1, 1);

        lineEdit_actpos = new QLineEdit(layoutWidget1);
        lineEdit_actpos->setObjectName("lineEdit_actpos");
        lineEdit_actpos->setEnabled(false);
        lineEdit_actpos->setMinimumSize(QSize(0, 50));
        lineEdit_actpos->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_actpos, 1, 5, 1, 1);

        lineEdit_cmdpos = new QLineEdit(layoutWidget1);
        lineEdit_cmdpos->setObjectName("lineEdit_cmdpos");
        lineEdit_cmdpos->setEnabled(false);
        lineEdit_cmdpos->setMinimumSize(QSize(0, 50));
        lineEdit_cmdpos->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_cmdpos, 1, 4, 1, 1);

        lineEdit_stateword = new QLineEdit(layoutWidget1);
        lineEdit_stateword->setObjectName("lineEdit_stateword");
        lineEdit_stateword->setEnabled(false);
        lineEdit_stateword->setMinimumSize(QSize(0, 50));
        lineEdit_stateword->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_stateword, 1, 1, 1, 1);

        lineEdit_state = new QLineEdit(layoutWidget1);
        lineEdit_state->setObjectName("lineEdit_state");
        lineEdit_state->setEnabled(false);
        lineEdit_state->setMinimumSize(QSize(0, 50));
        lineEdit_state->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(lineEdit_state, 1, 2, 1, 1);

        stackedWidget_2->addWidget(page_axis);
        page_dio = new QWidget();
        page_dio->setObjectName("page_dio");
        groupBox_7 = new QGroupBox(page_dio);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(10, 10, 731, 221));
        layoutWidget2 = new QWidget(groupBox_7);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(60, 25, 661, 181));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_do1_1 = new QPushButton(layoutWidget2);
        btn_do1_1->setObjectName("btn_do1_1");
        btn_do1_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_1, 1, 1, 1, 1);

        btn_do0_1 = new QPushButton(layoutWidget2);
        btn_do0_1->setObjectName("btn_do0_1");
        btn_do0_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_1, 0, 1, 1, 1);

        btn_do1_7 = new QPushButton(layoutWidget2);
        btn_do1_7->setObjectName("btn_do1_7");
        btn_do1_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_7, 1, 7, 1, 1);

        btn_do1_6 = new QPushButton(layoutWidget2);
        btn_do1_6->setObjectName("btn_do1_6");
        btn_do1_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_6, 1, 6, 1, 1);

        btn_do0_5 = new QPushButton(layoutWidget2);
        btn_do0_5->setObjectName("btn_do0_5");
        btn_do0_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_5, 0, 5, 1, 1);

        btn_do2_5 = new QPushButton(layoutWidget2);
        btn_do2_5->setObjectName("btn_do2_5");
        btn_do2_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_5, 2, 5, 1, 1);

        btn_do0_0 = new QPushButton(layoutWidget2);
        btn_do0_0->setObjectName("btn_do0_0");
        btn_do0_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));
        btn_do0_0->setCheckable(true);

        gridLayout_2->addWidget(btn_do0_0, 0, 0, 1, 1);

        btn_do0_6 = new QPushButton(layoutWidget2);
        btn_do0_6->setObjectName("btn_do0_6");
        btn_do0_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_6, 0, 6, 1, 1);

        btn_do2_1 = new QPushButton(layoutWidget2);
        btn_do2_1->setObjectName("btn_do2_1");
        btn_do2_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_1, 2, 1, 1, 1);

        btn_do0_4 = new QPushButton(layoutWidget2);
        btn_do0_4->setObjectName("btn_do0_4");
        btn_do0_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_4, 0, 4, 1, 1);

        btn_do2_4 = new QPushButton(layoutWidget2);
        btn_do2_4->setObjectName("btn_do2_4");
        btn_do2_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_4, 2, 4, 1, 1);

        btn_do2_6 = new QPushButton(layoutWidget2);
        btn_do2_6->setObjectName("btn_do2_6");
        btn_do2_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_6, 2, 6, 1, 1);

        btn_do2_7 = new QPushButton(layoutWidget2);
        btn_do2_7->setObjectName("btn_do2_7");
        btn_do2_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_7, 2, 7, 1, 1);

        btn_do2_0 = new QPushButton(layoutWidget2);
        btn_do2_0->setObjectName("btn_do2_0");
        btn_do2_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_0, 2, 0, 1, 1);

        btn_do1_0 = new QPushButton(layoutWidget2);
        btn_do1_0->setObjectName("btn_do1_0");
        btn_do1_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_0, 1, 0, 1, 1);

        btn_do1_2 = new QPushButton(layoutWidget2);
        btn_do1_2->setObjectName("btn_do1_2");
        btn_do1_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_2, 1, 2, 1, 1);

        btn_do0_3 = new QPushButton(layoutWidget2);
        btn_do0_3->setObjectName("btn_do0_3");
        btn_do0_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_3, 0, 3, 1, 1);

        btn_do1_4 = new QPushButton(layoutWidget2);
        btn_do1_4->setObjectName("btn_do1_4");
        btn_do1_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_4, 1, 4, 1, 1);

        btn_do2_3 = new QPushButton(layoutWidget2);
        btn_do2_3->setObjectName("btn_do2_3");
        btn_do2_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_3, 2, 3, 1, 1);

        btn_do2_2 = new QPushButton(layoutWidget2);
        btn_do2_2->setObjectName("btn_do2_2");
        btn_do2_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do2_2, 2, 2, 1, 1);

        btn_do0_2 = new QPushButton(layoutWidget2);
        btn_do0_2->setObjectName("btn_do0_2");
        btn_do0_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_2, 0, 2, 1, 1);

        btn_do0_7 = new QPushButton(layoutWidget2);
        btn_do0_7->setObjectName("btn_do0_7");
        btn_do0_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do0_7, 0, 7, 1, 1);

        btn_do1_3 = new QPushButton(layoutWidget2);
        btn_do1_3->setObjectName("btn_do1_3");
        btn_do1_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_3, 1, 3, 1, 1);

        btn_do1_5 = new QPushButton(layoutWidget2);
        btn_do1_5->setObjectName("btn_do1_5");
        btn_do1_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_2->addWidget(btn_do1_5, 1, 5, 1, 1);

        layoutWidget3 = new QWidget(groupBox_7);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(10, 30, 51, 171));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(layoutWidget3);
        label_30->setObjectName("label_30");

        verticalLayout->addWidget(label_30);

        label_31 = new QLabel(layoutWidget3);
        label_31->setObjectName("label_31");

        verticalLayout->addWidget(label_31);

        label_32 = new QLabel(layoutWidget3);
        label_32->setObjectName("label_32");

        verticalLayout->addWidget(label_32);

        groupBox_8 = new QGroupBox(page_dio);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(750, 10, 741, 221));
        layoutWidget4 = new QWidget(groupBox_8);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(67, 25, 661, 181));
        gridLayout_4 = new QGridLayout(layoutWidget4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_58 = new QPushButton(layoutWidget4);
        pushButton_58->setObjectName("pushButton_58");
        pushButton_58->setEnabled(false);
        pushButton_58->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_58, 1, 1, 1, 1);

        pushButton_62 = new QPushButton(layoutWidget4);
        pushButton_62->setObjectName("pushButton_62");
        pushButton_62->setEnabled(false);
        pushButton_62->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_62, 1, 5, 1, 1);

        pushButton_51 = new QPushButton(layoutWidget4);
        pushButton_51->setObjectName("pushButton_51");
        pushButton_51->setEnabled(false);
        pushButton_51->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_51, 0, 1, 1, 1);

        pushButton_68 = new QPushButton(layoutWidget4);
        pushButton_68->setObjectName("pushButton_68");
        pushButton_68->setEnabled(false);
        pushButton_68->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_68, 2, 3, 1, 1);

        pushButton_53 = new QPushButton(layoutWidget4);
        pushButton_53->setObjectName("pushButton_53");
        pushButton_53->setEnabled(false);
        pushButton_53->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_53, 0, 2, 1, 1);

        pushButton_60 = new QPushButton(layoutWidget4);
        pushButton_60->setObjectName("pushButton_60");
        pushButton_60->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_60, 1, 3, 1, 1);

        pushButton_72 = new QPushButton(layoutWidget4);
        pushButton_72->setObjectName("pushButton_72");
        pushButton_72->setEnabled(false);
        pushButton_72->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_72, 2, 7, 1, 1);

        pushButton_54 = new QPushButton(layoutWidget4);
        pushButton_54->setObjectName("pushButton_54");
        pushButton_54->setEnabled(false);
        pushButton_54->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_54, 0, 3, 1, 1);

        pushButton_50 = new QPushButton(layoutWidget4);
        pushButton_50->setObjectName("pushButton_50");
        pushButton_50->setEnabled(false);
        pushButton_50->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_50, 0, 7, 1, 1);

        pushButton_64 = new QPushButton(layoutWidget4);
        pushButton_64->setObjectName("pushButton_64");
        pushButton_64->setEnabled(false);
        pushButton_64->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_64, 1, 7, 1, 1);

        pushButton_71 = new QPushButton(layoutWidget4);
        pushButton_71->setObjectName("pushButton_71");
        pushButton_71->setEnabled(false);
        pushButton_71->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_71, 2, 6, 1, 1);

        pushButton_57 = new QPushButton(layoutWidget4);
        pushButton_57->setObjectName("pushButton_57");
        pushButton_57->setEnabled(false);
        pushButton_57->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_57, 1, 0, 1, 1);

        pushButton_67 = new QPushButton(layoutWidget4);
        pushButton_67->setObjectName("pushButton_67");
        pushButton_67->setEnabled(false);
        pushButton_67->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_67, 2, 2, 1, 1);

        pushButton_56 = new QPushButton(layoutWidget4);
        pushButton_56->setObjectName("pushButton_56");
        pushButton_56->setEnabled(false);
        pushButton_56->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_56, 0, 4, 1, 1);

        pushButton_70 = new QPushButton(layoutWidget4);
        pushButton_70->setObjectName("pushButton_70");
        pushButton_70->setEnabled(false);
        pushButton_70->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_70, 2, 5, 1, 1);

        pushButton_55 = new QPushButton(layoutWidget4);
        pushButton_55->setObjectName("pushButton_55");
        pushButton_55->setEnabled(false);
        pushButton_55->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_55, 0, 5, 1, 1);

        pushButton_49 = new QPushButton(layoutWidget4);
        pushButton_49->setObjectName("pushButton_49");
        pushButton_49->setEnabled(false);
        pushButton_49->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_49, 0, 0, 1, 1);

        pushButton_52 = new QPushButton(layoutWidget4);
        pushButton_52->setObjectName("pushButton_52");
        pushButton_52->setEnabled(false);
        pushButton_52->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_52, 0, 6, 1, 1);

        pushButton_59 = new QPushButton(layoutWidget4);
        pushButton_59->setObjectName("pushButton_59");
        pushButton_59->setEnabled(false);
        pushButton_59->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_59, 1, 2, 1, 1);

        pushButton_63 = new QPushButton(layoutWidget4);
        pushButton_63->setObjectName("pushButton_63");
        pushButton_63->setEnabled(false);
        pushButton_63->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_63, 1, 6, 1, 1);

        pushButton_61 = new QPushButton(layoutWidget4);
        pushButton_61->setObjectName("pushButton_61");
        pushButton_61->setEnabled(false);
        pushButton_61->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_61, 1, 4, 1, 1);

        pushButton_65 = new QPushButton(layoutWidget4);
        pushButton_65->setObjectName("pushButton_65");
        pushButton_65->setEnabled(false);
        pushButton_65->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_65, 2, 0, 1, 1);

        pushButton_69 = new QPushButton(layoutWidget4);
        pushButton_69->setObjectName("pushButton_69");
        pushButton_69->setEnabled(false);
        pushButton_69->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_69, 2, 4, 1, 1);

        pushButton_66 = new QPushButton(layoutWidget4);
        pushButton_66->setObjectName("pushButton_66");
        pushButton_66->setEnabled(false);
        pushButton_66->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    /* \345\237\272\347\241\200\346\240\267\345\274\217\357\274\232\346\265\205\347\201\260\345\234\206\345\275\242 */\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 25px;       /* \345\234\206\345\275\242\345\205\263\351\224\256\357\274\232\345\256\275\351\253\230\347\233\270\347\255\211\346\227\266\357\274\214\345\215\212\345\276\204\350\256\276\344\270\272\344\270\200\345\215\212 */\n"
"    min-width: 50px;\n"
"    min-height: 50px;\n"
"    max-width: 50px;\n"
"    max-height: 50px;\n"
"    font-size: 12px;\n"
"    color: #333333;            /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\232\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\346\227\266\350\275\273\345\276\256\345\217\230\347\201\260 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"\n"
"QPushButton:checked {\n"
"    backgroun"
                        "d-color: #4caf50; /* \344\270\273\347\273\277\350\211\262 */\n"
"    border: 1px solid #388e3c; /* \346\267\261\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    color: #ffffff;            /* \346\226\207\345\255\227\345\217\230\347\231\275\357\274\214\346\233\264\351\206\222\347\233\256 */\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"    background-color: #388e3c;\n"
"}"));

        gridLayout_4->addWidget(pushButton_66, 2, 1, 1, 1);

        layoutWidget5 = new QWidget(groupBox_8);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(20, 25, 41, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_39 = new QLabel(layoutWidget5);
        label_39->setObjectName("label_39");

        verticalLayout_3->addWidget(label_39);

        label_41 = new QLabel(layoutWidget5);
        label_41->setObjectName("label_41");

        verticalLayout_3->addWidget(label_41);

        label_40 = new QLabel(layoutWidget5);
        label_40->setObjectName("label_40");

        verticalLayout_3->addWidget(label_40);

        stackedWidget_2->addWidget(page_dio);
        btn_open_port_2 = new QPushButton(Widget);
        btn_open_port_2->setObjectName("btn_open_port_2");
        btn_open_port_2->setGeometry(QRect(1360, 10, 120, 35));
        btn_open_port_2->setCheckable(true);
        btn_scope = new QPushButton(Widget);
        btn_scope->setObjectName("btn_scope");
        btn_scope->setEnabled(true);
        btn_scope->setGeometry(QRect(20, 580, 120, 55));
        btn_scope->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 5px 5px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"    border: 1px solid #9e9e9e;\n"
"    /* \350\275\273\345\276\256\345\206\205\351\231\267\346\225\210\346\236\234\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213 */\n"
""
                        "    padding: 10px 10px 10px 10px;\n"
"}\n"
"\n"
"/* ==================================\n"
"   \345\257\274\350\210\252\346\214\211\351\222\256\357\274\210Link/ECAT/Setting\357\274\211\351\200\211\344\270\255\351\253\230\344\272\256\346\240\267\345\274\217\n"
"   \351\234\200\345\205\210\345\234\250Qt Designer\344\270\255\345\213\276\351\200\211\346\214\211\351\222\256\347\232\204 checkable \345\261\236\346\200\247\n"
"================================== */\n"
"QPushButton#btn_scope:checked\n"
"{\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\351\253\230\344\272\256 */\n"
"    border: 1px solid #1976D2;\n"
"    color: #ffffff;             /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
"/* \345\257\274\350\210\252\346\214\211\351\222\256\351\200\211\344\270\255\346\227\266\347\232\204\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton#btn_scope:checked:hover\n"
" {\n"
"    background-color: #1976D2;\n"
"}\n"
""));
        btn_scope->setCheckable(true);
        btn_RunTime = new QPushButton(Widget);
        btn_RunTime->setObjectName("btn_RunTime");
        btn_RunTime->setEnabled(true);
        btn_RunTime->setGeometry(QRect(20, 650, 120, 55));
        btn_RunTime->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f5f5f5;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 15px;      /* \345\234\206\350\247\222 */\n"
"    padding: 5px 5px;            /* \345\206\205\350\276\271\350\267\235*/\n"
"    font-size: 20px;          /* \346\226\207\345\255\227\345\244\247\345\260\217 */\n"
"    color: #333333;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"/* \346\202\254\345\201\234\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\346\224\276\344\270\212\345\216\273\357\274\211 */\n"
"QPushButton:hover {\n"
"    background-color: #e8e8e8;\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"/* \346\214\211\344\270\213\347\212\266\346\200\201\357\274\210\351\274\240\346\240\207\347\202\271\345\207\273\346\227\266\357\274\211 */\n"
"QPushButton:pressed {\n"
"    background-color: #d0d0d0;\n"
"    border: 1px solid #9e9e9e;\n"
"    /* \350\275\273\345\276\256\345\206\205\351\231\267\346\225\210\346\236\234\357\274\214\346\250\241\346\213\237\346\214\211\345\216\213 */\n"
""
                        "    padding: 10px 10px 10px 10px;\n"
"}\n"
"\n"
"/* ==================================\n"
"   \345\257\274\350\210\252\346\214\211\351\222\256\357\274\210Link/ECAT/Setting\357\274\211\351\200\211\344\270\255\351\253\230\344\272\256\346\240\267\345\274\217\n"
"   \351\234\200\345\205\210\345\234\250Qt Designer\344\270\255\345\213\276\351\200\211\346\214\211\351\222\256\347\232\204 checkable \345\261\236\346\200\247\n"
"================================== */\n"
"QPushButton#btn_RunTime:checked\n"
"{\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\351\253\230\344\272\256 */\n"
"    border: 1px solid #1976D2;\n"
"    color: #ffffff;             /* \346\226\207\345\255\227\345\217\230\347\231\275 */\n"
"}\n"
"\n"
"/* \345\257\274\350\210\252\346\214\211\351\222\256\351\200\211\344\270\255\346\227\266\347\232\204\346\202\254\345\201\234\346\225\210\346\236\234 */\n"
"QPushButton#btn_RunTime:checked:hover\n"
" {\n"
"    background-color: #1976D2;\n"
"}\n"
""));
        btn_RunTime->setCheckable(true);
        groupBox_2->raise();
        stackedWidget->raise();
        textEdit_log_info->raise();
        btn_disable->raise();
        btn_reboot->raise();
        btn_link->raise();
        btn_enable->raise();
        btn_axis->raise();
        btn_dio->raise();
        label->raise();
        btn_ECAT->raise();
        btn_set->raise();
        btn_save_log->raise();
        btn_clear_log->raise();
        stackedWidget_2->raise();
        btn_open_port_2->raise();
        btn_scope->raise();
        btn_RunTime->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_link->setText(QCoreApplication::translate("Widget", "Link", nullptr));
        btn_enable->setText(QCoreApplication::translate("Widget", "Enable", nullptr));
        btn_disable->setText(QCoreApplication::translate("Widget", "Disable", nullptr));
        btn_reboot->setText(QCoreApplication::translate("Widget", "Reboot", nullptr));
        btn_axis->setText(QCoreApplication::translate("Widget", "Axis", nullptr));
        btn_dio->setText(QCoreApplication::translate("Widget", "DIO", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("Widget", "Axis0", nullptr));
        checkBox_axis0enable->setText(QCoreApplication::translate("Widget", "enable", nullptr));
        btn_jognegative->setText(QCoreApplication::translate("Widget", "Jog-", nullptr));
        btn_jogpositive->setText(QCoreApplication::translate("Widget", "Jog+", nullptr));
        lineEdit_motion_value->setText(QCoreApplication::translate("Widget", "0", nullptr));
        btn_run->setText(QCoreApplication::translate("Widget", "RUN", nullptr));
        btn_stop->setText(QCoreApplication::translate("Widget", "STOP", nullptr));
        btn_set_2->setText(QCoreApplication::translate("Widget", "SET", nullptr));
        btn_ECAT->setText(QCoreApplication::translate("Widget", "ECAT", nullptr));
        btn_set->setText(QCoreApplication::translate("Widget", "Set", nullptr));
        btn_save_log->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\227\245\345\277\227", nullptr));
        btn_clear_log->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        groupBox_3->setTitle(QString());
        label_device_name->setText(QCoreApplication::translate("Widget", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        label_device_port->setText(QCoreApplication::translate("Widget", "\350\256\276\345\244\207\347\253\257\345\217\243", nullptr));
        label_slave_numbers->setText(QCoreApplication::translate("Widget", "\344\273\216\347\253\231\346\225\260\351\207\217", nullptr));
        label_baud_rate->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        btn_open_port->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        btn_refresh_port->setText(QCoreApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        label_linkset->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\351\205\215\347\275\256", nullptr));
        btn_link_device->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        btn_unlink->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        btn_rescan->setText(QCoreApplication::translate("Widget", "\351\207\215\346\226\260\346\211\253\346\217\217", nullptr));
        label_14->setText(QCoreApplication::translate("Widget", "\350\277\220\345\212\250\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246", nullptr));
        lineEdit_vel->setText(QCoreApplication::translate("Widget", "1045876", nullptr));
        lineEdit_acc->setText(QCoreApplication::translate("Widget", "10458760", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "\345\212\240\351\200\237\345\272\246", nullptr));
        lineEdit_dec->setText(QCoreApplication::translate("Widget", "10458760", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "\345\207\217\351\200\237\345\272\246", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "\345\233\236\351\233\266\346\220\234\347\264\242\351\200\237\345\272\246\357\274\210sw\357\274\211", nullptr));
        lineEdit_zero_vel->setText(QCoreApplication::translate("Widget", "50000", nullptr));
        lineEdit_sw_vel->setText(QCoreApplication::translate("Widget", "1045876", nullptr));
        label_19->setText(QCoreApplication::translate("Widget", "\345\233\236\351\233\266\346\250\241\345\274\217", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "\345\233\236\351\233\266\347\262\276\345\256\232\344\275\215\351\200\237\345\272\246\357\274\210zero\357\274\211", nullptr));
        btn_setpara->setText(QCoreApplication::translate("Widget", "\345\206\231\345\205\245\351\200\237\345\272\246\345\217\202\346\225\260", nullptr));
        label_33->setText(QCoreApplication::translate("Widget", "\346\250\241\345\274\217\351\200\211\346\213\251", nullptr));
        btn_setmode->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256\346\250\241\345\274\217", nullptr));
        btn_set_homepara->setText(QCoreApplication::translate("Widget", "\345\206\231\345\205\245\345\233\236\351\233\266\345\217\202\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "EtherCAT\350\260\203\350\257\225\346\216\247\345\210\266\345\217\260", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Widget", "ECAT\345\256\236\346\227\266\347\233\221\346\216\247", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\351\200\232\344\277\241\345\221\250\346\234\237", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\345\256\236\346\227\266\351\242\221\347\216\207\357\274\210HZ\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "DC\345\220\214\346\255\245", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\344\273\216\347\253\231\347\212\266\346\200\201", nullptr));
        textEdit_cycle->setHtml(QCoreApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:700; color:#0000ff;\">1000us</span></p></body></html>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Widget", "ECAT\346\216\247\345\210\266", nullptr));
        btn_read_slaveinfo->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226\344\273\216\347\253\231\344\277\241\346\201\257", nullptr));
        btn_clear_slave_error->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\344\273\216\347\253\231\351\224\231\350\257\257", nullptr));
        btn_to_op->setText(QCoreApplication::translate("Widget", "\345\210\207\346\215\242\350\207\263OP", nullptr));
        btn_to_safeop->setText(QCoreApplication::translate("Widget", "\345\210\207\346\215\242\350\207\263SAFE-OP", nullptr));
        btn_read_XMLfile->setText(QCoreApplication::translate("Widget", "\345\257\274\345\205\245XML\346\226\207\344\273\266", nullptr));
        btn_clear_XMLfile->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244XML\346\226\207\344\273\266", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Widget", "SDO\350\257\273\345\206\231", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\345\255\220\347\264\242\345\274\225\357\274\2100xXXXX\357\274\211", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "SDO\347\264\242\345\274\225\357\274\2100xXXXX\357\274\211", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "\344\273\216\347\253\231\345\217\267\357\274\210slave\357\274\211", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\346\225\260\345\200\274\357\274\210DEC\357\274\211", nullptr));
        btn_read_sdo->setText(QCoreApplication::translate("Widget", "\350\257\273\345\217\226SDO", nullptr));
        btn_write_sdo->setText(QCoreApplication::translate("Widget", "\345\206\231\345\205\245SDO", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(x_t), QCoreApplication::translate("Widget", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(x_v), QCoreApplication::translate("Widget", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ECAT), QCoreApplication::translate("Widget", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "\351\241\265", nullptr));
        checkBox_actpos->setText(QCoreApplication::translate("Widget", "\345\256\236\351\231\205\344\275\215\347\275\256\357\274\210actpos\357\274\211", nullptr));
        checkBox_targetpos->setText(QCoreApplication::translate("Widget", "\346\214\207\344\273\244\344\275\215\347\275\256 (target pos)", nullptr));
        checkBox_vel->setText(QCoreApplication::translate("Widget", "\351\200\237\345\272\246 (vel)", nullptr));
        checkBox_acc->setText(QCoreApplication::translate("Widget", "\345\212\240\351\200\237\345\272\246\357\274\210acc\357\274\211", nullptr));
        label_54->setText(QCoreApplication::translate("Widget", "\350\275\264\351\200\211\346\213\251", nullptr));
        btn_begin_scope->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\347\273\230\345\210\266", nullptr));
        btn_stop_scope->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\347\273\230\345\210\266", nullptr));
        btn_clear_scope->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\345\233\276\345\203\217", nullptr));
        btn_out_scope->setText(QCoreApplication::translate("Widget", "\345\257\274\345\207\272\345\233\276\345\203\217", nullptr));
        label_57->setText(QCoreApplication::translate("Widget", "\350\247\246\345\217\221", nullptr));
        label_55->setText(QCoreApplication::translate("Widget", "\346\227\266\345\237\272", nullptr));
        label_56->setText(QCoreApplication::translate("Widget", "\351\207\217\347\250\213", nullptr));
        label_58->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\346\227\266\351\227\264", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\345\273\266\346\227\266", nullptr));
        label_59->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("Widget", "\345\271\263\345\235\207\345\273\266\346\227\266", nullptr));
        label_63->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("Widget", "\346\234\200\345\260\217\345\273\266\346\227\266", nullptr));
        label_64->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("Widget", "\346\234\200\345\244\247\345\273\266\346\227\266", nullptr));
        label_65->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        groupBox_17->setTitle(QCoreApplication::translate("Widget", "\344\270\242\345\214\205\347\216\207", nullptr));
        label_70->setText(QCoreApplication::translate("Widget", "%", nullptr));
        groupBox_18->setTitle(QCoreApplication::translate("Widget", "\351\224\231\350\257\257\345\214\205\346\225\260", nullptr));
        label_71->setText(QCoreApplication::translate("Widget", "\344\270\252", nullptr));
        groupBox_19->setTitle(QCoreApplication::translate("Widget", "\346\212\226\345\212\250(Jitter)", nullptr));
        label_72->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        groupBox_20->setTitle(QCoreApplication::translate("Widget", "\351\200\232\344\277\241\351\242\221\347\216\207", nullptr));
        label_73->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        lineEdit_exchange_fre->setText(QCoreApplication::translate("Widget", "1", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "GroupBox", nullptr));
        label_21->setText(QCoreApplication::translate("Widget", "Axis(0)", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "Axis ID", nullptr));
        label_25->setText(QCoreApplication::translate("Widget", "\345\256\236\351\231\205\344\275\215\347\275\256\357\274\210act pos\357\274\211", nullptr));
        label_24->setText(QCoreApplication::translate("Widget", "\347\220\206\350\256\272\344\275\215\347\275\256\357\274\210cmd pos\357\274\211", nullptr));
        label_22->setText(QCoreApplication::translate("Widget", "\344\274\272\346\234\215\347\212\266\346\200\201\345\255\227", nullptr));
        label_27->setText(QCoreApplication::translate("Widget", "\350\257\257\345\267\256\344\275\215\347\275\256\357\274\210error pos\357\274\211", nullptr));
        label_26->setText(QCoreApplication::translate("Widget", "\346\214\207\344\273\244\344\275\215\347\275\256\357\274\210target pos\357\274\211", nullptr));
        label_23->setText(QCoreApplication::translate("Widget", "\347\212\266\346\200\201", nullptr));
        label_28->setText(QCoreApplication::translate("Widget", "\344\275\277\350\203\275", nullptr));
        label_29->setText(QCoreApplication::translate("Widget", "\346\212\245\350\255\246", nullptr));
        btn_clear_alarm->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\212\245\350\255\246", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("Widget", "DO", nullptr));
        btn_do1_1->setText(QString());
        btn_do0_1->setText(QString());
        btn_do1_7->setText(QString());
        btn_do1_6->setText(QString());
        btn_do0_5->setText(QString());
        btn_do2_5->setText(QString());
        btn_do0_0->setText(QString());
        btn_do0_6->setText(QString());
        btn_do2_1->setText(QString());
        btn_do0_4->setText(QString());
        btn_do2_4->setText(QString());
        btn_do2_6->setText(QString());
        btn_do2_7->setText(QString());
        btn_do2_0->setText(QString());
        btn_do1_0->setText(QString());
        btn_do1_2->setText(QString());
        btn_do0_3->setText(QString());
        btn_do1_4->setText(QString());
        btn_do2_3->setText(QString());
        btn_do2_2->setText(QString());
        btn_do0_2->setText(QString());
        btn_do0_7->setText(QString());
        btn_do1_3->setText(QString());
        btn_do1_5->setText(QString());
        label_30->setText(QCoreApplication::translate("Widget", "DO0", nullptr));
        label_31->setText(QCoreApplication::translate("Widget", "DO1", nullptr));
        label_32->setText(QCoreApplication::translate("Widget", "DO2", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("Widget", "DI", nullptr));
        pushButton_58->setText(QString());
        pushButton_62->setText(QString());
        pushButton_51->setText(QString());
        pushButton_68->setText(QString());
        pushButton_53->setText(QString());
        pushButton_60->setText(QString());
        pushButton_72->setText(QString());
        pushButton_54->setText(QString());
        pushButton_50->setText(QString());
        pushButton_64->setText(QString());
        pushButton_71->setText(QString());
        pushButton_57->setText(QString());
        pushButton_67->setText(QString());
        pushButton_56->setText(QString());
        pushButton_70->setText(QString());
        pushButton_55->setText(QString());
        pushButton_49->setText(QString());
        pushButton_52->setText(QString());
        pushButton_59->setText(QString());
        pushButton_63->setText(QString());
        pushButton_61->setText(QString());
        pushButton_65->setText(QString());
        pushButton_69->setText(QString());
        pushButton_66->setText(QString());
        label_39->setText(QCoreApplication::translate("Widget", "DI0", nullptr));
        label_41->setText(QCoreApplication::translate("Widget", "DI1", nullptr));
        label_40->setText(QCoreApplication::translate("Widget", "DI2", nullptr));
        btn_open_port_2->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        btn_scope->setText(QCoreApplication::translate("Widget", "Scope", nullptr));
        btn_RunTime->setText(QCoreApplication::translate("Widget", "RunTime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
