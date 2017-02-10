#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

#include <QWidget>

namespace Ui {
class ConnectionList;
}

class ConnectionList : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionList(QWidget *parent = 0);
    ~ConnectionList();

private:
    Ui::ConnectionList *ui;
};

#endif // CONNECTIONLIST_H
