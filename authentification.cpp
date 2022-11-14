#include "authentification.h"
#include "ui_authentification.h"
#include <QMessageBox>
#include <QSound>
#include"mainwindow.h"
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
        menu.show();

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                   QObject::tr("INVALID USERNAME OR PASSWORD.\nClick Cancel to exit."), QMessageBox::Ok);
    }
}
