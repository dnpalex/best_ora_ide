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


