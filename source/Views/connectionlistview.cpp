#include "connectionlistview.h"
#include "ui_connectionlistview.h"

ConnectionListView::ConnectionListView(ViewType vt, QAbstractItemModel *model, QWidget *parent) :
    ViewAbstract(parent),
    ui(new Ui::ConnectionListView)
{
    ui->setupUi(this);
    setViewType(vt);

    //Setup toolbar
    toolBar = new QToolBar(this);
    toolBar->setObjectName(tr("toolBar"));
    QAction* act = new QAction(toolBar);
    act->setObjectName(tr("addConnection"));
    connect(act, &QAction::triggered, this, &ConnectionListView::AddConnection);
    toolBar->addAction(act);

    act = new QAction(toolBar);
    act->setObjectName(tr("removeConnection"));
    connect(act, &QAction::triggered, this, &ConnectionListView::RemoveConnection);
    toolBar->addAction(act);

    ui->layToolBar->addWidget(toolBar);

#ifdef QT_DEBUG
    //QtDebug::PrintObjectTree(this,"-");
#endif
    //end toolbar

    setModel(model);
}

ConnectionListView::~ConnectionListView()
{
    delete ui;
}

void ConnectionListView::setModel(QAbstractItemModel *model)
{
    ui->treeView->setModel(model);
}

void ConnectionListView::AddConnection()
{
}

void ConnectionListView::RemoveConnection()
{

}

