#ifndef CONTROLLERTAB_H
#define CONTROLLERTAB_H

#include <QWidget>
#include "../../C_lib/Qt_lib/tools.h"
#include <QMessageBox>
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

    RW_Widget* RW_Lists;
    Console* Console;
    ConnectionsBar* ConnectionBar;
    Connection_Info ConnectionInfo;
    ConnectionManager* connectionManager;

     QUdpSocket* udpSocket;

    void setConnectionSettings(Connection_Info CI){connectionManager->ConnectionInfo = CI;};
    void connectDevice();
    void write();
    void read();

    void dataReceived();

private slots:

    void on_Start_Server_pb_clicked();

    void on_Run_executable_file_pb_clicked();

private:
    Ui::ControllerTab *ui;
};

#endif // CONTROLLERTAB_H
