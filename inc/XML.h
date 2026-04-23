#ifndef XML_H
#define XML_H


#include <QFile>
#include <QHash>
#include <QString>
#include <QVector>
#include <QObject>
#include <QVariant>
#include <QXmlStreamReader>

struct XmlEcatParam
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

// XML子项结构体（存储对象字典子索引信息）
struct XmlSubItemInfo
{
    int subIndex = -1;        // 子索引
    QString name;             // 名称
    QString typeName;         // 数据类型
    QString access;           // 访问权限（ro/rw）
    int bitSize = 0;          // 位宽
};

// XML数据类型结构体（存储自定义数据类型信息）
struct XmlDataTypeInfo
{
    QString name;                     // 类型名称
    QString baseType;                 // 基类型
    int bitSize = 0;                  // 位宽
    QVector<XmlSubItemInfo> subItems; // 子项列表
};

// XML对象信息结构体（存储EtherCAT对象字典核心信息）
struct XmlObjectInfo
{
    quint16 index = 0;        // 对象字典索引（如0x6040）
    int subIndex = -1;        // 子索引
    QString name;             // 对象名称
    QString typeName;         // 数据类型
    QString access;           // 访问权限
    QString pdoMapping;       // PDO映射属性
    int bitSize = 0;          // 位宽
};

class XML:public QObject
{
    Q_OBJECT
public:
    XML(QObject *parent = nullptr);
    ~XML();

    bool readXMLFile(const QString &filepath, QString &errormsg); // 读取并解析XML文件
    void clearXMLData();                                          // 清空解析后的XML数据

    QVector<XmlEcatParam> getEcatParams() const;               // 获取解析后的ECAT参数列表
    XmlEcatParam getSlaveParam(uint16_t slaveIndex = 1) const; // 单从站参数快捷获取（适配现有项目默认从站1）

signals:
    void logMessage(const QString& msg);


private:
    bool m_xmlLoaded = false;                       // XML是否加载完成标志
    QString m_xmlFilePath;                          // 加载的XML文件路径
    QHash<QString, XmlDataTypeInfo> m_xmlDataTypes; // 存储XML数据类型
    QHash<QString, XmlObjectInfo> m_xmlObjectMap;   // 存储对象字典（索引:子索引 -> 对象信息）
    QStringList m_xmlSummaryLines;                  // XML解析摘要信息
    QStringList m_xmlRxPdoLines;                    // RxPDO解析结果
    QStringList m_xmlTxPdoLines;                    // TxPDO解析结果

    QString formatHex(quint32 value, int width) const;                               // 十六进制格式化
    QString makeXmlObjectKey(quint16 index, int subIndex) const;                     // 生成对象唯一键（索引:子索引）

    void parseEcatParamNode(QXmlStreamReader &xml);                                  // 解析ECAT参数节点（核心解析逻辑）

    void parseMotionParamNode(QXmlStreamReader &xml, XmlEcatParam &param);           // 解析运动参数子节点
    void parseHomeParamNode(QXmlStreamReader &xml, XmlEcatParam &param);             // 解析回零参数子节点

    bool lookupXmlObject(quint16 index, quint8 subIndex, XmlObjectInfo &info) const; // 查找对象字典
    void applyXmlHintsToSdo(quint16 index, quint8 subIndex, bool isWrite);           // SDO操作时应用XML提示
    
    QVector<XmlEcatParam> m_ecatParams;                                              // 存储解析后的所有从站参数
};






















#endif // XML_H
