#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <QObject>
#include <QStandardItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QEventLoop>
#include <QDir>
#include <QThread>

#include "source/Misc/logableobject.h"
#include "source/Models/adapterabstract.h"

class IOAdapter : public QEventLoop, public LogableObject, public AdapterAbstract, public SettingsUser
{
    Q_OBJECT
public:
    enum FileType {XML, JSON, UNKNOWN};

    explicit IOAdapter(QObject *parent = 0);

    void RequestModel(const ViewType& viewType);

    QStandardItemModel* ReadFile(const QString& fileName, const FileType& fileType);
    QDomDocument* ReadGlobSettings(bool refresh = false);

    virtual void exec();

signals:

    void LogError(const QString& message);

    void ModelFinished(QAbstractItemModel* model, const ViewType& viewType);

protected:

    QDir configDir;
    QDomDocument globalSettings;

    void RecursiveRead(const QDomElement& parElem, QStandardItem& parItem);
    QVariant CreateAttributeValue(const QString& name, const QString& value);
    IOAdapter::FileType InterpretFileType(const QString& ftName);
    QDomDocument* readXmlFile(const QString& fileName, QDomDocument* doc = Q_NULLPTR);
};

#endif // IOADAPTER_H
