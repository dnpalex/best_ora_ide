#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include <QToolBar>
#include <QScopedPointer>
#include <QAbstractItemModel>

#include "source/Views/viewabstract.h"

namespace Ui {
class ConnectionListView;
}

class ConnectionListView : public ViewAbstract
{
    Q_OBJECT

public:
    explicit ConnectionListView(ViewType vt, QAbstractItemModel* model = Q_NULLPTR, QWidget* parent = Q_NULLPTR);
    ~ConnectionListView();

    void setConnectionsModel(QAbstractItemModel* model);

protected:

    void AddConnection();
    void RemoveConnection();

private:
    Ui::ConnectionListView *ui;
    QScopedPointer<QToolBar> toolBar;
};

#endif // CONNECTIONLISTVIEW_H
