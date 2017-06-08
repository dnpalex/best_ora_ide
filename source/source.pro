
QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = best_ora_ide
TEMPLATE = app
INCLUDEPATH += .

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    Presenters/mainpresenter.cpp \
    Views/mainview.cpp \
    Views/connectionlistview.cpp \
    Views/viewabstract.cpp \
    Misc/settingsuser.cpp \
    Misc/logger.cpp \
    Misc/logableobject.cpp \
    Models/ioadapter.cpp \
    Views/connectionpropview.cpp \
    Models/adapterabstract.cpp \
    Misc/qtxml.cpp \
    Misc/qtdebug.cpp \

HEADERS  += Presenters/mainpresenter.h \
    Views/mainview.h \
    Views/enumviewtype.h \
    Views/connectionlistview.h \
    Views/viewabstract.h \
    Misc/settingsuser.h \
    Misc/logger.h \
    Misc/logableobject.h \
    Models/ioadapter.h \
    Views/connectionpropview.h \
    Models/adapterabstract.h \
    Misc/qtxml.h \
    Misc/qtdebug.h \

FORMS    += Views/mainview.ui \
    Views/connectionlistview.ui \
    Views/connectionpropview.ui

STATECHARTS +=

