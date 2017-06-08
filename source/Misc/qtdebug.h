#ifndef QTDEBUG_H
#define QTDEBUG_H

#include <QObject>
#include <QString>
#include <QDebug>

namespace QtDebug{

void PrintObjectTree(const QObject* obj, QString prefix);

}


#endif // QTDEBUG_H


