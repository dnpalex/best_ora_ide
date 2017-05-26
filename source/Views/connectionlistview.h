#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include <QToolBar>
#include <QScopedPointer>
#include <QAbstractItemModel>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "source/Misc/qtdebug.h"
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

    void setModel(QAbstractItemModel *model) Q_DECL_OVERRIDE;

protected:

    void AddConnection();
    void RemoveConnection();

    QToolBar* toolBar;

private:
    Ui::ConnectionListView *ui;
};

#endif // CONNECTIONLISTVIEW_H
