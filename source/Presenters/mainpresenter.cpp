#include "mainpresenter.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    connect(getMainView().data(),&MainView::sigShowSubView,this,&MainPresenter::ShowSubView);

    connect(getIoadapter().data(),&IOAdapter::LogError,new Logger(this),&Logger::LogMessage);
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

QScopedPointer<MainView>& MainPresenter::getMainView()
{
    if(mainView.isNull()){
        mainView.reset(new MainView());
    }
    return mainView;
}

QScopedPointer<IOAdapter> &MainPresenter::getIoadapter()
{
    if(ioadapter.isNull()){
        ioadapter.reset(new IOAdapter(this));
    }
    return ioadapter;
}

ViewAbstract *&MainPresenter::getSubView(const ViewType& viewType)
{
    if(!views[viewType]){
        switch (viewType) {
        case ViewType::ConnectionList:
            views[viewType] = new ConnectionListView(viewType,getViewModel(viewType));
            break;
        case ViewType::QueryEditor:
            break;
        case ViewType::OutPut:
            break;
        case ViewType::Default:
            break;
        }
    }
    return views[viewType];
}

QAbstractItemModel*& MainPresenter::getViewModel(const ViewType& viewType)
{
    if(!models[viewType]){
        switch (viewType) {
        case ViewType::ConnectionList:{
            models[viewType] = getIoadapter().data()->readFile(tr(":/connections.xml"), IOAdapter::XML);
            models[viewType]->setParent(this);
            break;
        }
        case ViewType::QueryEditor:
            break;
        case ViewType::OutPut:
            break;
        case ViewType::Default:
            break;
        };
    }
    return models[viewType];
}
