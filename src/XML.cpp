#include "inc/XML.h"
#include <QDateTime>
#include <QMessageBox>
#include <qfileinfo.h>


XML::XML(QObject* parent)
	:QObject{ parent }
{

}

XML::~XML()
{

}

QString XML::xmlFilePath() const
{
	return m_xmlFilePath;
}

QStringList XML::xmlSummaryLines() const
{
	return m_xmlSummaryLines;
}

QStringList XML::xmlRxPdoLines() const
{
	return m_xmlRxPdoLines;
}

QStringList XML::xmlTxPdoLines() const
{
	return m_xmlTxPdoLines;
}

/**
 * @brief获取XML元素标签内的文本内容，并自动去除首尾空白字符。
 */
QString XML::nodeText(QXmlStreamReader& xml)
{
	return xml.readElementText(QXmlStreamReader::SkipChildElements).trimmed();
}

/**
 * @brief 解析EtherCAT设备描述文件中的数字格式
 *
 **/
quint32 XML::parseEtherCatNumber(const QString& raw, bool* ok)
{
	QString text = raw.trimmed(); // 去除输入字符串首尾的空白字符
	bool parsed = false;		  // 用于记录解析是否成功
	quint32 value = 0;			  // 存储解析后的数值

	if (text.startsWith("#x", Qt::CaseInsensitive))
	{
		value = text.mid(2).toUInt(&parsed, 16);
	}
	else if (text.startsWith("0x", Qt::CaseInsensitive))
	{
		value = text.mid(2).toUInt(&parsed, 16);
	}
	else
	{
		value = text.toUInt(&parsed, 10);
	}

	if (ok)
	{
		*ok = parsed;
	}
	return value;
}

/**
 * @brief 安全地获取元素文本，当文本为空时返回预设的默认值，
 **/
QString XML::safeElementText(const QString& text, const QString& fallback)
{
	return text.trimmed().isEmpty() ? fallback : text.trimmed();
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
		.arg(index, 4, 16, QChar('0')) // ???????4λ??????????0
		.arg(subIndex);				   // ??????
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
	if (m_xmlObjectMap.contains(fullkey))
	{
		info = m_xmlObjectMap.value(fullkey);
		return true;
	}
	// 2. 模糊匹配：仅索引（无子索引）
	const QString objectOnlykey = makeXmlObjectKey(index, -1);
	if (m_xmlObjectMap.contains(objectOnlykey))
	{
		info = m_xmlObjectMap.value(objectOnlykey);
		return true;
	}
	return false;
}


/**
 * @brief SDO读写时，应用XML字典提示（日志输出对象信息）
 * @param index 索引
 * @param subIndex 子索引
 * @param isWrite true=写入，false=读取
 */
void XML::applyXmlHintsToSdo(quint16 index, quint8 subIndex, bool isWrite)
{
    if (!m_xmlLoaded)
    {
        return;
    }

    XmlObjectInfo info;
    if (!lookupXmlObject(index, subIndex, info))
    {
        emit logMessage(QString("[XML] 未找到对像 %1:%2")
                            .arg(formatHex(index, 4))
                            .arg(formatHex(subIndex, 2)));
        return;
    }

    const QString action = isWrite ? "写入" : "读取";
    QStringList details;
    details << QString("%1 %2:%3").arg(action, formatHex(index, 4), formatHex(subIndex, 2));
    details << QString("名称=%1").arg(info.name.isEmpty() ? "unnamed object" : info.name);

    if (!info.typeName.isEmpty())
    {
        details << QString("类型=%1").arg(info.typeName);
    }
    if (info.bitSize > 0)
    {
        details << QString("位宽=%1").arg(info.bitSize);
    }
    if (!info.access.isEmpty())
    {
        details << QString("访问=%1").arg(info.access);
    }
    if (!info.pdoMapping.isEmpty())
    {
        details << QString("PDO映射=%1").arg(info.pdoMapping);
    }

    emit logMessage(QString("[XML] %1").arg(details.join("  |  ")));

}


/**
 * @brief 核心：加载并解析EtherCAT从站XML描述文件
 * @param filePath 文件路径
 * @param errorMessage 输出错误信息
 * @return 解析成功true，失败false
 */
