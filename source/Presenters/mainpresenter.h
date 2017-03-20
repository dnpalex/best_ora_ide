#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QScopedPointer>
#include <QMap>
#include <QThread>
#include <QApplication>
#include <QCloseEvent>

#include "source/Views/mainview.h"
#include "source/Views/connectionlistview.h"
#include "source/Models/ioadapter.h"
#include "source/Misc/logger.h"
#include "source/Views/connectionpropview.h"


class MainPresenter : public QApplication, public SettingsUser
{
    Q_OBJECT
public:
    explicit MainPresenter(int& argc,char**argv,int appflags = QApplication::ApplicationFlags);
    ~MainPresenter();

    virtual int exec();

    void ShowSubView(const ViewType& viewType);

    void ModelFinished(QAbstractItemModel* model, const ViewType& viewType);

    void MainViewClosed(QCloseEvent* event);

signals:

    void RequestModel(const ViewType& viewType);

protected:

    //Views
    MainView* mainView;
    QMap<ViewType,ViewAbstract*> views;

    //getters
    ViewAbstract*& getSubView(const ViewType& viewType);

    //Models
    QMap<ViewType,QAbstractItemModel*> models;

    //getters
    QAbstractItemModel*& getViewModel(const ViewType& viewType);

    //Threads
    QThread* ioThread;

    //Logger
    Logger* logger;

};

#endif // MAINPRESENTER_H
