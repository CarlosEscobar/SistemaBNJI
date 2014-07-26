#include "addaero.h"
#include "ui_addaero.h"

addAero::addAero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addAero)
{
    ui->setupUi(this);

}

addAero::~addAero()
{
    delete ui;
}

void addAero::setFacts(QString nn, QString xx, QString yy)
{
    ui->lineEdit_aero->setText(nn);
    ui->lineEdit_x->setText(xx);
    ui->lineEdit_y->setText(yy);
}

void addAero::on_pushButton_clicked()
{
    this->close();
}
