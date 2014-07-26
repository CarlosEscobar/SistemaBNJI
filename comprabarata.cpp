#include "comprabarata.h"
#include "ui_comprabarata.h"

CompraBarata::CompraBarata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CompraBarata)
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

CompraBarata::~CompraBarata()
{
    delete ui;
}
