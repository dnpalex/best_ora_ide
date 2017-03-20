#include "mainpresenter.h"

MainPresenter::MainPresenter(int& argc,char**argv,int appflags) : QApplication(argc,argv,appflags), SettingsUser()
{
    logger = new Logger(this);

    mainView = new MainView();
    connect(mainView,&MainView::ShowSubView,this,&MainPresenter::ShowSubView);
    connect(mainView,&MainView::Close,this,&MainPresenter::MainViewClosed);

    ioAdapter = new IOAdapter();
    locale = ioAdapter->ReadGlobSettings(true);
    connect(ioAdapter,&IOAdapter::LogError,logger,&Logger::LogMessage);
    connect(ioAdapter,&IOAdapter::ModelFinished,this,&MainPresenter::ModelFinished);
    connect(ioAdapter,&QThread::finished, ioAdapter, &QObject::deleteLater);
    connect(this, &MainPresenter::RequestModel, ioAdapter,&IOAdapter::RequestModel);

    ioAdapter->start();
}

MainPresenter::~MainPresenter()
{
    ioAdapter->quit();
}

int MainPresenter::exec()
{
    mainView->show();
    return this->QApplication::exec();
}

void MainPresenter::ShowSubView(const ViewType& viewType)
{
    ViewAbstract* subView = getSubView(viewType);
    switch (viewType){
    case ViewType::ConnectionList:{
        mainView->AddToolBox(subView);
        emit RequestModel(viewType);
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

void MainPresenter::MainViewClosed(QCloseEvent *event)
{
    delete mainView;
    this->quit();
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
    return models[viewType];
}
