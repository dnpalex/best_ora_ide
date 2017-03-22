#-------------------------------------------------
#
# Project created by QtCreator 2017-02-10T14:22:45
#
#-------------------------------------------------

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
    source/Presenters/mainpresenter.cpp \
    source/Views/mainview.cpp \
    source/Views/connectionlistview.cpp \
    source/Views/viewabstract.cpp \
    source/Misc/settingsuser.cpp \
    source/Misc/logger.cpp \
    source/Misc/logableobject.cpp \
    source/Models/ioadapter.cpp \
    source/Views/connectionpropview.cpp \
    source/Models/adapterabstract.cpp \
    source/Misc/qtxml.cpp

HEADERS  += source/Presenters/mainpresenter.h \
    source/Views/mainview.h \
    source/Views/enumviewtype.h \
    source/Views/connectionlistview.h \
    source/Views/viewabstract.h \
    source/Misc/settingsuser.h \
    source/Misc/logger.h \
    source/Misc/logableobject.h \
    source/Models/ioadapter.h \
    source/Views/connectionpropview.h \
    source/Models/adapterabstract.h \
    source/Misc/qtxml.h

FORMS    += source/Views/mainview.ui \
    source/Views/connectionlistview.ui \
    source/Views/connectionpropview.ui

STATECHARTS +=

