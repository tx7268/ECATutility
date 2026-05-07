#ifndef PROTOCOL_H
#define PROTOCOL_H


#include <QObject>
#include <QString>


/*请求指令码：
指令码  功能          轴号范围  备注
0x01	使能轴	        0~8	     无
0x02	失能轴	        0~8	     无
0x03	停止	        0~8	     无
0x04	重置	        0~8	     无
0x05	回零	        0~8	     无

0x06	点动正转	    1~8	     无
0x07	点动反转	    1~8	     无
0x08	停止点动	    1~8	     无

0x09    清除从站错误

0x10	绝对运动	    1~8	     4字节位置
0x11	相对运动	    1~8	     4字节偏移

0x20	设置速度	    1~8	     2字节速度
0x21	设置加速度	    1~8	     2字节加速度
0x22	设置减速度	    1~8	     2字节减速度

0x30	读取位置	    1~8	    无
0x31	读取速度	    1~8	    无
0x32	读取状态	    1~8	    无

0x40	写8位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B) + value(1B)
0x41	写16位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B) + value(2B)
0x42	写32位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B) + value(4B)
0x43	读8位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B)
0x44	读16位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B)
0x45	读32位SDO	    1~8	    slaveIndex(2B) + sdo_index(2B) + subindex(1B)


0x47    切换至safe-op
0x48    切换至op

0x50    读取从站信息
*/


/*
应答指令码：
0x81 |使能
0x82 |失能
0x83 |停止
0x84 |重置
0x85 |回零

0x86 |点动正转	
0x87 |点动反转	
0x88 |停止点动	

0x90 |绝对运动
0x91 |相对运动

0xA0 |速度
0xA1 |加速度
0xA2 |减速度

0xB0 |位置
0xB1 |速度
0xB2 |状态

0xC0 |SDO写8
0xC1 |SDO写16
0xC2 |SDO写32
0xC3 |SDO读8
0xC4 |SDO读16
0xC5 |SDO读32
*/

#define FRAME_HEADER        0xAA    // 帧头
#define FRAME_TYPE_REQ      0x01    // 请求帧
#define FRAME_TYPE_ACK      0x02    // 应答帧
#define FRAME_TYPE_ERR      0x03    // 错误帧
#define FRAME_TYPE_DATA     0x04    // 主动上传数据帧


/* 请求指令码 */
#define CMD_AXIS_EN         0x01
#define CMD_AXIS_DIS        0x02
#define CMD_STOP            0x03
#define CMD_RESET           0x04
#define CMD_HOME            0x05
#define CMD_JOG_POS         0x06
#define CMD_JOG_NEG         0x07
#define CMD_JOG_STOP        0x08
#define CMD_CLR_SLAVE_ERR   0x09
#define CMD_MOVE_ABS        0x10
#define CMD_MOVE_REL        0x11
#define CMD_MOVE_DEG        0x12
#define CMD_SET_VEL         0x20
#define CMD_SET_ACC         0x21
#define CMD_SET_DEC         0x22
#define CMD_READ_POS        0x30
#define CMD_READ_VEL        0x31
#define CMD_READ_STATUS     0x32
#define CMD_SDO_WRITE_8      0x40
#define CMD_SDO_WRITE_16     0x41
#define CMD_SDO_WRITE_32     0x42
#define CMD_SDO_READ_8       0x43
#define CMD_SDO_READ_16      0x44
#define CMD_SDO_READ_32      0x45
#define CMD_ECAT_UNLINK      0x46
#define CMD_TO_SAFEOP        0x47
#define CMD_TO_OP            0x48
#define CMD_ECAT_RESCAN      0x49
#define CMD_READ_SLAVE_INFO  0x50
#define CMD_DIO_SET_OUTPUT   0x51
#define CMD_DIO_READ_INPUT   0x52

#define CMD_UPLOAD_MONITOR   0x60// 周期监视上传


#pragma pack(push, 1)
typedef struct
{
    qint32  actpos;
    qint32  cmdpos;
    qint32  errorpos;
    qint16  state;
    quint16 stateword;
    qint32  targetpos;
    qint32  runvel;
    qint32  velcmd;
    qint32  dc;
    quint32 freq;
    quint16 slavestate;
    quint16 di_input;
} MonitorUpload_t;
#pragma pack(pop)

