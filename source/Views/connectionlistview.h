#ifndef CONNECTIONLISTVIEW_H
#define CONNECTIONLISTVIEW_H

#include <QWidget>

namespace Ui {
class ConnectionListView;
}

class ConnectionListView : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionListView(QWidget *parent = 0);
    ~ConnectionListView();

private:
    Ui::ConnectionListView *ui;
};

#endif // CONNECTIONLISTVIEW_H
