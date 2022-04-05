#include "controllertab.h"
#include "ui_controllertab.h"

ControllerTab::ControllerTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControllerTab)
{
    ui->setupUi(this);
    ConnectionBar = new ConnectionsBar();
    connect(ConnectionBar,&ConnectionsBar::SettingsChanged,this,&ControllerTab::setConnectionSettings);
    connect(ConnectionBar,&ConnectionsBar::OpenDevice,this,&ControllerTab::openDevice);
    ui->Tools_vl->addWidget(ConnectionBar);
}

ControllerTab::~ControllerTab()
{
    delete ui;
}

void ControllerTab::setConnectionSettings(Connection_Info CI)
{
    ConnectionInfo = CI;
}

void ControllerTab::openDevice()
{
    if(ConnectionInfo.connectionType == UDP){
       // Eth = new Ethernet_Interface();
       // bool EthStatus = false;
       // EthStatus = Eth->init(ConnectionInfo.IP_addrress.toStdString().c_str(),ConnectionInfo.Port);
       // if(EthStatus){
         //   qDebug()<<EthStatus;
       udpSocket = new QUdpSocket(this);
            udpSocket->bind(QHostAddress::LocalHost, 7755);

            connect(udpSocket, &QUdpSocket::readyRead,
                    this, &ControllerTab::readPendingDatagrams);
        }

}

void ControllerTab::readPendingDatagrams()
{
    qDebug()<<"Принял";
    //while (udpSocket->hasPendingDatagrams()) {
        //   QNetworkDatagram datagram = udpSocket->receiveDatagram();
           //rocessTheDatagram(datagram);
      // }
}


