#include "mainpresenter.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    connect(getMainView().data(),&MainView::sigShowSubView,this,&MainPresenter::ShowSubView);

    connect(getIoadapter().data(),&IOAdapter::LogError,new Logger(getIoadapter().data()),&Logger::LogMessage);
    connect(getIoadapter().data(),&IOAdapter::ModelFinished,this,&MainPresenter::ModelFinished);
}

void MainPresenter::ShowMainView()
{
    getMainView().data()->show();
}

void MainPresenter::ShowSubView(ViewType viewType)
{
    ViewAbstract* subView = getSubView(viewType);
    switch (viewType){
    case ViewType::ConnectionList:{
        getMainView().data()->AddToolBox(subView);
        getIoadapter().data()->RequestModel(viewType);
        break;
    }
    case ViewType::OutPut:
        break;
    case ViewType::QueryEditor:
        break;
    case ViewType::Default:
        break;
    }
}

void MainPresenter::ModelFinished(QAbstractItemModel *model, const ViewType &viewType)
{
    if(model != Q_NULLPTR){
        if(models[viewType] == Q_NULLPTR){
            models[viewType] = model;
            models[viewType]->setParent(this);
        }else{
            models[viewType]->deleteLater();
            models[viewType] = model;
        }
        getSubView(viewType)->setModel(models[viewType]);
    }else{
        if(models[viewType] != Q_NULLPTR) models[viewType]->deleteLater();
        models[viewType] = Q_NULLPTR;
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
            views[viewType] = new ConnectionListView(viewType);
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
            models[viewType] = getIoadapter().data()->ReadFile(tr(":/connections.xml"), IOAdapter::XML);
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
