#ifndef QTXML_H
#define QTXML_H

#include <QVariant>
#include <QIcon>
#include <QDomDocument>
#include <QStandardItemModel>

namespace QtXML{

void ApplyPropertyTree(const QDomElement &root, QObject* obj);
void ApplyPropertyObject(const QDomElement &elem, QObject *obj);
QVariant AttributeToValue(const QDomAttr& attr);

QDomElement ElementByNameNTag(const QDomElement& root, const QString& tag, const QString& name);

QString GetElementName(const QDomElement& elem);

QDomDocument* ModelToDocument(const QStandardItemModel* model, const QString& name);

void ObjectToXml(const QObject* obj, QDomElement& header);

QDomDocument* PropertyTreeToDocument(const QObject* root, const QString& name);

QString ValueToAttribute(QVariant val);
}

#endif // QTXML_H
