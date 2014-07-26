#include "boleto.h"
#include "ui_boleto.h"

Boleto::Boleto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Boleto)
{
    ui->setupUi(this);
}

Boleto::~Boleto()
{
    delete ui;
}

void Boleto::on_pushButton_clicked()
{
    this->close();
}
