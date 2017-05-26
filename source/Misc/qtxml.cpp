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

void ApplyPropertyObject(const QDomElement &elem, QObject *obj)
{
    if(obj != Q_NULLPTR){
        QDomNamedNodeMap attrList = elem.attributes();
        QDomAttr attr;
        for(int i = 0; i < attrList.count(); i++){
            attr = attrList.item(i).toAttr();
            obj->setProperty(attr.name().toStdString().c_str(),CreateAttributeValue(attr));
        }
    }
}

void ApplyPropertyTree(const QDomElement &root, QObject* obj)
{
    ApplyPropertyObject(root,obj);
    QDomNodeList list = root.childNodes();
    for(int i = 0; i < list.count(); i++){
        if(list.item(i).isElement()){
            QString nme = QtXML::GetElementName(list.item(i).toElement());
            ApplyPropertyTree(list.item(i).toElement(), obj->findChild<QObject*>(nme,Qt::FindChildrenRecursively));
        }
        else{
            continue;
        }
    }
}

}
