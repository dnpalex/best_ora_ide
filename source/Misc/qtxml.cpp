#include "source/Misc/qtxml.h"

namespace QtXML{
QVariant CreateAttributeValue(const QDomAttr& attr){
    QVariant val;
    if(attr.name()=="icon"){
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

QString GetElementName(const QDomElement &elem)
{
    QString nme;
    QDomNamedNodeMap map = elem.attributes();
    for (int i =0; i < map.count(); i++) {
        if(map.item(i).toAttr().name() == "name"){
            nme = map.item(i).toAttr().value();
            break;
        }
    }
    return nme;
}

}
