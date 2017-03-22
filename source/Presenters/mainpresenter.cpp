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

void MainPresenter::ShowSubView(const ViewAbstract::ViewType& viewType)
{
    ViewAbstract* subView = getSubView(viewType);
    switch (viewType){
    case ViewAbstract::ConnectionList:{
        mainView->AddToolBox(subView);
        emit RequestModel(viewType);
        break;
    }
    case ViewAbstract::OutPut:
        break;
    case ViewAbstract::QueryEditor:
        break;
    case ViewAbstract::Default:
        break;
    }
}

void MainPresenter::ModelFinished(QAbstractItemModel *model, const ViewAbstract::ViewType &viewType)
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
    event->accept();
    delete mainView;
    this->quit();
}


ViewAbstract *&MainPresenter::getSubView(const ViewAbstract::ViewType& viewType)
{
    if(!views[viewType]){
        switch (viewType) {
        case ViewAbstract::ConnectionList:
            views[viewType] = new ConnectionListView(viewType);
            break;
        case ViewAbstract::QueryEditor:
            break;
        case ViewAbstract::OutPut:
            break;
        case ViewAbstract::Default:
            break;
        }
        views[viewType]->ApplySettings(QtXML::ElementByNameNTag(locale->documentElement(),tr("viewclass"),views[viewType]->getViewTypeStr()));
    }
    return views[viewType];
}

QAbstractItemModel*& MainPresenter::getViewModel(const ViewAbstract::ViewType& viewType)
{
    return models[viewType];
}
