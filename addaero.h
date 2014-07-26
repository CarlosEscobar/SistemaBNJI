#ifndef ADDAERO_H
#define ADDAERO_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class addAero;
}

class addAero : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit addAero(QWidget *parent = 0);
    ~addAero();

    QString num;
    QString x;
    QString y;

    void setFacts(QString nn, QString xx, QString yy);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::addAero *ui;
};

#endif // ADDAERO_H
