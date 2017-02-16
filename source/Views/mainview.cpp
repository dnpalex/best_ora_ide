#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    connect(ui->actionConnection_list,&QAction::triggered,[=]() {
        auto view = ifViewAvailable(ViewType::ConnectionList);
        if(view  == nullptr){
            emit sigShowSubView(ViewType::ConnectionList);
        }else{
            view->parentWidget()->showNormal();
        }
    });
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
    //dock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    dock->setWidget(tb);
    tb->setParent(dock);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

ViewAbstract* MainView::ifViewAvailable(ViewType vt)
{
    ViewAbstract* va = nullptr;
    foreach(auto c, findChildren<ViewAbstract*>()){
        if(c->getViewType() == vt){
            va = c;
            break;
        }
    }
    return va;
}
