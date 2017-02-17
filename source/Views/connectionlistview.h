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
    explicit ConnectionListView(ViewType vt, QWidget* parent = 0);
    ~ConnectionListView();

private:
    Ui::ConnectionListView *ui;
};

#endif // CONNECTIONLISTVIEW_H
