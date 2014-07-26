#ifndef COMPRABARATA_H
#define COMPRABARATA_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtXml>

namespace Ui {
class CompraBarata;
}

class CompraBarata : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CompraBarata(QWidget *parent = 0);
    ~CompraBarata();
    
private:
    Ui::CompraBarata *ui;
    QStringListModel *model;
};

#endif // COMPRABARATA_H
