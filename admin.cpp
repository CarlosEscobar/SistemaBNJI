#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    QPixmap pix2("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/logo2.png");
    ui->label_logoadmin->setPixmap(pix2);

    ui->label_error->setVisible(false);
}

admin::~admin()
{
    delete ui;
}

void admin::openMainAdmin()
{
    mainad=new mainadmin(this);
    QString mun;
    mun="Control Central BNJI";
    mainad->setWindowTitle(mun);
    mainad->setStyleSheet("QMainWindow {background: 'grey';}");
    mainad->show();
}

void admin::on_continuar_admin_clicked()
{
    QString password;
    password="123";
    if (ui->lineEdit->text()==password)
    {
        ui->label_error->setVisible(false);
        openMainAdmin();
    } else
    {
        ui->label_error->setVisible(true);
    }
}
