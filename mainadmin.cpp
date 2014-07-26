#include "mainadmin.h"
#include "ui_mainadmin.h"

mainadmin::mainadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainadmin)
{
    ui->setupUi(this);

    aero=0;
    ui->lineEdit->setText("0");
    ui->lineEdit_name->setText("");
    first=1;
    ui->label_error->hide();

    QPixmap pixm("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/mundo.png");
    ui->label_mun->setPixmap(pixm);
    QPixmap pixl("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/logo2.png");
    ui->label_logoo->setPixmap(pixl);

    root_aeros=aeropuertos.createElement("Aeropuertos");
    aeropuertos.appendChild(root_aeros);

    root_lineas=lineas.createElement("Lineas");
    lineas.appendChild(root_lineas);

    root_aristas=aristas.createElement("Aristas");
    aristas.appendChild(root_aristas);

    entro=0;
}

mainadmin::~mainadmin()
{
    delete ui;
}

void mainadmin::openAddCone()
{
    adcn = new addCone(this);
    QString ccc;
    ccc="Agregando Conexion";
    adcn->setWindowTitle(ccc);
    adcn->setStyleSheet("QMainWindow {background: 'white';}");
    adcn->ari=&aristas;
    adcn->root=&root_aristas;
    adcn->show();
}

void mainadmin :: mousePressEvent(QMouseEvent *e)
{
    if ((ui->addAero->isChecked()) && (ui->addCone->isChecked()==false))
    {
        mFirstX=0;
        mFirstY=0;
        mFirstClick=true;
        mpaintflag=false;

        if(e->button() == Qt::LeftButton)
        {
            if(mFirstClick)
            {
                mFirstX = e->x();
                mFirstY = e->y();
                mFirstClick = false;
                mpaintflag = true;

                if ((mFirstX>20) && (mFirstX<720) && (mFirstY>150) && (mFirstY<610))
                {
                    if(ui->lineEdit_name->text()=="")
                    {
                        ui->label_error->show();
                    } else
                    {
                        aero++;
                        entro=1;
                        ui->label_error->hide();
                        QString ae = QString::number(aero);
                        QString xx = QString::number(mFirstX);
                        QString yy = QString::number(mFirstY);
                        ui->lineEdit->setText(ae);
                        ui->lineEdit_num->setText(ae);
                        ui->lineEdit_x->setText(xx);
                        ui->lineEdit_y->setText(yy);

                        QString name;
                        name=ui->lineEdit_name->text();

                        aerop = aeropuertos.createElement("Aeropuerto");
                        aerop.setAttribute("Codigo", ae);
                        aerop.setAttribute("Nombre", name);
                        aerop.setAttribute("X", xx);
                        aerop.setAttribute("Y", yy);
                        root_aeros.appendChild(aerop);

                        qDebug() << "First image's coordinates" << mFirstX << "," << mFirstY ;
                        update();
                    }
                }
            }
        }
    }

    if ((ui->addCone->isChecked()) && (ui->addAero->isChecked()==false))
    {

        if(e->button() == Qt::LeftButton)
        {
            if (first==1)
            {
                lx1=-1;
                ly1=-1;
                lFClick=true;
                lSClick=false;
                lpflag=false;
                lpflag2=false;
            } else
            {
                lx2=3;
                ly2=3;
            }


            if((lFClick) && (lx1==-1) && (ly1==-1))
            {
                lx1 = e->x();
                ly1 = e->y();

                if ((lx1>20) && (lx1<720) && (ly1>150) && (ly1<610))
                {
                    first++;
                    lx2=-1;
                    ly2=-1;
                    lFClick = false;
                    lSClick=true;
                    lpflag = true;
                    qDebug() << "First point's coordinates" << lx1 << "," << ly1 ;
                }
            }

            if ((lSClick) && (lx2!=-1) && (ly2!=-1))
            {
                lx2 = e->x();
                ly2 = e->y();

                if ((lx2>20) && (lx2<720) && (ly2>150) && (ly2<610))
                {
                    lFClick=true;
                    lSClick=false;
                    lpflag2=true;
                    qDebug() << "Second point's coordinates" << lx2 << "," << ly2 ;
                    first--;

                    QString xx1 = QString::number(lx1);
                    QString yy1 = QString::number(ly1);
                    QString xx2 = QString::number(lx2);
                    QString yy2 = QString::number(ly2);

                    line = lineas.createElement("Linea");
                    line.setAttribute("X1", xx1);
                    line.setAttribute("Y1", yy1);
                    line.setAttribute("X2", xx2);
                    line.setAttribute("Y2", yy2);
                    root_lineas.appendChild(line);

                    update();
                    openAddCone();
                }
            }
        }
    }
}

void mainadmin::paintEvent(QPaintEvent *f)
{
    QImage temp(ui->label_mun->pixmap()->toImage());
    QPainter painter(&temp);

    QPen pen(Qt::red);
    pen.setWidth(10);

    QPen pen2(Qt::red);
    pen2.setWidth(2);


    if ((ui->addAero->isChecked()) && (ui->addCone->isChecked()==false) && (entro>0))
    {
        QPoint p3;
        p3.setX(mFirstX-20);
        p3.setY(mFirstY-150);

        painter.setPen(pen);
        painter.drawPoint(p3);
        entro=0;
    }

    if ((ui->addCone->isChecked()) && (ui->addAero->isChecked()==false) && (lx2!=-1) && (ly2!=-1) && (lFClick))
    {
        painter.setPen(pen2);
        QPoint p1;
        p1.setX(lx1-20);
        p1.setY(ly1-153);

        QPoint p2;
        p2.setX(lx2-20);
        p2.setY(ly2-153);

        painter.drawLine(p1,p2);
    }

    ui->label_mun->setPixmap(QPixmap::fromImage(temp));
}

void mainadmin::on_toolButton_2_clicked()
{
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AeropuertosXML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open File for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << aeropuertos.toString();
        file.close();
    }


}

void mainadmin::on_pushButton_clicked()
{
    ui->lineEdit_name->clear();
    ui->lineEdit_num->clear();
    ui->lineEdit_x->clear();
    ui->lineEdit_y->clear();
}

void mainadmin::on_pushButton_2_clicked()
{
    QFile file("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/LineasXML.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open File for writting";
    }
    else
    {
        QTextStream stream(&file);
        stream << lineas.toString();
        file.close();
    }

    QFile filee("C:/Users/carlosa/Documents/UNITEC/Año 2014/Semestre 1/Parcial 1/Estructura de Datos/PROYECTO2/SistemaBNJI/AristasXML.xml");
    if(!filee.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open File for writting";
    }
    else
    {
        QTextStream stream(&filee);
        stream << aristas.toString();
        filee.close();
    }

    this->close();
}
