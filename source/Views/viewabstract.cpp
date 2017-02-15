#include "viewabstract.h"

ViewAbstract::ViewAbstract(QWidget* parent) : QWidget(parent)
{
    viewType = ViewType::Default;
}

ViewAbstract::ViewAbstract(ViewType vt, QWidget* parent) : QWidget(parent)
{
    viewType = vt;
}

ViewAbstract::~ViewAbstract()
{

}

ViewType ViewAbstract::getViewType()
{
    return viewType;
}
