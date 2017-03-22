#ifndef QTXML_H
#define QTXML_H

#include <QVariant>
#include <QIcon>
#include <QDomDocument>

namespace QtXML{

QVariant CreateAttributeValue(const QDomAttr& attr);

QDomElement ElementByNameNTag(const QDomElement& root, const QString& tag, const QString& name);

}

#endif // QTXML_H
