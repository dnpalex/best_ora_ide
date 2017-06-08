#include "qtdebug.h"

namespace QtDebug{

void PrintObjectTree(const QObject* obj, QString prefix)
{
    qDebug() << prefix.append(obj->objectName());
    foreach(const QObject* o, obj->children()){
        PrintObjectTree(o, prefix.append("-"));
    }
}


}
