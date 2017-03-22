#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    connect(ui->actionConnection_list,&QAction::triggered,[=]() {
        auto view = ifViewAvailable(ViewAbstract::ConnectionList);
        if(view  == nullptr){
            emit ShowSubView(ViewAbstract::ConnectionList);
        }else{
            view->parentWidget()->showNormal();
        }
    });   
}

MainView::~MainView()
{
    delete ui;
    emit this->destroyed();
}

void MainView::AddToolBox(ViewAbstract *tb)
{
    QDockWidget* dock = new QDockWidget(tb->windowTitle(),this);
    if(tb->getViewType() != ViewAbstract::OutPut) {
        dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    }
    else {
        dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    }
    //dock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    dock->setWidget(tb);
    tb->setParent(dock);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

ViewAbstract* MainView::ifViewAvailable(const ViewAbstract::ViewType& vt)
{
    ViewAbstract* va = Q_NULLPTR;
    foreach(auto c, findChildren<ViewAbstract*>()){
        if(c->getViewType() == vt){
            va = c;
            break;
        }
    }
    return va;
}

void MainView::closeEvent(QCloseEvent *event)
{
    emit Close(event);
}
