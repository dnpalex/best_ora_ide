#include <QApplication>
#include <QResource>
#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>

#include <source/Presenters/mainpresenter.h>
#include <source/Misc/logger.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");
    QCoreApplication::setApplicationName("BestOraIDE");//*/

    //qDebug() << "reg ico:" <<
    QResource::registerResource("res/ico.rcc");
    //qDebug() << "reg locals:" <<
    QResource::registerResource("res/locals.rcc");
    QResource::registerResource("res/config.rcc");

    //QSettings s(":/general",QSettings::IniFormat);

    MainPresenter mainPres;
    mainPres.ShowMainView();//*/

    //s.beginGroup("ConnectionList");
    //s.setValue("windowName","Connections");

    //qDebug() << "wrote value: " <<s.value("windowTitle");

    return a.exec();
    //return 0;
}
