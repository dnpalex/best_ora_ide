#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QDockWidget>
#include "source/Views/viewabstract.h"

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

    void AddToolBox(ViewAbstract* tb);

signals:

    void sigShowSubView(ViewType);

protected:

    ViewAbstract* ifViewAvailable(ViewType vt);

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
