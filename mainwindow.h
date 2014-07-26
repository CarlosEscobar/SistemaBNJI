#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
#include "cliente.h"
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
    
public slots:
    void openAdmin();
    void openClient();

private slots:
    void on_addmi_clicked();
    void on_compra_clicked();

private:
    Ui::MainWindow *ui;
    admin* adm;
    cliente* clie;
};

#endif // MAINWINDOW_H
