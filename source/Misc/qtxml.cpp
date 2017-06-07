#include "Misc/qtxml.h"

namespace QtXML{

void ApplyPropertyObject(const QDomElement &elem, QObject *obj)
{
    if(obj != Q_NULLPTR){
        QDomNamedNodeMap attrList = elem.attributes();
        QDomAttr attr;
        for(int i = 0; i < attrList.count(); i++){
            attr = attrList.item(i).toAttr();
            obj->setProperty(attr.name().toStdString().c_str(),AttributeToValue(attr));
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

QVariant AttributeToValue(const QDomAttr& attr){
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

QString ValueToAttribute(QVariant val)
{
    QString attr;
    if(QString(val.typeName()).contains("icon",Qt::CaseInsensitive)){
        attr = val.value<QIcon>().name();
    }else{
        attr = val.toString();
    }
    return attr;
}

QDomDocument *PropertyTreeToDocument(const QObject *root, const QString& name)
{
    QDomDocument* doc = new QDomDocument(name);
    QDomElement treeRoot = doc->createElement("tree");
    doc->appendChild(treeRoot);
    //ObjectToXml(root, treeRoot, doc);
    return doc;
}

QDomDocument *ModelToDocument(const QStandardItemModel *model, const QString& name)
{
    QDomDocument* doc = new QDomDocument(name);
    if(model != Q_NULLPTR && model->invisibleRootItem()->hasChildren()){
        QDomElement root = doc->createElement("tree");
        doc->appendChild(root);
    }
    return doc;
}

void ObjectToXml(const QObject* obj, QDomElement& header)
{
    if(obj != Q_NULLPTR){
        QDomElement el = header.ownerDocument().createElement(obj->metaObject()->className());
        QList<const char*> propList = {"name", "height", "width","x","y","maximized","fullScreen"};
        foreach (auto c, propList) {
            el.setAttribute(c,ValueToAttribute(obj->property(c)));
        }
        header.appendChild(el);
        foreach (auto child, obj->children()) {
            ObjectToXml(child, el);
        }
    }
}


}
