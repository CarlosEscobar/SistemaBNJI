#ifndef COMPRALIBRESINCONE_H
#define COMPRALIBRESINCONE_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtXml>
#include "confirmarvuelo1.h"

namespace Ui {
class CompraLibreSinCone;
}

class CompraLibreSinCone : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CompraLibreSinCone(QWidget *parent = 0);
    ~CompraLibreSinCone();

public slots:
    void openCompraLibre();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CompraLibreSinCone *ui;
    QStringListModel *model;
    ConfirmarVuelo1 *confi1;
};

#endif // COMPRALIBRESINCONE_H
