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
    ui->MVL->addWidget(RW_Lists);

    USB_Device = new USB_Interface();

    statusConnection = false;
}

ControllerTab::~ControllerTab()
{
    delete ui;
}

void ControllerTab::setConnectionSettings(Connection_Info CI)
{
    ConnectionInfo = CI;
}

void ControllerTab::connectDevice()
{
    /*
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
        }*/



    if(ConnectionInfo.connectionType == USB){
        if(statusConnection == false){
            // - - - Подлючение - - - //
            USB_Device->Select_Device(ConnectionInfo.USB_SN.toStdString().c_str());
            statusConnection = USB_Device->Open_Device();
            if(statusConnection == true){
                ConnectionBar->setStatus(true,ConnectionInfo.USB_SN);
            }else {
                QMessageBox::critical(this,
                                      ("Ошибка"),
                                      ("Произошла ошибка при подлючении."));
            }
        }else{
            // - - - Отключение - - - //
            statusConnection = !USB_Device->Close_Device();
            if(statusConnection == false){
                ConnectionBar->setStatus(statusConnection,ConnectionInfo.USB_SN);
            }else {
                QMessageBox::critical(this,
                                             ("Ошибка"),
                                             ("Произошла ошибка при отключении устройства."));
            }

        }
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


