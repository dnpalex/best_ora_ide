#include "viewabstract.h"

ViewAbstract::ViewAbstract(QWidget* parent) : QWidget(parent)
{
}

ViewAbstract::~ViewAbstract()
{

}

ViewAbstract::ViewType ViewAbstract::getViewType() const
{
    return viewType;
}

QString ViewAbstract::getViewTypeStr() const
{
    return QMetaEnum::fromType<ViewAbstract::ViewType>().valueToKey(viewType);
}

void ViewAbstract::setViewType(const ViewAbstract::ViewType& vt)
{
    viewType = vt;
}

void ViewAbstract::ApplyForElement(const QDomElement &elem, QObject *obj)
{
    QString nme = QtXML::GetElementName(elem);
    auto o = obj == Q_NULLPTR ? this->findChild<QObject*>(nme) : obj;
    if(o != Q_NULLPTR){
        QDomNamedNodeMap attrList = elem.attributes();
        QDomAttr attr;
        QString n = o->property("objectName").toString();
        for(int i = 0; i < attrList.count(); i++){
            attr = attrList.item(i).toAttr();
            if(o != Q_NULLPTR)
                o->setProperty(attr.name().toStdString().c_str(),attr.value());
        }
    }
}

void ViewAbstract::ApplySettings(const QDomElement &root)
{
    ApplyForElement(root,this);
    QDomNodeList list = root.childNodes();
    for(int i = 0; i < list.count(); i++){
        if(list.item(i).isElement()){
            ApplySettings(list.item(i).toElement());
        }
        else{
            continue;
        }
    }
//    foreach (auto w, findChildren<QToolBar*>()) {
//        qDebug() << w->property("objectName").toString();
//    }
}
