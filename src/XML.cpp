#include "inc/XML.h"
#include <QDateTime>
#include <QMessageBox>


XML::XML(QObject* parent)
	:QObject{ parent }
{

}

XML::~XML()
{

}

/**
 * @brief 生成XML对象唯一键：索引:子索引
 * @param index 对象字典索引
 * @param subIndex 子索引（-1代表仅索引）
 * @return 格式化字符串（006040:00）
 */
QString XML::makeXmlObjectKey(quint16 index, int subIndex) const
{
	return QString("%1:%2")
		.arg(index, 4, 16, QChar('0'))  // 索引固定4位十六进制，补0
		.arg(subIndex);                // 子索引
}

/**
 * @brief 数值格式化为十六进制字符串
 * @param value 原始值
 * @param width 宽度
 * @return 0xXXXX格式大写字符串
 */
QString XML::formatHex(quint32 value, int width) const
{
	return QString("0x%1").arg(value, width, 16, QChar('0')).toUpper();

}


/**
 * @brief 根据索引+子索引查找XML对象字典
 * @param index 对象索引
 * @param subIndex 子索引
 * @param info 输出查找到的对象信息
 * @return 找到返回true，否则false
 */
bool XML::lookupXmlObject(quint16 index, quint8 subIndex, XmlObjectInfo& info) const
{
	// 1. 精确匹配：索引+子索引
	const QString fullkey = makeXmlObjectKey(index, subIndex);
}


bool XML::readXMLFile(const QString &filePath, QString &errorMsg)
{
	QFile file(filePath);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		errorMsg = QString("XML文件打开失败 ：%1").arg(file.errorString());
		emit logMessage(errorMsg);
		return false;
	}

	QXmlStreamReader xml(&file);
	clearXMLData();

	while (!xml.atEnd() && !xml.hasError())
	{
		QXmlStreamReader::TokenType token = xml.readNext();
		if (token == QXmlStreamReader::StartDocument)
		{
			emit logMessage(QString("开始解析XML文件：%1").arg(filePath));
			continue;
		}

		// todo
		/*匹配根节点（示例根节点：<ECATConfig>）
		if (token == QXmlStreamReader::StartElement && xml.name() == "ECATConfig") {
			parseEcatParamNode(xml);
		}
		*/

		if (xml.hasError())
		{
			errorMsg = QString("XML解析错误：%1（行号：%2）").arg(xml.errorString()).arg(xml.lineNumber());
			emit logMessage(errorMsg);
			file.close();
			return false;
		}

		file.close();
		emit logMessage(QString("XML文件解析完成，共解析%1个从站参数").arg(m_ecatParams.size()));
		return true;
	}
}

void XML::clearXMLData()
{
	m_ecatParams.clear();

	/*todo
	更多参数待清除

	*/

	emit logMessage("已清空XML解析缓存数据");
}

QVector<XmlEcatParam> XML::getEcatParams() const
{
	return m_ecatParams;
}

XmlEcatParam XML::getSlaveParam(uint16_t slaveIndex) const
{

}

void XML::parseEcatParamNode(QXmlStreamReader& xml)
{

}

void XML::parseMotionParamNode(QXmlStreamReader& xml, XmlEcatParam& param)
{

}


void XML::parseHomeParamNode(QXmlStreamReader& xml, XmlEcatParam& param)
{

}