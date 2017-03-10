#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    BeginConfigGroup(tr("Log"));

    QDir logDir(configValue(tr("logFolder")).toString());
    if(!logDir.exists() && !logDir.mkdir(logDir.absolutePath())){
        throw logDir.separator();
    }

    errorLogFile.setFileName(logDir.dirName().append(QDir::separator()).append(configValue(tr("errorFileName")).toString()));

    EndConfigGroup();
}

void Logger::LogMessage(const QString text)
{
    if(!errorLogFile.isOpen() && !errorLogFile.open(QIODevice::ReadWrite | QIODevice::Text)){
        throw errorLogFile.errorString();
    }else{
       QTextStream out(&errorLogFile);
       out.seek(errorLogFile.size());
       out << "\r\n" << QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss.zzz").append(" ").append(text);
    }

    if(errorLogFile.isOpen()) errorLogFile.close();
}
