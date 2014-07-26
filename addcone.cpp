#include "addcone.h"
#include "ui_addcone.h"

addCone::addCone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addCone)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList list;

    QDomDocument doc;
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AeropuertosXML.xml");

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
    QDomNodeList names = root.elementsByTagName("Aeropuerto");

    for(int i=0; i<names.count(); i++)
    {
        QDomNode ae = names.at(i);
        if(ae.isElement())
        {
            QDomElement a = ae.toElement();
            QString x = a.attribute("Nombre");
            list<<x;
        }
    }

    model->setStringList(list);
    ui->comboBox->setModel(model);
    ui->comboBox_2->setModel(model);
}

addCone::~addCone()
{
    delete ui;
}

void addCone::on_pushButton_clicked()
{
    origen=(ui->comboBox->currentIndex()+1);
    destino=(ui->comboBox_2->currentIndex()+1);
    QString p;
    p=ui->lineEdit->text();

    QString o = QString::number(origen);
    QString d = QString::number(destino);

    QDomDocument ddooc;
    QFile fil("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AeropuertosXML.xml");

    if(!fil.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    } else
    {
        if(!ddooc.setContent(&fil))
        {
            qDebug() << "Failed to load document";
        }
        fil.close();
    }

    QDomElement rooot = ddooc.firstChildElement();
    QDomNodeList names = rooot.elementsByTagName("Aeropuerto");
    QString nom;

    for(int i=0; i<names.count(); i++)
    {
        QDomNode ae = names.at(i);
        if(ae.isElement())
        {
            QDomElement a = ae.toElement();
            QString x = a.attribute("Codigo");

            if(d==x)
            {
                nom=a.attribute("Nombre");
            }
        }
    }

    ar = (*ari).createElement("Arista");
    ar.setAttribute("Origen", o);
    ar.setAttribute("Destino", d);
    ar.setAttribute("NombreDestino",nom);
    ar.setAttribute("Precio", p);
    (*root).appendChild(ar);

    this->close();
}
