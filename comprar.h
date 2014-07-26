#ifndef COMPRAR_H
#define COMPRAR_H
#include "compralibresincone.h"
#include "comprabarata.h"

#include <QMainWindow>

namespace Ui {
class comprar;
}

class comprar : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit comprar(QWidget *parent = 0);
    ~comprar();

public slots:
    void openCompraLibreSinCone();
    void openCompraBarata();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::comprar *ui;
    CompraLibreSinCone* complibsincone;
    CompraBarata* comprabar;
};

#endif // COMPRAR_H
