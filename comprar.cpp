#include "comprar.h"
#include "ui_comprar.h"

comprar::comprar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comprar)
{
    ui->setupUi(this);

    ui->label_error->setVisible(false);
}

comprar::~comprar()
{
    delete ui;
}

void comprar::openCompraLibreSinCone()
{
    complibsincone = new CompraLibreSinCone(this);
    QString m;
    m="Compra Libre";
    complibsincone->setWindowTitle(m);
    complibsincone->setStyleSheet("QMainWindow {background: 'white';}");
    complibsincone->show();
}

void comprar::openCompraBarata()
{
    comprabar = new CompraBarata(this);
    QString m;
    m="Compra Barata";
    comprabar->setWindowTitle(m);
    comprabar->setStyleSheet("QMainWindow {background: 'white';}");
    comprabar->show();
}

void comprar::on_pushButton_clicked()
{
    if ((ui->checkBox_cC->isChecked()==false) && (ui->checkBox_sC->isChecked()==false))
    {
        ui->label_error->setVisible(true);
    } else if(ui->checkBox_sC->isChecked())
    {
        ui->label_error->setVisible(false);
        openCompraLibreSinCone();
        this->close();
    }
}

void comprar::on_pushButton_2_clicked()
{
    openCompraBarata();
    this->close();
}
