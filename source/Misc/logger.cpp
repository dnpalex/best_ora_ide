#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent), SettingsUser()
{
    QDir logDir(configValue(tr("Log"),tr("folder")).toString());
    if(!logDir.exists() && !logDir.mkdir(logDir.absolutePath())){
        throw tr("Logger. Cannot create a directory:").append(logDir.absolutePath());
    }
    errorLogFile = new QFile(logDir.dirName().append(QDir::separator()).append(configValue(tr("Log"),tr("fileName")).toString()), this);
}

Logger::~Logger()
{
}

void Logger::LogMessage(const QString& text)
{
    if(!errorLogFile->isOpen() && !errorLogFile->open(QIODevice::ReadWrite | QIODevice::Text)){
        throw errorLogFile->errorString();;
    }else{
       QTextStream out(errorLogFile);
       out.seek(errorLogFile->size());
       out << "\r\n" << QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz").append(" ").append(text);
    }

    if(errorLogFile->isOpen()) errorLogFile->close();
}
