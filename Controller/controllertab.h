#ifndef CONTROLLERTAB_H
#define CONTROLLERTAB_H

#include <QWidget>
#include "tools.h"
#include "ethernet_interface.h"
#include "USB_Interface.h"
#include <QUdpSocket>
#include <QMessageBox>
namespace Ui {
class ControllerTab;
}

class ControllerTab : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerTab(QWidget *parent = nullptr);
    ~ControllerTab();

    RW_Widget* RW_Lists;
    Console* Console;
    ConnectionsBar* ConnectionBar;
    Connection_Info ConnectionInfo;

    bool statusConnection;
    Ethernet_Interface* Eth_Device;
    QUdpSocket* udpSocket;

    USB_Interface*      USB_Device;

    void setConnectionSettings(Connection_Info CI);
    void connectDevice();
    void readPendingDatagrams();
private:
    Ui::ControllerTab *ui;
};

#endif // CONTROLLERTAB_H
