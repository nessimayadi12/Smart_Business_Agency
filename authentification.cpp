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
    QString user ;
    QString pswd ;
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from LOGIN where USERNAME= :username");
    test.bindValue(":username",username);
    test.exec();
    if (test.next())
    {
    if (test.value(0).toInt() == 1)
    {
    QSqlQuery query ;
    query.prepare("SELECT USERNAME,PASSWORD FROM LOGIN WHERE USERNAME= :username");
    query.bindValue(":username",username);
    query.exec();
    if (query.next())
    {
    user = query.value(0).toString();
    pswd = query.value(1).toString();
    if (username == user && password == pswd)
    {
        QStringList myOptions;
        myOptions << "khalil" << "nessim" << "jassem" << "achref" <<"sandid"<<"admin";
        switch(myOptions.indexOf(user)){
          case 0:
            hide();

                    m.show();
                    m.ui->menu_sponsor->setEnabled(false);
                    m.ui->menu_missions->setEnabled(false);
                    m.ui->menu_clients->setEnabled(false);
                    m.ui->menu_transport->setEnabled(false);
            break;
          case 1:
            hide();
                   m.show();
                   m.ui->menu_sponsor->setEnabled(false);
                   m.ui->menu_missions->setEnabled(false);
                   m.ui->menu_employee->setEnabled(false);
                   m.ui->menu_clients->setEnabled(false);
            break;
        case 2 :
            hide();
                   m.show();
                   m.ui->menu_sponsor->setEnabled(false);
                   m.ui->menu_missions->setEnabled(false);
                   m.ui->menu_employee->setEnabled(false);
                   m.ui->menu_transport->setEnabled(false);
            break ;
        case 3 :
            hide();
                   m.show();
                   m.ui->menu_sponsor->setEnabled(false);
                   m.ui->menu_clients->setEnabled(false);
                   m.ui->menu_employee->setEnabled(false);
                   m.ui->menu_transport->setEnabled(false);
            break ;
        case 4 :
            hide();
                    m.show();
                    m.ui->menu_employee->setEnabled(false);
                    m.ui->menu_missions->setEnabled(false);
                    m.ui->menu_clients->setEnabled(false);
                    m.ui->menu_transport->setEnabled(false);
            break ;
        case 5 :
            hide();
                   m.show();
            break ;
    }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INCORRECT USERNAME OR PASSWORD.\nCLICK CANCEL TO RETURN."), QMessageBox::Ok);
    }
    }
    }
}
}
