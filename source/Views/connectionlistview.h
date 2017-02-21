#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include "source/Views/viewabstract.h"
#include <QToolBar>
#include <QScopedPointer>


namespace Ui {
class ConnectionListView;
}

class ConnectionListView : public ViewAbstract
{
    Q_OBJECT

public:
    explicit ConnectionListView(ViewType vt, QWidget* parent = 0);
    ~ConnectionListView();
protected slots:

    void AddConnection();
    void RemoveConnection();

private:
    Ui::ConnectionListView *ui;
    QScopedPointer<QToolBar> toolBar;
};

#endif // CONNECTIONLISTVIEW_H
