#include "viewabstract.h"

ViewAbstract::ViewAbstract(QWidget* parent) : QWidget(parent), SettingsUser()
{
    qRegisterMetaType<ViewType>("ViewType");
}

ViewAbstract::~ViewAbstract()
{

}

ViewType ViewAbstract::getViewType()
{
    return viewType;
}

void ViewAbstract::setViewType(const ViewType& vt)
{
    viewType = vt;
}
