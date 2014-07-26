#include "cliente.h"
#include "ui_cliente.h"


cliente::cliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cliente)
{
    ui->setupUi(this);
}

cliente::~cliente()
{
    delete ui;
}

void cliente::openMundoExpo(QString x)
{
    mundoexpo = new mundo_exop_cliente(this);
    QString mune;
    mune="Exposicion Aeropuertos Internacionales";
    mundoexpo->setWindowTitle(mune);
    mundoexpo->setStyleSheet("QMainWindow {background: 'grey';}");
    mundoexpo->setName(x);
    mundoexpo->show();
}

void cliente::on_continuar_cliente_clicked()
{
    QString nom;
    nom=ui->lineEdit_nombre->text();
    openMundoExpo(nom);
}
