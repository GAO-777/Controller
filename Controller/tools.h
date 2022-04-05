#ifndef TOOLS_H
#define TOOLS_H
#include <Windows.h>
#include "USB_Interface.h"
#include <QTableWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QList>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include<QSettings>
#include<QFileDialog>
#include <QComboBox>
#include<QList>
#include<QCloseEvent>
#include<QSpinBox>
#include <QValidator>
/*===============================================================================================*\
  ███████████████████████████████████████████████████████████████████████████████████████████████
  ███████████████████████████───█─█─█─██─█────█───█───█────█─██─█───█████████████████████████████
  ███████████████████████████─███─█─█──█─█─██─██─███─██─██─█──█─█─███████████████████████████████
  ███████████████████████████───█─█─█─█──█─█████─███─██─██─█─█──█───█████████████████████████████
  ███████████████████████████─███─█─█─██─█─██─██─███─██─██─█─██─███─█████████████████████████████
  ███████████████████████████─███───█─██─█────██─██───█────█─██─█───█████████████████████████████
  ███████████████████████████████████████████████████████████████████████████████████████████████
\*===============================================================================================*/
WORD* QListToWord(QList<unsigned int>* InData);

QList<unsigned int> WordToQList(WORD* InData, int size);

enum ConnectionType{
    NON = 0,
    USB = 1,
    UDP = 2
};

struct Connection_Info {
    ConnectionType connectionType;
    // - - - USB - - - //
    QString USB_SN;
    QString USB_Description;
    QString USB_ID;
    QString USB_LocId;
    // - - - UDP - - - //
    QString IP_addrress;
    int Port;
};

/*===============================================================================================*\
  ███████████████████████████████████████████████████████████████████████████████████
  ████████████────█────█─███─█─███─█────█─██─█────██─███───█───█───██████████████████
  ████████████─██─█─██─█──█──█──█──█─██─█──█─█─██──█─████─██─████─███████████████████
  ████████████─████─██─█─█─█─█─█─█─█────█─█──█─██──█─████─██───██─███████████████████
  ████████████─██─█─██─█─███─█─███─█─██─█─██─█─██──█─████─████─██─███████████████████
  ████████████────█────█─███─█─███─█─██─█─██─█────██───█───█───██─███████████████████
  ███████████████████████████████████████████████████████████████████████████████████
\*===============================================================================================*/

class CommandList : public QTableWidget
{
    Q_OBJECT
public:
    CommandList(QTableWidget *parent = nullptr);

    QString Name;
    int size =0;        // кол-во строк
    QList<unsigned int>* Items;
    QList<unsigned int>* Addr;
    QList<unsigned int>* Data;

    void createRow(int s);
    void updateQLists();    // Обновление списков: Items,Addr,Data
    void fill_Data(QList<unsigned int> *Items, unsigned int* InData);
    void fill_Data(QList<unsigned int> *Items, QList<unsigned int>* InData);
    void getDataToSave();
    void setDataToLoad(int size,QList<unsigned int>* Items,QList<unsigned int>* Addr,QList<unsigned int>* Data);
    void clearList();
    void save(QString saveFileName);
    void load(QString openFileName);

};


/*===============================================================================================*\
  ███████████████████████████████████████████████████████████████████████████████████████████████
  ████████████────█────█─██─█─██─█───█────█───█───█────█─██─█───█───█───█─█─█────████████████████
  ████████████─██─█─██─█──█─█──█─█─███─██─██─███─██─██─█──█─█─███─████─██─█─█─██─████████████████
  ████████████─████─██─█─█──█─█──█───█─█████─███─██─██─█─█──█───█───██─██─█─█────████████████████
  ████████████─██─█─██─█─██─█─██─█─███─██─██─███─██─██─█─██─███─█─████─██─█─█─███████████████████
  ████████████────█────█─██─█─██─█───█────██─██───█────█─██─█───█───██─██───█─███████████████████
  ███████████████████████████████████████████████████████████████████████████████████████████████
\*===============================================================================================*/
namespace Ui {
class ConnectionSetup;
}

class ConnectionSetup : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionSetup(QWidget *parent = nullptr);
    ~ConnectionSetup();

    void init_Pages();
    void PageSwitch();

    void UpdateDiviceList();
    void USB_page_ChangedDevice(int i);
    void UpdateSetup();

/*==========================================================================================*\
- - - - - - - - - - - - - USB PAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
\*==========================================================================================*/
    QWidget *USB_page;
    QComboBox* USB_SN_cb;
    QLabel* USB_Description_l;
    QLabel* USB_ID_l;
    QLabel* USB_LocId_l;
    QPushButton* USB_UpdateDeviceList_pb;
    FT_DEVICE_LIST_INFO_NODE *USB_DevInfo;  // Список подлюченных USB устройств

/*==========================================================================================*\
- - - - - - - - - - - - - UDP PAGE - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
\*==========================================================================================*/
    QWidget* UDP_page;
    QLineEdit*  IPaddress;
    QSpinBox*  Port;


private slots:
    void on_ApplyButton_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::ConnectionSetup *ui;
};


/*===============================================================================================*\
  ███████████████████████████████████████████████████████████████████████████████████████████████
  ███████████────█────█─██─█─██─█───█────█───█───█────█─██─█───█────██────█────██████████████████
  ███████████─██─█─██─█──█─█──█─█─███─██─██─███─██─██─█──█─█─███─██──█─██─█─██─██████████████████
  ███████████─████─██─█─█──█─█──█───█─█████─███─██─██─█─█──█───█────██────█────██████████████████
  ███████████─██─█─██─█─██─█─██─█─███─██─██─███─██─██─█─██─███─█─██──█─██─█─█─███████████████████
  ███████████────█────█─██─█─██─█───█────██─██───█────█─██─█───█────██─██─█─█─███████████████████
  ███████████████████████████████████████████████████████████████████████████████████████████████
\*===============================================================================================*/

class ConnectionsBar : public QWidget
{
    Q_OBJECT
public:
    explicit ConnectionsBar(QWidget *parent = nullptr);
    QWidget *ConnectionsBar_w;
    QPushButton* SettingsConnection_pb;
    QPushButton* openDevice_pb;         // Испускает сигнал OpenDevice, чтобы родитель инициировал обмен данными

    // = = = = = Данные о выбранном соединении = = = = = //
    Connection_Info ConnectionInfo;     // Параметры соединения
    QLabel*  Status_l;                  // Cтатус соединения
    QLabel*  NameConnection;
    void setStatus(bool status, QString name);
    void callConnectionSetup();         // Вызывает окно настройки соединения
    void openDevice();                  // Испускает сигнал OpenDevice

signals:
    void SettingsChanged(Connection_Info CI);
    void OpenDevice();
};




#endif // TOOLS_H