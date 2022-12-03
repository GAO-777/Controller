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
    Console->hide();

    connectionManager = new ConnectionManager();

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&ControllerTab::customContextMenuRequested, this, &ControllerTab::customContextMenuRequest);

}

ControllerTab::~ControllerTab()
{
    delete RW_Lists;
    delete Console;
    delete ConnectionBar;
    delete connectionManager;
    delete ui;
}

void ControllerTab::connectDevice()
{
    connectionManager->connectDevice();
    bool Status = connectionManager->statusConnection;
    ConnectionBar->setStatus(Status,connectionManager->NameConnection);
    if(Status){ // Подлючение
        Console->print("Device connected","m");
        RW_Lists->unblock();
    }
    else{       // Отключение
        Console->print("Device disconnected","m");
        RW_Lists->block();
    }
}

void ControllerTab::write()
{
    bool status = connectionManager->write(RW_Lists->getWriteAddr(),RW_Lists->getWriteData());
   Console->print(" sent the package",connectionManager->raw_data);
    if(!status)
        QMessageBox::critical(this,"Error",connectionManager->Message);
}

void ControllerTab::read()
{
    QList<unsigned int> *Data = new QList<unsigned int>();

    bool status = connectionManager->read(RW_Lists->getReadAddr(),Data);
    Console->print(" received the package",connectionManager->raw_data);
    if(status)
        RW_Lists->fillReadList(Data);
    else
        QMessageBox::critical(this,"Error",connectionManager->Message);

}

void ControllerTab::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())// Есть дейтаграмма для чтения
        {
            QByteArray* datagram = new QByteArray();
            datagram->resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(datagram->data(),datagram->size());
            QList<unsigned int> *Data = EthDatagramToList(datagram);
            Console->printTable(Data);
        }

}

void ControllerTab::customContextMenuRequest(const QPoint &pos)
{
    QMenu* menu = new QMenu();

    if(Console->isHidden()){
        auto Show_console = menu->addAction("Show console");
        connect(Show_console, &QAction::triggered, this, [this](){
            Console->show();
        });
    }else{
        auto Hide_console = menu->addAction("Hide console");
        connect(Hide_console, &QAction::triggered, this, [this](){
            Console->hide();
        });
    }
    menu->exec(QCursor::pos());
}

void ControllerTab::on_Start_Server_pb_clicked()
{
   // udpSocket = new QUdpSocket(this);		// Создаем QUdpSocket
    //connect(udpSocket,&QUdpSocket::readyRead,this,&ControllerTab::dataReceived);

     // bool result=udpSocket->bind(27015);// Привязать порт 63820

    int N_words =100;
    int N_cycle =1000;
    int num_er=0;

    for(int i=0;i<N_cycle;i++){
        QList<unsigned int> *Addr = new  QList<unsigned int>;
        QList<unsigned int> *Data = new  QList<unsigned int>;
        for(int i=0;i<N_words;i++){
            Addr->append(8192+i);
            Data->append(rand());
        }


        QList<unsigned int> *ReadData = new QList<unsigned int> ();
         bool status = connectionManager->write(Addr,Data);
        status = connectionManager->read(Addr,ReadData);
        for(int k=0;k<N_words;k++)
            if(ReadData->at(k)!=Data->at(k)){
                qDebug()<<"error";
                num_er++;
            }
         qDebug()<<i;
        }
     qDebug()<<num_er;
}

void ControllerTab::on_Run_executable_file_pb_clicked()
{
    QString openFileName = QFileDialog::getOpenFileName(this,
                                                        "Open file",
                                                        QDir::currentPath(),
                                                        "INI files (*.cl);;All files (*.*)");
    QList<unsigned int>* Addr = new QList<unsigned int>();
    QList<unsigned int>* Data = new QList<unsigned int>();
    CLToQList(openFileName,Addr,Data);
    connectionManager->write(Addr,Data);

}
