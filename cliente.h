#ifndef CLIENTE_H
#define CLIENTE_H

#include <QMainWindow>
#include "mundo_exop_cliente.h"
#include <QString>

namespace Ui {
class cliente;
}

class cliente : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit cliente(QWidget *parent = 0);
    ~cliente();

public slots:
    void openMundoExpo(QString x);
    
private slots:
    void on_continuar_cliente_clicked();

private:
    Ui::cliente *ui;
    mundo_exop_cliente* mundoexpo;
};

#endif // CLIENTE_H
