#ifndef CONTROLLERTAB_H
#define CONTROLLERTAB_H

#include <QWidget>
#include "tools.h"
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
    ConnectionManager* connectionManager;

    void setConnectionSettings(Connection_Info CI){connectionManager->ConnectionInfo = CI;};
    void connectDevice();
    void write();
    void read();

private:
    Ui::ControllerTab *ui;
};

#endif // CONTROLLERTAB_H
