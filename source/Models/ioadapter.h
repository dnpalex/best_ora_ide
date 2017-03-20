#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <QObject>
#include <QStandardItemModel>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QThread>
#include <QDir>
#include <QThread>

#include "source/Misc/logableobject.h"
#include "source/Models/adapterabstract.h"

class IOAdapter : public QThread, public LogableObject, public AdapterAbstract, public SettingsUser
{
    Q_OBJECT
public:
    enum FileType {XML, JSON, UNKNOWN};

    explicit IOAdapter(QObject *parent = 0);

    void RequestModel(const ViewType& viewType) Q_DECL_OVERRIDE;

    QStandardItemModel* ReadFile(const QString& fileName, const FileType& fileType);

    QDomDocument* ReadGlobSettings(bool refresh = false);

    virtual void run() Q_DECL_OVERRIDE;

signals:

    void LogError(const QString& message) Q_DECL_OVERRIDE;

    void ModelFinished(QAbstractItemModel* model, const ViewType& viewType) Q_DECL_OVERRIDE;

protected:

    QDomDocument globalSettings;

    void RecursiveRead(const QDomElement& parElem, QStandardItem& parItem);
    QVariant CreateAttributeValue(const QString& name, const QString& value);
    IOAdapter::FileType InterpretFileType(const QString& ftName);
    QDomDocument* ReadXmlFile(const QString& fileName, QDomDocument* doc = Q_NULLPTR);
    QDir AcquireDir(const QString& configGroup);
};

#endif // IOADAPTER_H
