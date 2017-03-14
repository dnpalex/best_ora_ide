#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QScopedPointer>
#include <QMap>

#include "source/Views/mainview.h"
#include "source/Views/connectionlistview.h"
#include "source/Models/ioadapter.h"
#include "source/Misc/logger.h"
#include "source/Views/connectionpropview.h"


class MainPresenter : public QObject, SettingsUser
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = 0);

    void ShowMainView();

signals:

public slots:

    void ShowSubView(ViewType viewType);

protected:

    //Views
    QScopedPointer<MainView> mainView;
    QMap<ViewType,ViewAbstract*> views;

    //getters

    QScopedPointer<MainView> &getMainView();
    ViewAbstract*& getSubView(const ViewType& viewType);

    //Models
    QScopedPointer<IOAdapter> ioadapter;
    QMap<ViewType,QAbstractItemModel*> models;

    //getters
    QScopedPointer<IOAdapter>& getIoadapter();
    QAbstractItemModel*& getViewModel(const ViewType& viewType);



};

#endif // MAINPRESENTER_H
