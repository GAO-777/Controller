#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectionBar = new ConnectionsBar();
    ui->MVL->addWidget(ConnectionBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

