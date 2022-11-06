#include "modify.h"
#include "ui_modify.h"
#include "mainwindow.h"
#include "employe.h"
#include "QMessageBox"

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


void modify::on_confirm_clicked()
{
    QString id = ui->lineID_edit->text();
    QString status = ui->comboBox_edit->currentText();
    QString phone = ui->linePhone_edit->text();
    QString mail = ui->lineMail_edit->text();
    int salaire = ui->lineSal_edit->text().toInt();
    QString id_emp = ui->line_ID_chef_edit->text();

    Employe e(id,status, mail, phone,salaire,id_emp);
    bool test_modify = e.Modifier(id,status,mail,phone,salaire,id_emp);
    if (test_modify)
    {
        ui->table_modify->setModel(e.Afficher());
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    else
    { QMessageBox::information(nullptr, QObject::tr("database is not open"),
                            QObject::tr("NOT DONE.\nClick Cancel to exit."), QMessageBox::Ok);
    qDebug() << "test";
    }
}
