#include "connectionlistview.h"
#include "ui_connectionlistview.h"

ConnectionListView::ConnectionListView(ViewType vt, QWidget *parent) :
    ViewAbstract(parent),
    ui(new Ui::ConnectionListView)
{
    ui->setupUi(this);
    setViewType(vt);

    //Read text settings group
    BeginTextGroup(tr("ConnectionList"));

    setWindowTitle(textValue("windowTitle").toString());

    EndTextGroup();
    //End text settings group
}

ConnectionListView::~ConnectionListView()
{
    delete ui;
}

