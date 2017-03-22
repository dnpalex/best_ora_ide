#include "source/Misc/qtxml.h"

namespace QtXML{
QVariant CreateAttributeValue(const QDomAttr& attr){
    QVariant val;
    if(attr.name()=="ico"){
        val = QIcon(attr.value());
    }else{
        val = attr.value();
    }
    return val;
}

QDomElement ElementByNameNTag(const QDomElement& root, const QString& tag, const QString& name){
    QDomNodeList lst = root.elementsByTagName(tag);
    for(int i = 0; i < lst.count(); i++){
        if(lst.item(i).attributes().namedItem("name").toAttr().value() == name){
            return lst.item(i).toElement();
        }
    }
    return root;
}

}
