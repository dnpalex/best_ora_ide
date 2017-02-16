#include <source/Presenters/mainpresenter.h>
#include <QApplication>

#include <QPushButton>
#include <source/Views/viewabstract.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPresenter mainPres;
    mainPres.ShowMainView();

    return a.exec();
}
