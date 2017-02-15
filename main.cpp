#include <source/Presenters/mainpresenter.h>
#include <source/Views/mainview.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPresenter mainPres;

    mainPres.ShowMainView();

    return a.exec();
}