class Protocol : public QObject
{
    Q_OBJECT
public:
    explicit Protocol(QObject *parent = nullptr);
    ~Protocol();

    QByteArray packCommand(uint8_t type, uint8_t cmd, uint8_t axis, uint8_t seq, QByteArray payload);


    QByteArray enableAxis(uint8_t axis);        // 使能指定轴
    QByteArray enableAllAxes();                 // 使能所有轴
    QByteArray disableAxis(uint8_t axis);       // 失能指定轴
    QByteArray disableAllAxes();                // 失能所有轴
    QByteArray stopAxis(uint8_t axis);          // 急停指定轴
    QByteArray stopAllAxes();                   // 急停所有轴
    QByteArray resetAxis(uint8_t axis);         // 复位指定轴
    QByteArray resetAllAxes();                  // 复位所有轴
    QByteArray homeAxis(uint8_t axis, uint8_t homingMode);          // 回零指定轴
    QByteArray homeAllAxes(uint8_t homingMode);                     // 回零所有轴
    QByteArray clear_error(uint8_t axis);       // 清除从站错误

    // ====================== 运动控制指令 ======================
    QByteArray jogforward(uint8_t axis);        // 点动正转
    QByteArray jogbackward(uint8_t axis);       // 点动反转
    QByteArray jogstop(uint8_t axis);           // 停止点动

    // ====================== 位置控制指令 ======================
    QByteArray moveabs(uint8_t axis, qint32 position);  // 绝对位置运动
    QByteArray moverel(uint8_t axis, qint32 offset);    // 相对位置运动
    QByteArray movedeg(uint8_t axis, qint32 offset);    // 角度运动

    // ====================== 参数设置指令 ======================
    QByteArray setvel(uint8_t axis, qint16 speed); // 设置速度
    QByteArray setacc(uint8_t axis, qint16 acc);   // 设置加速度
    QByteArray setdec(uint8_t axis, qint16 dec);   // 设置减速度

    // ====================== 状态读取指令 ======================
    QByteArray getcmdpos(uint8_t axis);  // 读取理论
    QByteArray gettargpos(uint8_t axis); // 读取目标位置
    QByteArray getactpos(uint8_t axis);  // 读取实际位置
	QByteArray getvel(uint8_t axis);	 // 读取速度
    QByteArray getstatus(uint8_t axis);  // 读取状态


    // 写8位SDO：slaveIndex(2) + index(2) + subindex(1) + value(1)
    QByteArray writeSDO8(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint8_t sdo_value);
    // 写16位SDO
    QByteArray writeSDO16(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint16_t sdo_value);
    // 写32位SDO
    QByteArray writeSDO32(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint32_t sdo_value);
    // 读8位SDO
    QByteArray readSDO8(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex);
    // 读16位SDO
    QByteArray readSDO16(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex);
    // 读32位SDO
    QByteArray readSDO32(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex);

    QByteArray read_slaveinfo(uint8_t axis);  // 读取从站信息
    QByteArray switch_safeop(uint8_t axis);
    QByteArray switch_op(uint8_t axis);
    QByteArray unlinkEcat();
    QByteArray rescanEcat();
    QByteArray setDioOutput(uint8_t slave, uint16_t outputMask);
    QByteArray readDioInput(uint8_t slave);
public slots:


signals:

    void commandSent(const QByteArray& command);  // 命令发送信号
    void errorOccurred(const QString& error);     // 错误信号


private:
    // 辅助方法：将整数转换为字节数组（小端序）
    QByteArray int32ToBytes(qint32 value);
    QByteArray int16ToBytes(qint16 value);

    // 无符号16位整数转字节数组（小端序）
    QByteArray uint16ToBytes(uint16_t value);
    // 无符号32位整数转字节数组（小端序）
    QByteArray uint32ToBytes(uint32_t value);

    // 辅助方法：字节序转换（如果需要大端序）
    bool m_littleEndian = true;  // 默认小端序
    uint8_t m_seq = 0x01; // 固定序列号，可自增
};

#endif // PROTOCOL_H
