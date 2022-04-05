#ifndef CONTROLLERTAB_H
#define CONTROLLERTAB_H

#include <QWidget>
#include "tools.h"
#include "ethernet_interface.h"
#include "USB_Interface.h"
#include <QUdpSocket>
namespace Ui {
class ControllerTab;
}

class ControllerTab : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerTab(QWidget *parent = nullptr);
    ~ControllerTab();

    ConnectionsBar* ConnectionBar;
    Connection_Info ConnectionInfo;

    Ethernet_Interface* Eth;
    QUdpSocket* udpSocket;
    USB_Interface*      USB;

    void setConnectionSettings(Connection_Info CI);
    void openDevice();
    void readPendingDatagrams();
private:
    Ui::ControllerTab *ui;
};

#endif // CONTROLLERTAB_H
