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
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
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

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
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

        QMetaObject::connectSlotsByName(ConnectionPropView);
    } // setupUi

    void retranslateUi(QWidget *ConnectionPropView)
    {
        ConnectionPropView->setWindowTitle(QApplication::translate("ConnectionPropView", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConnectionPropView", "TextLabel", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ConnectionPropView", "CheckBox", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConnectionPropView", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConnectionPropView", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionPropView: public Ui_ConnectionPropView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONPROPVIEW_H
