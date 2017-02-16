#include "connectionlistview.h"
#include "ui_connectionlistview.h"

ConnectionListView::ConnectionListView(QWidget *parent) :
    ViewAbstract(parent),
    ui(new Ui::ConnectionListView)
{
    ui->setupUi(this);
}

ConnectionListView::ConnectionListView(ViewType vt, QString windowName, QWidget *parent) :
    ViewAbstract(vt, windowName, parent),
    ui(new Ui::ConnectionListView)
{
    ui->setupUi(this);
    this->setWindowTitle(windowName);
}

ConnectionListView::~ConnectionListView()
{
    delete ui;
}

