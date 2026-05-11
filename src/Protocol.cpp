#include "inc/Protocol.h"

Protocol::Protocol(QObject *parent)
    : QObject{parent}

{
    m_littleEndian = true;
}

Protocol::~Protocol()
{
}

/**
 * @brief 通用命令打包函数实现
 * 格式：HEAD(0xAA) + TYPE(1B) + CMD(1B) + AXIS(1B) + SEQ(1B) + LEN(1B) + DATA + CRC
 */
QByteArray Protocol::packCommand(uint8_t type, uint8_t cmd, uint8_t axis, uint8_t seq, QByteArray payload) 
{
    QByteArray frame;

    frame.append(FRAME_HEADER); // 1. 固定帧头
    frame.append(type); // 2. 帧类型
    frame.append(cmd); // 3. 指令码
    frame.append(axis);// 4. 轴号
    frame.append(seq);// 5. 序列号
    frame.append(payload.size());// 6. 数据长度
    frame.append(payload);// 7. 数据段

    uint8_t crc = 0;
    for (auto b : frame)
        crc ^= b;

    frame.append(crc);

    if (type == FRAME_TYPE_REQ)
    {
        ++m_seq;
        if (m_seq == 0)
        {
            m_seq = 1;
        }
    }

    return frame;
}

QByteArray Protocol::writeSDO8(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint8_t sdo_value)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));   // 2字节：从站索引
    payload.append(uint16ToBytes(sdo_index));    // 2字节：SDO索引
    payload.append(sdo_subindex);                // 1字节：SDO子索引
    payload.append(sdo_value);                   // 1字节：写入值
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_WRITE_8, 0, m_seq, payload);// 轴号固定0
}

QByteArray Protocol::writeSDO16(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint16_t sdo_value)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));
    payload.append(uint16ToBytes(sdo_index));
    payload.append(sdo_subindex);
    payload.append(uint16ToBytes(sdo_value));    // 2字节：写入值
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_WRITE_16, 0, m_seq, payload);
}

QByteArray Protocol::writeSDO32(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex, uint32_t sdo_value)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));
    payload.append(uint16ToBytes(sdo_index));
    payload.append(sdo_subindex);
    payload.append(uint32ToBytes(sdo_value));    // 4字节：写入值
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_WRITE_32, 0, m_seq, payload);
}

QByteArray Protocol::readSDO8(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));
    payload.append(uint16ToBytes(sdo_index));
    payload.append(sdo_subindex);
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_READ_8, 0, m_seq, payload);

}

QByteArray Protocol::readSDO16(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));
    payload.append(uint16ToBytes(sdo_index));
    payload.append(sdo_subindex);
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_READ_16, 0, m_seq, payload);
}

QByteArray Protocol::readSDO32(uint16_t slaveIndex, uint16_t sdo_index, uint8_t sdo_subindex)
{
    QByteArray payload;
    payload.append(uint16ToBytes(slaveIndex));
    payload.append(uint16ToBytes(sdo_index));
    payload.append(sdo_subindex);
    return packCommand(FRAME_TYPE_REQ, CMD_SDO_READ_32, 0, m_seq, payload);
}


// 使能指定轴，指令：0x AA 01 AXIS+1 NULL
QByteArray Protocol::enableAxis(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_AXIS_EN, axis, m_seq, QByteArray());
}

// 使能所有轴,指令：0x AA 01 00 NULL
QByteArray Protocol::enableAllAxes()
{
    return packCommand(FRAME_TYPE_REQ, CMD_AXIS_EN, 0x00, m_seq, QByteArray());
}

// 失能指定轴，指令：0xAA 02 AXIS+1 NULL
QByteArray Protocol::disableAxis(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_AXIS_DIS, axis, m_seq, QByteArray());
}

// 失能所有轴，指令：0xAA 02 00 NULL
QByteArray Protocol::disableAllAxes()
{
    return packCommand(FRAME_TYPE_REQ, CMD_AXIS_DIS, 0x00, m_seq, QByteArray());
}

// 停止轴运动，指令：0xAA 03 AXIS+1 NULL
QByteArray Protocol::stopAxis(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_STOP, axis, m_seq, QByteArray());
}

// 停止所有轴运动，指令：0xAA 03 00 NULL
QByteArray Protocol::stopAllAxes()
{
    return packCommand(FRAME_TYPE_REQ, CMD_STOP, 0x00, m_seq, QByteArray());
}

