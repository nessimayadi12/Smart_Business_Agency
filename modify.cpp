#include "modify.h"
#include "ui_modify.h"
#include "mainwindow.h"
#include "employe.h"
#include "QMessageBox"
#include<QSound>

modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
    ui->setupUi(this);
    ui->table_modify->setModel(e.Afficher());
    qDebug()<<"start";
}

modify::~modify()
{
    delete ui;
}


void modify::on_pushButton_clicked()
{
    QString id = ui->line_id_m->text();
    QString status = ui->combo_s_m->currentText();
    QString phone = ui->line_p_m->text();
    QString mail = ui->line_m_m->text();
    int salaire = ui->line_salaire_m->text().toInt();
    QString id_emp = ui->line_idchef_m->text();
    Employe e(id,status,phone,mail,salaire,id_emp);
    bool test_modify = e.Modifier(id,status,phone,mail,salaire,id_emp);
    if (test_modify)
    {

        qDebug() << "test";
        ui->table_modify->setModel(e.Afficher());
        QMessageBox::information(nullptr, QObject::tr("YESS :)"),
                                 QObject::tr("DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("SORRY -_-"),
                            QObject::tr("NOT DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
}
