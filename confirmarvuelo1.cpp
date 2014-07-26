#include "confirmarvuelo1.h"
#include "ui_confirmarvuelo1.h"

ConfirmarVuelo1::ConfirmarVuelo1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfirmarVuelo1)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList list;

    QDomDocument dooc;
    QFile fiile("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/Conecte1XML.xml");

    if(!fiile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!dooc.setContent(&fiile))
        {
            qDebug() << "Failed to load document";
        }
        fiile.close();
    }

    QDomElement rooot = dooc.firstChildElement();
    QDomNodeList gg = rooot.elementsByTagName("Origen");
    QDomNode g = gg.at(0);

    if (g.isElement())
    {
        QDomElement e = g.toElement();
        QString y = e.attribute("Ori");

        int pl;
        bool p;
        pl = y.toInt(&p,10);
        origen=pl;
    }

    QDomDocument doc;
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AristasXML.xml");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!doc.setContent(&file))
        {
            qDebug() << "Failed to load document";
        }
        file.close();
    }

    QDomElement root = doc.firstChildElement();
    QDomNodeList names = root.elementsByTagName("Arista");

    for(int i=0; i<names.count(); i++)
    {
        QDomNode ae = names.at(i);
        if(ae.isElement())
        {
            QDomElement a = ae.toElement();
            QString x = a.attribute("Origen");
            bool t;
            int z=x.toInt(&t,10);
            QString y = a.attribute("NombreDestino");

            if(z == origen)
            {
                list<<y;
            }
        }
    }
    model->setStringList(list);

    ui->listView->setModel(model);

    QDomDocument oc;
    QFile fle("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AeropuertosXML.xml");

    if(!fle.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!oc.setContent(&fle))
        {
            qDebug() << "Failed to load document";
        }
        fle.close();
    }

    QDomElement rt = oc.firstChildElement();
    QDomNodeList namess = rt.elementsByTagName("Aeropuerto");

    for(int i=0; i<namess.count(); i++)
    {
        QDomNode ae = namess.at(i);
        if(ae.isElement())
        {
            QDomElement a = ae.toElement();
            QString x = a.attribute("Codigo");
            bool t;
            int z=x.toInt(&t,10);

            if(z == origen)
            {
                QString s = a.attribute("Nombre");
                ui->lineEdit_2->setText(s);
            }
        }
    }

}

ConfirmarVuelo1::~ConfirmarVuelo1()
{
    delete ui;
}

void ConfirmarVuelo1::setOrigen(int x)
{
    this->origen=x;
}

void ConfirmarVuelo1::on_toolButton_clicked()
{
    int row= ui->listView->currentIndex().row()+1;

    QDomDocument oc;
    QFile fle("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AristasXML.xml");

    if(!fle.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!oc.setContent(&fle))
        {
            qDebug() << "Failed to load document";
        }
        fle.close();
    }

    QDomElement rt = oc.firstChildElement();
    QDomNodeList namess = rt.elementsByTagName("Arista");

    int ya=0;

    for(int i=0; i<namess.count(); i++)
    {
        QDomNode ae = namess.at(i);
        if(ae.isElement())
        {
            QDomElement a = ae.toElement();
            QString x = a.attribute("Origen");
            bool t;
            int z=x.toInt(&t,10);

            if(z == origen)
            {
                ya++;
            }

            if(ya==row)
            {
                QString aa= a.attribute("Precio");
                ui->lineEdit_3->setText(aa);
            }
        }
    }
}

void ConfirmarVuelo1::on_toolButton_2_clicked()
{
    openBoleto();
    this->close();
}

void ConfirmarVuelo1::openBoleto()
{
    b = new Boleto(this);
    QString ccc;
    ccc="Boleto";
    b->setWindowTitle(ccc);
    b->setStyleSheet("QMainWindow {background: 'white';}");
    b->show();
}
