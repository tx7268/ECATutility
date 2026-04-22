#ifndef XML_H
#define XML_H


#include <QFile>
#include <QString>
#include <QVector>
#include <QObject>
#include <QVariant>
#include <QXmlStreamReader>



class XML:public QObject
{
    Q_OBJECT
public:
    XML(QObject* parent = nullptr);
    ~XML();

private:
    struct XmlEcatPara
    {
        uint16_t slaveIndex;      // 从站索引
        int8_t home_mode;         // 回零模式
        int32_t vel;              // 速度
        int32_t acc;              // 加速度
        int32_t dec;              // 减速度
        int32_t sw_vel;           // 回零搜索速度
        int32_t zero_vel;         // 回零精确定位速度
        uint8_t op_mode;          // 操作模式（PP/CSP/HOME等）
    };

    struct XmlSubItemInfo
    {
        int subIndex = -1;
        QString name;
        QString typeName;
        QString access;
        int bitSize = 0;
    };

    struct XmlDataTypeInfo
    {
        QString name;
        QString baseType;
        int bitSize = 0;
        QVector<XmlSubItemInfo> subItems;
    };

    struct XmlObjectInfo
    {
        quint16 index = 0;
        int subIndex = -1;
        QString name;
        QString typeName;
        QString access;
        QString pdoMapping;
        int bitSize = 0;
    };

};






















#endif // XML_H
