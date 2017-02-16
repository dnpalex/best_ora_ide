#include "viewabstract.h"

ViewAbstract::ViewAbstract(QWidget* parent) : QWidget(parent)
{
    viewType = ViewType::Default;
}

ViewAbstract::ViewAbstract(ViewType vt, QString windowName, QWidget* parent) : QWidget(parent)
{
    viewType = vt;
    this->setWindowTitle(windowName);
}

ViewAbstract::~ViewAbstract()
{

}

ViewType ViewAbstract::getViewType()
{
    return viewType;
}
