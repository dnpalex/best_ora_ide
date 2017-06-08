#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QScopedPointer>
#include <QMap>
#include <QThread>
#include <QApplication>
#include <QCloseEvent>

#include "Views/mainview.h"
#include "Views/connectionlistview.h"
#include "Models/ioadapter.h"
#include "Misc/logger.h"
#include "Views/connectionpropview.h"
#include "Misc/qtxml.h"


class MainPresenter : public QApplication, public SettingsUser
{
    Q_OBJECT
public:
    explicit MainPresenter(int& argc,char**argv,int appflags = QApplication::ApplicationFlags);
    ~MainPresenter();

    virtual int exec();

    void ShowSubView(const ViewAbstract::ViewType& viewType);

    void ModelFinished(QAbstractItemModel* model, const ViewAbstract::ViewType& viewType);

    void MainViewClosed(QCloseEvent* event);

signals:

    void RequestModel(const ViewAbstract::ViewType& viewType);

protected:

    //Views
    MainView* mainView;
    QMap<ViewAbstract::ViewType,ViewAbstract*> views;
    //Models
    QMap<ViewAbstract::ViewType,QAbstractItemModel*> models;
    //Logger
    Logger* logger;
    //Adapters
    IOAdapter* ioAdapter;
    //Resources
    QDomDocument* locale;

    //getters
    ViewAbstract*& getSubView(const ViewAbstract::ViewType& viewType);
    QAbstractItemModel*& getViewModel(const ViewAbstract::ViewType& viewType);

};

#endif // MAINPRESENTER_H
