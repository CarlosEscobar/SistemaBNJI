#include "mainwindow.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QString s;
    s="Sistema de Aviones";
    w.setWindowTitle(s);
    w.setStyleSheet("QMainWindow {background: 'grey';}");
    w.show();
    
    return a.exec();
}
