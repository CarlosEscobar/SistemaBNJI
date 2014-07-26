#ifndef ADDCONE_H
#define ADDCONE_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtXml>

namespace Ui {
class addCone;
}

class addCone : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit addCone(QWidget *parent = 0);
    ~addCone();
    QDomDocument *ari;
    QDomElement *root;
    QDomElement ar;
    int origen;
    int destino;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::addCone *ui;
    QStringListModel *model;
};

#endif // ADDCONE_H
