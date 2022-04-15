#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setFont(QFont("Consolas",9, QFont::Normal));
    connect(ui->TabWidget_tw->tabBar(), &QTabBar::tabCloseRequested,this, &MainWindow::closeTab);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeTab(int tab)
{
    ui->TabWidget_tw->removeTab(tab);
}

void MainWindow::on_NewConnection_action_triggered()
{
    ControllerTab* newTab = new ControllerTab(ui->TabWidget_tw);
    int indexOfnewTab = ui->TabWidget_tw->addTab(newTab,"1");
    ui->TabWidget_tw->setTabText(indexOfnewTab,"Controller Tab "+QString::number(indexOfnewTab));
    ui->TabWidget_tw->setCurrentIndex(indexOfnewTab);
}

