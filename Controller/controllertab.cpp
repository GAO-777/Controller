#include "controllertab.h"
#include "ui_controllertab.h"

ControllerTab::ControllerTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControllerTab)
{
    ui->setupUi(this);
    // - - - ConnectionBar - - - //
    ConnectionBar = new ConnectionsBar();
    connect(ConnectionBar,&ConnectionsBar::SettingsChanged,this,&ControllerTab::setConnectionSettings);
    connect(ConnectionBar,&ConnectionsBar::OpenDevice,this,&ControllerTab::connectDevice);
    ui->Tools_vl->addWidget(ConnectionBar);

    // - - - RW_Widget - - - //
    RW_Lists = new RW_Widget();
    RW_Lists->block();
    connect(RW_Lists,&RW_Widget::write_pb_clicked,this,&ControllerTab::write);
    connect(RW_Lists,&RW_Widget::read_pb_clicked,this,&ControllerTab::read);
    ui->MVL->addWidget(RW_Lists);

    Console = new class Console();
    ui->Console_vl->addWidget(Console);

    connectionManager = new ConnectionManager();


}

ControllerTab::~ControllerTab()
{
    delete ui;
}

void ControllerTab::connectDevice()
{
    connectionManager->connectDevice();
    bool Status = connectionManager->statusConnection;
    ConnectionBar->setStatus(Status,connectionManager->NameConnection);
    if(Status)
        RW_Lists->unblock();
    else
        RW_Lists->block();
}

void ControllerTab::write()
{
    bool status = connectionManager->write(RW_Lists->getWriteAddr(),RW_Lists->getWriteData());
    if(status)
        printSendData("UDP Write Button",RW_Lists->getWriteAddr(),RW_Lists->getWriteData());
   else
        QMessageBox::critical(this,"Error",connectionManager->Message);
}

void ControllerTab::read()
{
    QList<unsigned int> *Data = new QList<unsigned int> ();

    bool status = connectionManager->read(RW_Lists->getReadAddr(),Data);
    if(status){
        printSendData("UDP Read Button",RW_Lists->getReadAddr(),Data);
        RW_Lists->fillReadList(Data);
    }
    else
        QMessageBox::critical(this,"Error",connectionManager->Message);

}


