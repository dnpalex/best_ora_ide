#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <QScopedPointer>
#include <QMap>
#include "source/Views/mainview.h"
#include "source/Views/connectionlistview.h"
#include "source/Models/ioadapter.h"
#include "source/Misc/logger.h"


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

    QScopedPointer<MainView> mainView;
    QScopedPointer<IOAdapter> ioadapter;

    ViewAbstract* getSubView(const ViewType& viewType);

    QAbstractItemModel *getViewModel(const ViewType& viewType);

};

#endif // MAINPRESENTER_H
