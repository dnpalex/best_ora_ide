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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionListView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layToolBar;
    QTreeView *treeView;

    void setupUi(QWidget *ConnectionListView)
    {
        if (ConnectionListView->objectName().isEmpty())
            ConnectionListView->setObjectName(QStringLiteral("ConnectionListView"));
        ConnectionListView->resize(326, 571);
        verticalLayout = new QVBoxLayout(ConnectionListView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layToolBar = new QHBoxLayout();
        layToolBar->setSpacing(0);
        layToolBar->setObjectName(QStringLiteral("layToolBar"));

        verticalLayout->addLayout(layToolBar);

        treeView = new QTreeView(ConnectionListView);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);


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
