#include "compralibresincone.h"
#include "ui_compralibresincone.h"

CompraLibreSinCone::CompraLibreSinCone(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CompraLibreSinCone)
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
}

CompraLibreSinCone::~CompraLibreSinCone()
{
    delete ui;
}

void CompraLibreSinCone::openCompraLibre()
{
    int f=ui->comboBox->currentIndex()+1;
    confi1 = new ConfirmarVuelo1(this);
    confi1->setOrigen(f);
    QString mune;
    mune="Confirmar Vuelo";
    confi1->setWindowTitle(mune);
    confi1->setStyleSheet("QMainWindow {background: 'grey';}");
    confi1->show();
    this->close();
}

void CompraLibreSinCone::on_pushButton_clicked()
{
    openCompraLibre();

    int kk=ui->comboBox->currentIndex()+1;

    //Write XML
    QDomDocument document;

    //Make the root element
    QDomElement root = document.createElement("CompraLibre");

    //Add it to the document
    document.appendChild(root);

    QDomElement book = document.createElement("Origen");
    book.setAttribute("Ori", QString::number(kk));
    root.appendChild(book);


    //Write to file
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/Conecte1XML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open File for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << document.toString();
        file.close();
        qDebug() << "Finished";
    }
}
