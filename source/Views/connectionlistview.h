#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include "source/Views/viewabstract.h"
#include <QToolBar>
#include <QScopedPointer>
#include <QAbstractItemModel>


namespace Ui {
class ConnectionListView;
}

class ConnectionListView : public ViewAbstract
{
    Q_OBJECT

public:
    explicit ConnectionListView(ViewType vt, QAbstractItemModel* model = 0, QWidget* parent = 0);
    ~ConnectionListView();

    void setConnectionsModel(QAbstractItemModel* model);

protected slots:

    void AddConnection();
    void RemoveConnection();

private:
    Ui::ConnectionListView *ui;
    QScopedPointer<QToolBar> toolBar;
};

#endif // CONNECTIONLISTVIEW_H
