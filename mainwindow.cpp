#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/logo.png");
    ui->label_logo->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openAdmin()
{
    adm = new admin(this);
    QString a;
    a="Administrador";
    adm->setWindowTitle(a);
    adm->setStyleSheet("QMainWindow {background: 'brown';}");
    adm->show();
}

void MainWindow::openClient()
{
    clie = new cliente(this);
    QString c;
    c="Cliente";
    clie->setWindowTitle(c);
    clie->setStyleSheet("QMainWindow {background: 'green';}");
    clie->show();
}

void MainWindow::on_addmi_clicked()
{
   openAdmin();
}

void MainWindow::on_compra_clicked()
{
    openClient();
}
