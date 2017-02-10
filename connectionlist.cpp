#include "connectionlist.h"
#include "ui_connectionlist.h"

ConnectionList::ConnectionList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionList)
{
    ui->setupUi(this);
}

ConnectionList::~ConnectionList()
{
    delete ui;
}
