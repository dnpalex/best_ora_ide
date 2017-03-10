#include "mainpresenter.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    mainView.reset(new MainView());
    connect(mainView.data(),&MainView::sigShowSubView,this,&MainPresenter::ShowSubView);
}

void MainPresenter::ShowMainView()
{
    mainView->show();
}

void MainPresenter::ShowSubView(ViewType viewType)
{
    ViewAbstract* subView = getSubView(viewType);
    switch (viewType){
    case ViewType::ConnectionList:
        mainView->AddToolBox(subView);
        break;
    case ViewType::OutPut:
        break;
    case ViewType::QueryEditor:
        break;
    case ViewType::Default:
        break;
    }
}

ViewAbstract* MainPresenter::getSubView(ViewType viewType)
{
    ViewAbstract* subView = nullptr;
    switch (viewType) {
    case ViewType::ConnectionList:
        subView = new ConnectionListView(ViewType::ConnectionList, getViewModel(viewType));
        break;
    case ViewType::QueryEditor:
        break;
    case ViewType::OutPut:
        break;
    case ViewType::Default:
        break;
    }
    return subView;
}

QAbstractItemModel *MainPresenter::getViewModel(ViewType viewType, ViewAbstract* view)
{
    QAbstractItemModel* model = nullptr;
    switch (viewType) {
    case ViewType::ConnectionList:
        model = new TreeModel(new Logger(), tr(":/connections.xml"), FileType::XML,view);
        break;
    case ViewType::QueryEditor:
        break;
    case ViewType::OutPut:
        break;
    case ViewType::Default:
        break;
    }
    return model;
}
