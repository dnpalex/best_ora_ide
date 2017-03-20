/********************************************************************************
** Form generated from reading UI file 'connectionpropview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONPROPVIEW_H
#define UI_CONNECTIONPROPVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionPropView
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit1;
    QLabel *label1;
    QLabel *label3;
    QLabel *label2;
    QCheckBox *checkBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QWidget *ConnectionPropView)
    {
        if (ConnectionPropView->objectName().isEmpty())
            ConnectionPropView->setObjectName(QStringLiteral("ConnectionPropView"));
        ConnectionPropView->resize(633, 356);
        horizontalLayout = new QHBoxLayout(ConnectionPropView);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(ConnectionPropView);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(3);
        splitter->setChildrenCollapsible(false);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        splitter->addWidget(treeView);
        treeView->header()->setVisible(false);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(4);
        lineEdit_3 = new QLineEdit(verticalLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        lineEdit2 = new QLineEdit(verticalLayoutWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));

        gridLayout->addWidget(lineEdit2, 1, 1, 1, 1);

        lineEdit1 = new QLineEdit(verticalLayoutWidget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));

        gridLayout->addWidget(lineEdit1, 0, 1, 1, 1);

        label1 = new QLabel(verticalLayoutWidget);
        label1->setObjectName(QStringLiteral("label1"));

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        label3 = new QLabel(verticalLayoutWidget);
        label3->setObjectName(QStringLiteral("label3"));

        gridLayout->addWidget(label3, 1, 0, 1, 1);

        label2 = new QLabel(verticalLayoutWidget);
        label2->setObjectName(QStringLiteral("label2"));

        gridLayout->addWidget(label2, 2, 0, 1, 1);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 3, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        splitter->addWidget(verticalLayoutWidget);

        horizontalLayout->addWidget(splitter);


        retranslateUi(ConnectionPropView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConnectionPropView);
    } // setupUi

    void retranslateUi(QWidget *ConnectionPropView)
    {
        ConnectionPropView->setWindowTitle(QApplication::translate("ConnectionPropView", "Form", Q_NULLPTR));
        label1->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        label3->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        label2->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ConnectionPropView", "Save password", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConnectionPropView", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConnectionPropView", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionPropView: public Ui_ConnectionPropView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONPROPVIEW_H
