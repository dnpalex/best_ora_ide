#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    connect(ui->actionConnection_list,&QAction::triggered,[=]() { emit sigShowSubView(ViewType::ConnectionList); });
}

MainView::~MainView()
{
    delete ui;
}

void MainView::AddToolBox(ViewAbstract *tb)
{
    QDockWidget* dock = new QDockWidget(tb->windowTitle(),this);
    if(tb->getViewType() != ViewType::OutPut) {
        dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    }
    else {
        dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    }
    dock->setWidget(tb);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}
