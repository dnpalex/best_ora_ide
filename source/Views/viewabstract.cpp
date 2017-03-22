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

void ViewAbstract::ApplySettings(const QDomElement &root)
{
    QDomNamedNodeMap attrList = root.attributes();
    QDomAttr attr;
    for(int i = 0; i < attrList.count(); i++){
        attr = attrList.item(i).toAttr();
        this->setProperty(attr.name().toStdString().c_str(),attr.value());
    }
}
