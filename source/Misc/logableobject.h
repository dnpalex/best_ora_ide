#ifndef LOGABLEOBJECT_H
#define LOGABLEOBJECT_H

#include <QString>

class LogableObject
{
public:
    explicit LogableObject();
    virtual ~LogableObject();

    virtual void LogError(QString errorString) = 0;
};

#endif // LOGABLEOBJECT_H
