#ifndef IOADAPTER_H
#define IOADAPTER_H

#include <QObject>
#include <QStandardItemModel>
#include <QFile>

#include "source/Misc/logableobject.h"

class IOAdapter : public QObject, public LogableObject
{
    Q_OBJECT
public:
    enum FileType {XML, JSON};

    explicit IOAdapter(QObject *parent = 0);

    QStandardItemModel* readFile(const QString& fileName, const FileType& fileType);

signals:

    virtual void LogError(const QString& message);

public slots:
};

#endif // IOADAPTER_H
