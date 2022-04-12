#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tools.h"
#include "controllertab.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    ConnectionsBar* ConnectionBar;

private slots:
    void closeTab(int tab);
    void on_NewConnection_action_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
