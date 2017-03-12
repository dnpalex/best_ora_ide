#include "mainpresenter.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    mainView.reset(new MainView());
    connect(mainView.data(),&MainView::sigShowSubView,this,&MainPresenter::ShowSubView);

    ioadapter.reset(new IOAdapter(this));
    connect(ioadapter.data(),&IOAdapter::LogError,new Logger(this),&Logger::LogMessage);
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

ViewAbstract* MainPresenter::getSubView(const ViewType& viewType)
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

QAbstractItemModel* MainPresenter::getViewModel(const ViewType& viewType)
{
    QAbstractItemModel* model = Q_NULLPTR;
    switch (viewType) {
    case ViewType::ConnectionList:
        model = ioadapter.data()->readFile(tr(":/connections.xml"), IOAdapter::XML);
        model->setParent(this);
    case ViewType::QueryEditor:
        break;
    case ViewType::OutPut:
        break;
    case ViewType::Default:
        break;
    };
    return model;
}
