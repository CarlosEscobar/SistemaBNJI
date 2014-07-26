#ifndef BOLETO_H
#define BOLETO_H

#include <QMainWindow>

namespace Ui {
class Boleto;
}

class Boleto : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Boleto(QWidget *parent = 0);
    ~Boleto();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Boleto *ui;
};

#endif // BOLETO_H