// 重启指定轴，指令：0xAA 04 AXIS+1 NULL
QByteArray Protocol::resetAxis(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_RESET, axis, m_seq, QByteArray());
}

// 重启所有轴，指令：0xAA 04 00 NULL
QByteArray Protocol::resetAllAxes()
{
    return packCommand(FRAME_TYPE_REQ, CMD_RESET, 0x00, m_seq, QByteArray());
}

// 回零指定轴，指令：0xAA 05 AXIS+1 NULL
QByteArray Protocol::homeAxis(uint8_t axis, uint8_t homingMode)
{
    QByteArray payload;
    payload.append(homingMode);
    return packCommand(FRAME_TYPE_REQ, CMD_HOME, axis, m_seq, payload);
}

// 回零所有轴，指令：0xAA 05 00 NULL
QByteArray Protocol::homeAllAxes(uint8_t homingMode)
{
    QByteArray payload;
    payload.append(homingMode);
    return  packCommand(FRAME_TYPE_REQ, CMD_HOME, 0x00, m_seq, payload);
}

// 指定轴正方向点动，指令：0xAA 06 AXIS NULL
QByteArray Protocol::jogforward(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_JOG_POS, axis, m_seq, QByteArray());
}

// 指定轴负方向点动，指令：0xAA 07 AXIS NULL
QByteArray Protocol::jogbackward(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_JOG_NEG, axis, m_seq, QByteArray());
}

// 指定轴停止点动，指令：0xAA 08 AXIS NULL
QByteArray Protocol::jogstop(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_JOG_STOP, axis, m_seq, QByteArray());
}

// 清除从站错误，指令：0xAA 09 AXIS NULL
QByteArray Protocol::clear_error(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_CLR_SLAVE_ERR, axis, m_seq, QByteArray());
}

// 指定轴绝对运动，指令：0xAA 10 AXIS 04 POS(4B)
QByteArray Protocol::moveabs(uint8_t axis, qint32 position)
{
    return packCommand(FRAME_TYPE_REQ, CMD_MOVE_ABS, axis, m_seq, int32ToBytes(position));
}

// 指定轴相对运动，指令：0xAA 11 AXIS 04 OFFSET(4B)
QByteArray Protocol::moverel(uint8_t axis, qint32 offset)
{
    return packCommand(FRAME_TYPE_REQ, CMD_MOVE_REL, axis, m_seq, int32ToBytes(offset));
}

QByteArray Protocol::movedeg(uint8_t axis, qint32 offset)
{
    return packCommand(FRAME_TYPE_REQ, CMD_MOVE_DEG, axis, m_seq, int32ToBytes(offset));
}

QByteArray Protocol::moverepeat(uint8_t axis, qint32 offset)
{
    return packCommand(FRAME_TYPE_REQ, CMD_MOVE_REPEAT, axis, m_seq, int32ToBytes(offset));
}

// 设置轴速度，指令：0xAA 20 AXIS 02 VEL(2B)
QByteArray Protocol::setvel(uint8_t axis, qint16 vel)
{
    return packCommand(FRAME_TYPE_REQ, CMD_SET_VEL, axis, m_seq, int16ToBytes(vel));
}

// 设置轴加速度，指令：0xAA 21 AXIS 02 ACC(2B)
QByteArray Protocol::setacc(uint8_t axis, qint16 acc)
{
    return packCommand(FRAME_TYPE_REQ, CMD_SET_ACC, axis, m_seq, int16ToBytes(acc));
}

// 设置轴减速度，指令：0xAA 22 AXIS 02 DEC(2B)
QByteArray Protocol::setdec(uint8_t axis, qint16 dec)
{
    return  packCommand(FRAME_TYPE_REQ, CMD_SET_DEC, axis, m_seq, int16ToBytes(dec));
}

// 读取理论位置，指令：0xAA 30 AXIS 00 NULL
QByteArray Protocol::getcmdpos(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_POS, axis, m_seq, QByteArray());
}
// 读取目标位置，指令：0xAA 30 AXIS 00 NULL
QByteArray Protocol::gettargpos(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_POS, axis, m_seq, QByteArray());
}
// 读取实际位置，指令：0xAA 30 AXIS 00 NULL
QByteArray Protocol::getactpos(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_POS, axis, m_seq, QByteArray());
}

QByteArray Protocol::getvel(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_VEL, axis, m_seq, QByteArray());
}

