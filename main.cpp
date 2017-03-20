#include <QResource>
#include <QDebug>
#include <QCoreApplication>

#include <source/Presenters/mainpresenter.h>
#include <source/Misc/logger.h>

int main(int argc, char *argv[])
{
    QResource::registerResource("res/ico.rcc");
    QResource::registerResource("res/locals.rcc");
    QResource::registerResource("res/config.rcc");

    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setOrganizationDomain("mysoft.com");
    QCoreApplication::setApplicationName("BestOraIDE");

    try {
        MainPresenter mainPres(argc, argv);
        return mainPres.exec();
    } catch (QString mes) {
        qDebug() << mes;
    }
    return 0;
}
