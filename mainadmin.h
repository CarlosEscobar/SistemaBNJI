#ifndef MAINADMIN_H
#define MAINADMIN_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QPoint>
#include <QString>
#include <QtXml>
#include <QDebug>

#include "addcone.h"

namespace Ui {
class mainadmin;
}

class mainadmin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit mainadmin(QWidget *parent = 0);
    ~mainadmin();
    int mFirstX;
    int mFirstY;
    int lx1;
    int lx2;
    int ly1;
    int ly2;
    bool mFirstClick;
    bool mpaintflag;
    bool lFClick;
    bool lSClick;
    bool lpflag;
    bool lpflag2;
    int first;

    int aero;
    int entro;

    QDomDocument aeropuertos;
    QDomElement root_aeros;
    QDomElement aerop;

    QDomDocument lineas;
    QDomElement root_lineas;
    QDomElement line;
    
    QDomDocument aristas;
    QDomElement root_aristas;

public slots:
    void openAddCone();

private:
    Ui::mainadmin *ui;

protected:
    void paintEvent(QPaintEvent *f);
    void mousePressEvent(QMouseEvent * e);

protected:
    addCone* adcn;

private slots:
    void on_toolButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAINADMIN_H
