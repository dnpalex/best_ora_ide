#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <QObject>
#include <QStandardItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>

#include "source/Misc/logableobject.h"
#include "source/Models/adapterabstract.h"

class IOAdapter : public QObject, public LogableObject, public AdapterAbstract
{
    Q_OBJECT
public:
    enum FileType {XML, JSON};

    explicit IOAdapter(QObject *parent = 0);

    void RequestModel(const ViewType& viewType);

    QStandardItemModel* ReadFile(const QString& fileName, const FileType& fileType);
signals:

    void LogError(const QString& message);

    void ModelFinished(QAbstractItemModel* model, const ViewType& viewType);

protected:

    void RecursiveRead(const QDomElement& parElem, QStandardItem &parItem);
    QVariant CreateAttributeValue(const QString& name, const QString& value);
};

#endif // IOADAPTER_H
