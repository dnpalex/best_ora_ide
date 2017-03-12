#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <QObject>
#include <QStandardItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>

#include "source/Misc/logableobject.h"

class IOAdapter : public QObject, public LogableObject
{
    Q_OBJECT
public:
    enum FileType {XML, JSON};

    explicit IOAdapter(QObject *parent = 0);

    QStandardItemModel* readFile(const QString& fileName, const FileType& fileType);

signals:

    void LogError(const QString& message);

protected:

    void recursiveRead(const QDomElement& parElem, QStandardItem &parItem);
    QVariant createAttributeValue(const QString& name, const QString& value);
};

#endif // IOADAPTER_H
