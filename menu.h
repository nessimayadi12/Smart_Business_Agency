#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"
#include "gestion_missions.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_menu_employee_clicked();

    void on_menu_customers_clicked();

    void on_menu_sponsor_clicked();

    void on_menu_missions_clicked();

    void on_menu_transport_clicked();

public:
    Ui::menu *ui;
private:
    MainWindow khalil;
    gestion_missions Achref;
};

#endif // MENU_H
