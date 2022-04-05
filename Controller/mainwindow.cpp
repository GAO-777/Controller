#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectionBar = new ConnectionsBar();
    RW_Widget* RWidget = new RW_Widget();
    ui->MVL->addWidget(RWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

