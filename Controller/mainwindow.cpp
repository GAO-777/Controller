#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFont(QFont("Consolas",9, QFont::Normal));
    connect(ui->Control_Connections_tw->tabBar(), &QTabBar::tabCloseRequested,this, &MainWindow::closeTab);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddConnection_pb_clicked()
{
    ControllerTab* newTab = new ControllerTab();
    ui->Control_Connections_tw->addTab(newTab,"Controller Tab");
    int indexOfnewTab = ui->Control_Connections_tw->indexOf(newTab);
    ui->Control_Connections_tw->setCurrentIndex(indexOfnewTab);
}

void MainWindow::closeTab(int tab)
{
    ui->Control_Connections_tw->tabBar()->removeTab(tab);
    ui->Control_Connections_tw->widget(tab)->close();
    ui->Control_Connections_tw->setCurrentIndex(tab-1);
}
