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
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionListView
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *ConnectionListView)
    {
        if (ConnectionListView->objectName().isEmpty())
            ConnectionListView->setObjectName(QStringLiteral("ConnectionListView"));
        ConnectionListView->resize(243, 527);
        verticalLayout = new QVBoxLayout(ConnectionListView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(ConnectionListView);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(ConnectionListView);

        QMetaObject::connectSlotsByName(ConnectionListView);
    } // setupUi

    void retranslateUi(QWidget *ConnectionListView)
    {
        ConnectionListView->setWindowTitle(QApplication::translate("ConnectionListView", "Form", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ConnectionListView", "Connection", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("ConnectionListView", "PROD", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("ConnectionListView", "S1P", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("ConnectionListView", "M1P", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("ConnectionListView", "UAT", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QApplication::translate("ConnectionListView", "S1U", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(0, QApplication::translate("ConnectionListView", "S7U", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem7->setText(0, QApplication::translate("ConnectionListView", "SIT", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QApplication::translate("ConnectionListView", "R7T", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ConnectionListView: public Ui_ConnectionListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONLISTVIEW_H
