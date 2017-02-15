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
    default:
        break;
    }
}

ViewAbstract* MainPresenter::getSubView(ViewType viewType)
{
    ViewAbstract* subView = nullptr;
    switch (viewType) {
    case ViewType::ConnectionList:
        subView = new ConnectionListView();
        break;
    case ViewType::QueryEditor:
        break;
    case ViewType::OutPut:
        break;
    default:
        break;
    }
    return subView;
}
