#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QSound>
#include"mainwindow.h"
#include "authentification.h"
#include "gestion_partenaire.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    setWindowTitle("MENU");
}

menu::~menu()
{
    delete ui;
}

void menu::on_menu_employee_clicked()
{
    qDebug()<<"WELCOME KHALIL";
    khalil.show();
}
void menu::on_menu_missions_clicked()
{
   qDebug()<<"welcome achref";
    Achref.show();
}

void menu::on_menu_clients_clicked()
{

    qDebug()<<"welcome jassem";
     jessem.show();
}

void menu::on_menu_partenaire_clicked()
{
    qDebug()<<"welcome mohamed";
     mohamed.show();
}



void menu::on_menu_transport_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME NESSIM"),
                               QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}



