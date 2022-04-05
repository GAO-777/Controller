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
    void on_AddConnection_pb_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
