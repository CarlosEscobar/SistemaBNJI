#ifndef CONFIRMARVUELO1_H
#define CONFIRMARVUELO1_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtXml>
#include "boleto.h"

namespace Ui {
class ConfirmarVuelo1;
}

class ConfirmarVuelo1 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ConfirmarVuelo1(QWidget *parent = 0);
    ~ConfirmarVuelo1();

    int origen;

    void setOrigen(int x);
    
private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

protected:
    Boleto *b;

public slots:
    void openBoleto();

private:
    Ui::ConfirmarVuelo1 *ui;
    QStringListModel *model;

};

#endif // CONFIRMARVUELO1_H
