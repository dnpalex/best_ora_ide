#ifndef QTXML_H
#define QTXML_H

#include <QVariant>
#include <QIcon>
#include <QDomDocument>

namespace QtXML{

void ApplyPropertyTree(const QDomElement &root, QObject* obj);
void ApplyPropertyObject(const QDomElement &elem, QObject *obj);

QVariant CreateAttributeValue(const QDomAttr& attr);

QDomElement ElementByNameNTag(const QDomElement& root, const QString& tag, const QString& name);

QString GetElementName(const QDomElement& elem);

}

#endif // QTXML_H
