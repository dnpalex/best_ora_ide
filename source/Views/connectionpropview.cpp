#include "connectionpropview.h"
#include "ui_connectionpropview.h"

ConnectionPropView::ConnectionPropView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionPropView)
{
    ui->setupUi(this);
}

ConnectionPropView::~ConnectionPropView()
{
    delete ui;
}
