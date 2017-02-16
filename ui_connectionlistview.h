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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionListView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *ConnectionListView)
    {
        if (ConnectionListView->objectName().isEmpty())
            ConnectionListView->setObjectName(QStringLiteral("ConnectionListView"));
        ConnectionListView->resize(326, 571);
        verticalLayout = new QVBoxLayout(ConnectionListView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        pushButton = new QPushButton(ConnectionListView);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(ConnectionListView);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(ConnectionListView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 10);

        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(ConnectionListView);
        treeWidget->headerItem()->setText(0, QString());
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, treeWidget);
        QWidget::setTabOrder(treeWidget, pushButton_3);

        retranslateUi(ConnectionListView);

        QMetaObject::connectSlotsByName(ConnectionListView);
    } // setupUi

    void retranslateUi(QWidget *ConnectionListView)
    {
        ConnectionListView->setWindowTitle(QApplication::translate("ConnectionListView", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ConnectionListView", ".", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ConnectionListView", ".", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ConnectionListView", ".", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionListView: public Ui_ConnectionListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONLISTVIEW_H
