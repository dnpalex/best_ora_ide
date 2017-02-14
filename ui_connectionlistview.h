/********************************************************************************
** Form generated from reading UI file 'connectionlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONLISTVIEW_H
#define UI_CONNECTIONLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionListView
{
public:

    void setupUi(QWidget *ConnectionListView)
    {
        if (ConnectionListView->objectName().isEmpty())
            ConnectionListView->setObjectName(QStringLiteral("ConnectionListView"));
        ConnectionListView->resize(400, 300);

        retranslateUi(ConnectionListView);

        QMetaObject::connectSlotsByName(ConnectionListView);
    } // setupUi

    void retranslateUi(QWidget *ConnectionListView)
    {
        ConnectionListView->setWindowTitle(QApplication::translate("ConnectionListView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionListView: public Ui_ConnectionListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONLISTVIEW_H
