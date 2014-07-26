#include "mundo_exop_cliente.h"
#include "ui_mundo_exop_cliente.h"

mundo_exop_cliente::mundo_exop_cliente(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mundo_exop_cliente)
{
    ui->setupUi(this);

    QPixmap pixmu("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/mundo.png");
    ui->label_mundo->setPixmap(pixmu);
    QPixmap pix2("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/logo2.png");
    ui->label_minilogo->setPixmap(pix2);

}

mundo_exop_cliente::~mundo_exop_cliente()
{
    delete ui;
}

void mundo_exop_cliente::setName(QString nam)
{
    ui->lineEdit_nomb->setText(nam);
}

void mundo_exop_cliente::openComprar()
{
    comp = new comprar(this);
    QString cc;
    cc="Forma Comprar";
    comp->setWindowTitle(cc);
    comp->setStyleSheet("QMainWindow {background: 'white';}");
    comp->show();
}

void mundo_exop_cliente::on_pushButton_comprar_clicked()
{
    openComprar();
}

void mundo_exop_cliente::paintEvent(QPaintEvent *f)
{
    QImage temp(ui->label_mundo->pixmap()->toImage());
    QPainter painter(&temp);
    QPen pen(Qt::red);
    pen.setWidth(10);
    QPen pen2(Qt::red);
    pen2.setWidth(2);

    QDomDocument doc;
    QFile filee("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AeropuertosXML.xml");

    if(!filee.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!doc.setContent(&filee))
        {
            qDebug() << "Failed to load document";
        }
        filee.close();
    }
    QDomElement root = doc.firstChildElement();
    QDomNodeList points = root.elementsByTagName("Aeropuerto");

    for(int i=0; i<points.count(); i++)
    {
        QDomNode pp = points.at(i);

        if(pp.isElement())
        {
            QDomElement p = pp.toElement();
            QString x = p.attribute("X");
            bool t;
            int xxx=x.toInt(&t,10);
            QString y = p.attribute("Y");
            bool tt;
            int yyy=y.toInt(&tt,10);

            QPoint p30;
            p30.setX(xxx-20);
            p30.setY(yyy-150);

            painter.setPen(pen);
            painter.drawPoint(p30);

            ui->label_mundo->setPixmap(QPixmap::fromImage(temp));
        }
    }

    QDomDocument docc;
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/LineasXML.xml");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!docc.setContent(&file))
        {
            qDebug() << "Failed to load document";
        }
        file.close();
    }
    QDomElement rooot = docc.firstChildElement();
    QDomNodeList lll = rooot.elementsByTagName("Linea");

    for(int i=0; i<lll.count(); i++)
    {
        QDomNode l = lll.at(i);

        if(l.isElement())
        {
            QDomElement p = l.toElement();
            QString x1 = p.attribute("X1");
            bool t;
            int xx1=x1.toInt(&t,10);
            QString y1 = p.attribute("Y1");
            bool tt;
            int yy1=y1.toInt(&tt,10);
            QString x2 = p.attribute("X2");
            bool ttt;
            int xx2=x2.toInt(&ttt,10);
            QString y2 = p.attribute("Y2");
            bool tttt;
            int yy2=y2.toInt(&tttt,10);

            QPoint p1;
            p1.setX(xx1-20);
            p1.setY(yy1-153);
            QPoint p2;
            p2.setX(xx2-20);
            p2.setY(yy2-153);

            painter.setPen(pen2);
            painter.drawLine(p1,p2);

            ui->label_mundo->setPixmap(QPixmap::fromImage(temp));
        }
    }


}
