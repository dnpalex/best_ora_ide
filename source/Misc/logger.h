#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QDir>

#include "source/Misc/settingsuser.h"

class Logger : public QObject, public SettingsUser
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0);

signals:

public slots:

    void LogMessage(const QString& text);

private:

    QFile errorLogFile;

};

#endif // LOGGER_H
