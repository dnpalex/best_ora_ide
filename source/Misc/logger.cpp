#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{
    BeginConfigGroup(tr("Log"));

    errorLogFile.setFileName(configValue(tr("/logFolder/")).toString().append(configValue(tr("errorFileName")).toString()));

    EndConfigGroup();
}

void Logger::LogMessage(const QString text)
{
    if(!errorLogFile.isOpen() && !errorLogFile.open(QIODevice::ReadWrite | QIODevice::Text)){
        throw errorLogFile.errorString();
    }else{
       QTextStream out(&errorLogFile);
       out << QDate::currentDate().toString().append(" ").append(text);
    }

    if(errorLogFile.isOpen()) errorLogFile.close();
}
