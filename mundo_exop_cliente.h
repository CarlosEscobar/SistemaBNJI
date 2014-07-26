#ifndef MUNDO_EXOP_CLIENTE_H
#define MUNDO_EXOP_CLIENTE_H

#include <QMainWindow>
#include <QString>
#include "comprar.h"
#include <QtCore>
#include <QtXml>
#include <QDebug>
#include <QtGui>
#include <QPoint>

namespace Ui {
class mundo_exop_cliente;
}

class mundo_exop_cliente : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit mundo_exop_cliente(QWidget *parent = 0);
    ~mundo_exop_cliente();

    void setName(QString nam);
    void openComprar();
    
private slots:
    void on_pushButton_comprar_clicked();

private:
    Ui::mundo_exop_cliente *ui;
    comprar* comp;

protected:
    void paintEvent(QPaintEvent *f);
};

#endif // MUNDO_EXOP_CLIENTE_H
