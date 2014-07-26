#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "mainadmin.h"
#include <QString>

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit admin(QWidget *parent = 0);
    ~admin();

public slots:
    void openMainAdmin();
    
private slots:
    void on_continuar_admin_clicked();

private:
    Ui::admin *ui;
    mainadmin* mainad;
};

#endif // ADMIN_H
