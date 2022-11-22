#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QSound>
#include"mainwindow.h"
#include "authentification.h"

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

void menu::on_menu_customers_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME JASSEM"),
                               QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}

void menu::on_menu_sponsor_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME SANDID"),
                               QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}

void menu::on_menu_missions_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME ACHREF"),
                               QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}

void menu::on_menu_transport_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("WELCOME NESSIM"),
                               QObject::tr("LOADING.\nClick Cancel to exit."), QMessageBox::Ok);
}

