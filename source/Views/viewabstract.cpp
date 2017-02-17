#include "viewabstract.h"

ViewAbstract::ViewAbstract(QWidget* parent) : QWidget(parent), SettingsUser()
{
}

ViewAbstract::~ViewAbstract()
{

}

ViewType ViewAbstract::getViewType()
{
    return viewType;
}

void ViewAbstract::setViewType(ViewType vt)
{
    viewType = vt;
}
