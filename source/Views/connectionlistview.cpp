#include "connectionlistview.h"
#include "ui_connectionlistview.h"

ConnectionListView::ConnectionListView(QWidget *parent) :
    ViewAbstract(parent),
    ui(new Ui::ConnectionListView)
{
    ui->setupUi(this);
}

ConnectionListView::~ConnectionListView()
{
    delete ui;
}

