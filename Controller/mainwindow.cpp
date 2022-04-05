#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddConnection_pb_clicked()
{
    ControllerTab* newTab = new ControllerTab(this);
    ui->Control_Connections_tw->addTab(newTab,"Controller Tab");
}
