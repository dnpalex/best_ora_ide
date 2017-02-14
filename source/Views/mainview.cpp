#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    connect(ui->actionConnection_list,&QAction::triggered,[=]() { emit ShowConnections(); });
}

MainView::~MainView()
{
    delete ui;
}

