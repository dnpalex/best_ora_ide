#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include "source/Views/viewabstract.h"


namespace Ui {
class ConnectionListView;
}

class ConnectionListView : public ViewAbstract
{
    Q_OBJECT

public:
    explicit ConnectionListView(QWidget *parent = 0);
    ConnectionListView(ViewType vt, QString windowName = tr("Connections"), QWidget* parent = 0);
    ~ConnectionListView();

private:
    Ui::ConnectionListView *ui;
};

#endif // CONNECTIONLISTVIEW_H
