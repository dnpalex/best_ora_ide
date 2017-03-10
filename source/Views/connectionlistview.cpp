#include "connectionlistview.h"
#include "ui_connectionlistview.h"

ConnectionListView::ConnectionListView(ViewType vt, QAbstractItemModel* model, QWidget *parent) :
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

    //Setup toolbar
    toolBar.reset(new QToolBar(this));
    QAction *act = new QAction(QIcon(tr(":/database_add.png")),"",toolBar.data());
    connect(act, &QAction::triggered, this, &ConnectionListView::AddConnection);
    toolBar->addAction(act);

    act = new QAction(QIcon(tr(":/database_remove.png")),"",toolBar.data());
    connect(act, &QAction::triggered, this, &ConnectionListView::RemoveConnection);
    toolBar->addAction(act);

    ui->layToolBar->addWidget(toolBar.data());
    //end toolbar

    setConnectionsModel(model);
}

ConnectionListView::~ConnectionListView()
{
    delete ui;
}

void ConnectionListView::setConnectionsModel(QAbstractItemModel *model)
{
    ui->treeView->setModel(model);
}

void ConnectionListView::AddConnection()
{

}

void ConnectionListView::RemoveConnection()
{

}