// 读取轴状态，指令：0xAA 32 AXIS 00 NULL
QByteArray Protocol::getstatus(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_STATUS, axis, m_seq, QByteArray());
}

// 读取从站信息
QByteArray Protocol::read_slaveinfo(uint8_t axis)  
{
    return packCommand(FRAME_TYPE_REQ, CMD_READ_SLAVE_INFO, axis, m_seq, QByteArray());
}


QByteArray Protocol::switch_safeop(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_TO_SAFEOP, axis, m_seq, QByteArray());
}

QByteArray Protocol::switch_op(uint8_t axis)
{
    return packCommand(FRAME_TYPE_REQ, CMD_TO_OP, axis, m_seq, QByteArray());
}

QByteArray Protocol::unlinkEcat()
{
    return packCommand(FRAME_TYPE_REQ, CMD_ECAT_UNLINK, 0x00, m_seq, QByteArray());
}

QByteArray Protocol::rescanEcat()
{
    return packCommand(FRAME_TYPE_REQ, CMD_ECAT_RESCAN, 0x00, m_seq, QByteArray());
}

QByteArray Protocol::setDioOutput(uint8_t slave, uint16_t outputMask)
{
    return packCommand(FRAME_TYPE_REQ, CMD_DIO_SET_OUTPUT, slave, m_seq, uint16ToBytes(outputMask));
}

QByteArray Protocol::readDioInput(uint8_t slave)
{
    return packCommand(FRAME_TYPE_REQ, CMD_DIO_READ_INPUT, slave, m_seq, QByteArray());
}


// 32位整数转字节数组（小端序：低字节在前）
QByteArray Protocol::int32ToBytes(qint32 value)
{
    QByteArray bytes;
    bytes.resize(4);

    if (m_littleEndian)
    {
        // 小端序：低位在前
        bytes[0] = static_cast<char>(value & 0xFF);
        bytes[1] = static_cast<char>((value >> 8) & 0xFF);
        bytes[2] = static_cast<char>((value >> 16) & 0xFF);
        bytes[3] = static_cast<char>((value >> 24) & 0xFF);
    }
    else
    {
        // 大端序：高位在前
        bytes[3] = static_cast<char>(value & 0xFF);
        bytes[2] = static_cast<char>((value >> 8) & 0xFF);
        bytes[1] = static_cast<char>((value >> 16) & 0xFF);
        bytes[0] = static_cast<char>((value >> 24) & 0xFF);
    }

    return bytes;
}

// 16位整数转字节数组（小端序：低字节在前）
QByteArray Protocol::int16ToBytes(qint16 value)
{
    QByteArray bytes;
    bytes.resize(2);

    if (m_littleEndian)
    {
        // 小端序
        bytes[0] = static_cast<char>(value & 0xFF);
        bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    }
    else
    {
        // 大端序
        bytes[1] = static_cast<char>(value & 0xFF);
        bytes[0] = static_cast<char>((value >> 8) & 0xFF);
    }

    return bytes;
}

// 无符号16位整数转字节数组（小端序：低字节在前）
QByteArray Protocol::uint16ToBytes(uint16_t value)
{
    QByteArray bytes;
    bytes.resize(2);

    if (m_littleEndian)
    {
        bytes[0] = static_cast<char>(value & 0xFF);
        bytes[1] = static_cast<char>((value >> 8) & 0xFF);
    }
    else
    {
        bytes[1] = static_cast<char>(value & 0xFF);
        bytes[0] = static_cast<char>((value >> 8) & 0xFF);
    }
    return bytes;
}

// 无符号32位整数转字节数组（小端序：低字节在前）
QByteArray Protocol::uint32ToBytes(uint32_t value)
{
    QByteArray bytes;
    bytes.resize(4);

    if (m_littleEndian)
    {
        bytes[0] = static_cast<char>(value & 0xFF);
        bytes[1] = static_cast<char>((value >> 8) & 0xFF);
        bytes[2] = static_cast<char>((value >> 16) & 0xFF);
        bytes[3] = static_cast<char>((value >> 24) & 0xFF);
    }
    else
    {
        bytes[3] = static_cast<char>(value & 0xFF);
        bytes[2] = static_cast<char>((value >> 8) & 0xFF);
        bytes[1] = static_cast<char>((value >> 16) & 0xFF);
        bytes[0] = static_cast<char>((value >> 24) & 0xFF);
    }
    return bytes;
}

