#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QScopedPointer>
#include <QMap>
#include "source/Views/mainview.h"
#include "source/Views/connectionlistview.h"
#include "source/Models/treemodel.h"
#include "source/Misc/logger.h"


class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = 0);

    void ShowMainView();

signals:

public slots:

    void ShowSubView(ViewType viewType);

protected:

    QScopedPointer<MainView> mainView;

    ViewAbstract* getSubView(ViewType viewType);

    QAbstractItemModel* getViewModel(ViewType viewType, ViewAbstract* view = nullptr);

};

#endif // MAINPRESENTER_H
