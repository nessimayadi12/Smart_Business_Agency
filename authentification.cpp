#include "ui_menu.h"
#include "authentification.h"
#include "ui_authentification.h"
#include <QMessageBox>
#include <QSound>
#include"mainwindow.h"
#include "menu.h"
#include <QThread>
authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
    setWindowTitle("LOGIN");
}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_pushButton_clicked()
{
    QString username = ui->userline->text();
    QString password = ui->passwordline->text();

    if (username == "khalil" && password == "khalil")
    {
        hide();
        m.show();
        m.ui->menu_sponsor->setEnabled(false);
        m.ui->menu_missions->setEnabled(false);
        m.ui->menu_customers->setEnabled(false);
        m.ui->menu_transport->setEnabled(false);
        qDebug()<<"choose your department";
    }
    else if (username == "jassem" && password == "jassem")
    {
        hide();
        m.show();
        m.ui->menu_sponsor->setEnabled(false);
        m.ui->menu_missions->setEnabled(false);
        m.ui->menu_employee->setEnabled(false);
        m.ui->menu_transport->setEnabled(false);
        qDebug()<<"choose your department";
    }
    else if (username == "nessim" && password == "nessim")
    {
        hide();
        m.show();
        m.ui->menu_sponsor->setEnabled(false);
        m.ui->menu_missions->setEnabled(false);
        m.ui->menu_employee->setEnabled(false);
        m.ui->menu_customers->setEnabled(false);
        qDebug()<<"choose your department";
    }
    else if (username == "achref" && password == "achref")
    {
        hide();
        m.show();
        m.ui->menu_sponsor->setEnabled(false);
        m.ui->menu_customers->setEnabled(false);
        m.ui->menu_employee->setEnabled(false);
        m.ui->menu_transport->setEnabled(false);
        qDebug()<<"choose your department";
    }
    else if (username == "sandid" && password == "sandid")
    {
        hide();
        m.show();
        m.ui->menu_employee->setEnabled(false);
        m.ui->menu_missions->setEnabled(false);
        m.ui->menu_customers->setEnabled(false);
        m.ui->menu_transport->setEnabled(false);
        qDebug()<<"choose your department";
    }

}