bool XML::loadXmlDescription(const QString& filePath, QString& errorMessage)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		errorMessage = QString("XML 文件打开失败: %1").arg(file.errorString());
		emit logMessage(errorMessage);
		return false;
	}

	QXmlStreamReader xml(&file);

	clearXMLData();

	// 临时存储设备信息
	m_xmlFilePath = filePath;
	QString deviceType;
	QString deviceName;
	QString groupType;
	QString productCode;
	QString revisionNo;
	int slaveCountHint = 1;
	bool insideDevice = false;

	while (!xml.atEnd() && !xml.hasError())
	{
		xml.readNext();

		
		if (xml.isEndElement() && xml.name() == QLatin1String("Device"))
		{
			insideDevice = false;
			continue;
		}
		if (!xml.isStartElement()) 
		{
			continue;
		}
		const QString elementName = xml.name().toString();

		if (elementName == QLatin1String("Device"))
		{
			insideDevice = true;
			continue;
		}
		if (!insideDevice)
		{
			continue;
		}

		if (elementName == QLatin1String("Type") && deviceType.isEmpty())
		{
			const auto attrs = xml.attributes();
			if (attrs.hasAttribute("ProductCode"))
			{
				productCode = attrs.value("ProductCode").toString();
			}
			if (attrs.hasAttribute("RevisionNo"))
			{
				revisionNo = attrs.value("RevisionNo").toString();
			}
			deviceType = nodeText(xml);
		}
		else if (elementName == QLatin1String("Name") && deviceName.isEmpty())
		{
			deviceName = nodeText(xml);
		}
		else if (elementName == QLatin1String("GroupType") && groupType.isEmpty())
		{
			groupType = nodeText(xml);
		}

		else if (elementName == QLatin1String("DataType"))
		{
			XmlDataTypeInfo typeInfo;

			while (!(xml.isEndElement() && xml.name() == QLatin1String("DataType")) && !xml.atEnd())
			{
				xml.readNext();
				if (!xml.isStartElement())
				{
					continue;
				}

				const QString typeChild = xml.name().toString();
				if (typeChild == QLatin1String("Name") && typeInfo.name.isEmpty())
				{
					typeInfo.name = nodeText(xml);
				}
				else if (typeChild == QLatin1String("BaseType"))
				{
					typeInfo.baseType = nodeText(xml);
				}
				else if (typeChild == QLatin1String("BitSize"))
				{
					typeInfo.bitSize = nodeText(xml).toInt();
				}
				else if (typeChild == QLatin1String("SubItem"))
				{
					XmlSubItemInfo subItem;
					QString access;

					while (!(xml.isEndElement() && xml.name() == QLatin1String("SubItem")) && !xml.atEnd())
					{
						xml.readNext();
						if (!xml.isStartElement())
						{
							continue;
						}
						const QString subChild = xml.name().toString();
						if (subChild == QLatin1String("SubIdx"))
						{
							subItem.subIndex = nodeText(xml).toInt();
						}
						else if (subChild == QLatin1String("Name"))
						{
							subItem.name = nodeText(xml);
						}
						else if (subChild == QLatin1String("Type"))
						{
							subItem.typeName = nodeText(xml);
						}
						else if (subChild == QLatin1String("BitSize"))
						{
							subItem.bitSize = nodeText(xml).toInt();
						}
						else if (subChild == QLatin1String("Flags"))
						{
							while (!(xml.isEndElement() && xml.name() == QLatin1String("Flags")) && !xml.atEnd())
							{
								xml.readNext();
								if (xml.isStartElement() && xml.name() == QLatin1String("Access"))
								{
									access = nodeText(xml);
								}
							}
						}
					}

					subItem.access = access;
					typeInfo.subItems.append(subItem);
				}
			}
			if (!typeInfo.name.isEmpty())
			{
				m_xmlDataTypes.insert(typeInfo.name, typeInfo);
			}
		}

		else if (elementName == QLatin1String("Object"))
		{
			XmlObjectInfo baseObject;
			QVector<XmlSubItemInfo> infoSubItems;

			while (!(xml.isEndElement() && xml.name() == "Object") && !xml.atEnd())
			{
				xml.readNext();
				if (!xml.isStartElement())
				{
					continue;
				}

				const QString objectChild = xml.name().toString();
				if (objectChild == QLatin1String("Index"))
				{
					baseObject.index = static_cast<quint16>(parseEtherCatNumber(nodeText(xml)));
				}
				else if (objectChild == QLatin1String("Name") && baseObject.name.isEmpty())
				{
					baseObject.name = nodeText(xml);
				}
				else if (objectChild == QLatin1String("Type"))
				{
					baseObject.typeName = nodeText(xml);
				}
				else if (objectChild == QLatin1String("BitSize"))
				{
					baseObject.bitSize = nodeText(xml).toInt();
				}
				else if (objectChild == QLatin1String("Info"))
				{
					while (!(xml.isEndElement() && xml.name() == QLatin1String("Info")) && !xml.atEnd())
					{
						xml.readNext();
						if (!xml.isStartElement() || xml.name() != QLatin1String("SubItem"))
						{
							continue;
						}

						XmlSubItemInfo subItem;
						while (!(xml.isEndElement() && xml.name() == QLatin1String("SubItem")) && !xml.atEnd())
						{
							xml.readNext();
							if (!xml.isStartElement())
							{
								continue;
							}

							const QString subChild = xml.name().toString();
							if (subChild == QLatin1String("Name"))
							{
								subItem.name = nodeText(xml);
							}
						}

						infoSubItems.append(subItem);
					}
				}
				else if (objectChild == QLatin1String("Flags"))
				{
					while (!(xml.isEndElement() && xml.name() == QLatin1String("Flags")) && !xml.atEnd())
					{
						xml.readNext();
						if (!xml.isStartElement())
						{
							continue;
						}

						if (xml.name() == QLatin1String("Access"))
						{
							baseObject.access = nodeText(xml);
						}
						else if (xml.name() == QLatin1String("PdoMapping"))
						{
							baseObject.pdoMapping = nodeText(xml);
						}
					}
				}
			}

			if (baseObject.index == 0)
			{
				continue;
			}
			m_xmlObjectMap.insert(makeXmlObjectKey(baseObject.index, -1), baseObject);

			const auto typeIt = m_xmlDataTypes.constFind(baseObject.typeName);
			if (typeIt != m_xmlDataTypes.constEnd() && !typeIt->subItems.isEmpty())
			{
				for (int i = 0; i < typeIt->subItems.size(); ++i)
				{
					XmlObjectInfo subObject = baseObject;
					const XmlSubItemInfo& typeSub = typeIt->subItems.at(i);

					subObject.subIndex = typeSub.subIndex;
					if (i < infoSubItems.size() && !infoSubItems.at(i).name.isEmpty())
					{
						subObject.name = infoSubItems.at(i).name;
					}
					else if (!typeSub.name.isEmpty())
					{
						subObject.name = typeSub.name;
					}

					if (!typeSub.typeName.isEmpty())
					{
						subObject.typeName = typeSub.typeName;
					}
					if (typeSub.bitSize > 0)
					{
						subObject.bitSize = typeSub.bitSize;
					}
					if (!typeSub.access.isEmpty())
					{
						subObject.access = typeSub.access;
					}

					m_xmlObjectMap.insert(makeXmlObjectKey(baseObject.index, subObject.subIndex), subObject);
				}
			}
		}
		else if (elementName == QLatin1String("RxPdo") || elementName == QLatin1String("TxPdo"))
		{
			const bool isRx = elementName == QLatin1String("RxPdo");
			const auto attrs = xml.attributes();
			QString pdoIndex;
			QStringList entries;

			while (!(xml.isEndElement() && xml.name().toString() == elementName) && !xml.atEnd())
			{
				xml.readNext();
				if (!xml.isStartElement())
				{
					continue;
				}

				if (xml.name() == QLatin1String("Index") && pdoIndex.isEmpty())
				{
					pdoIndex = nodeText(xml);
				}
				else if (xml.name() == QLatin1String("Entry"))
				{
					QString entryIndex;
					QString entrySub;
					QString entryBits;

					while (!(xml.isEndElement() && xml.name() == QLatin1String("Entry")) && !xml.atEnd())
					{
						xml.readNext();
						if (!xml.isStartElement())
						{
							continue;
						}

						if (xml.name() == QLatin1String("Index"))
						{
							entryIndex = nodeText(xml);
						}
						else if (xml.name() == QLatin1String("SubIndex"))
						{
							entrySub = nodeText(xml);
						}
						else if (xml.name() == QLatin1String("BitLen"))
						{
							entryBits = nodeText(xml);
						}
					}

					bool okIndex = false;
					bool okSub = false;
					const quint16 indexValue = static_cast<quint16>(parseEtherCatNumber(entryIndex, &okIndex));
					const quint8 subValue = static_cast<quint8>(parseEtherCatNumber(entrySub, &okSub));

					XmlObjectInfo xmlObject;
					QString objectName;
					if (okIndex && okSub && lookupXmlObject(indexValue, subValue, xmlObject))
					{
						objectName = xmlObject.name;
					}

					QString entryText = QString("%1:%2")
						.arg(entryIndex.isEmpty() ? "-" : entryIndex)
						.arg(entrySub.isEmpty() ? "-" : entrySub);

					if (!objectName.isEmpty())
					{
						entryText += QString(" → %1").arg(objectName);
					}
					if (!entryBits.isEmpty())
					{
						entryText += QString(" [%1bit]").arg(entryBits);
					}

					entries.append(entryText);
				}
			}

			QString line = QString("%1  [索引: %2]  %3")
				.arg(isRx ? "RxPDO" : "TxPDO")
				.arg(pdoIndex.isEmpty() ? "-" : pdoIndex)
				.arg(entries.join(" | "));

			if (attrs.hasAttribute("Sm"))
			{
				line += QString(" | SM=%1").arg(attrs.value("Sm").toString());
			}

			if (isRx)
			{
				m_xmlRxPdoLines.append(line);
			}
			else
			{
				m_xmlTxPdoLines.append(line);
			}
		}
	}

	if (xml.hasError())
	{
        errorMessage = QString("XML 解析失败: 第%1行, 第%2列, %3")
            .arg(xml.lineNumber()).arg(xml.columnNumber()).arg(xml.errorString());
		clearXMLData();
        return false;
	}

	m_xmlLoaded = true;

	m_xmlSummaryLines << "==================================================";
	m_xmlSummaryLines << QString("XML 解析完成 | 文件: %1").arg(QFileInfo(filePath).fileName());
	m_xmlSummaryLines << QString("设备名称:      %1").arg(safeElementText(deviceName, "未读取到"));
	m_xmlSummaryLines << QString("设备型号:      %1").arg(safeElementText(deviceType, "未读取到"));
	m_xmlSummaryLines << QString("分组类型:      %1").arg(safeElementText(groupType, "未读取到"));
	m_xmlSummaryLines << QString("产品编码:      %1").arg(productCode.isEmpty() ? "未读取到" : productCode);
	m_xmlSummaryLines << QString("固件版本:      %1").arg(revisionNo.isEmpty() ? "未读取到" : revisionNo);
	m_xmlSummaryLines << "--------------------------------------------------";
	m_xmlSummaryLines << QString("对象字典总数:  %1 个").arg(m_xmlObjectMap.size());
	m_xmlSummaryLines << QString("RxPDO 总数:    %1 组").arg(m_xmlRxPdoLines.size());
	m_xmlSummaryLines << QString("TxPDO 总数:    %1 组").arg(m_xmlTxPdoLines.size());
	m_xmlSummaryLines << QString("从站下拉已按 XML 刷新，当前数量: %1").arg(slaveCountHint);
	return true;
}

void XML::clearXMLData()
{
	m_ecatParams.clear();

	m_xmlLoaded = false;
	m_xmlFilePath.clear();
	m_xmlDataTypes.clear();
	m_xmlObjectMap.clear();
	m_xmlSummaryLines.clear();
	m_xmlRxPdoLines.clear();
	m_xmlTxPdoLines.clear();
    emit logMessage("[XML] 已清空所有XML解析数据");
}

QVector<XmlEcatParam> XML::getEcatParams() const
{
	return m_ecatParams;
}

XmlEcatParam XML::getSlaveParam(uint16_t slaveIndex) const
{
	for (const XmlEcatParam& param : m_ecatParams)
	{
		if (param.slaveIndex == slaveIndex)
		{
			return param;
		}
	}

	XmlEcatParam param{};
	param.slaveIndex = slaveIndex;
	return param;
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
