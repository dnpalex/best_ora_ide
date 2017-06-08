#ifndef CONNECTIONPROPVIEW_H
#define CONNECTIONPROPVIEW_H

#include <QDialog>

namespace Ui {
class ConnectionPropView;
}

class ConnectionPropView : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionPropView(QWidget *parent = 0);
    ~ConnectionPropView();

private:
    Ui::ConnectionPropView *ui;
};

#endif // CONNECTIONPROPVIEW_H
