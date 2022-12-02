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
    QString i = ui->line_id_m->text();
    QString s = ui->combo_s_m->currentText();
    QString m = ui->line_m_m->text();
    QString p = ui->line_p_m->text();
    int sa = ui->line_salaire_m->text().toInt();
    QString id_emp = ui->line_idchef_m->text();
    Employe e(i,s,p,m,sa,id_emp);
    bool test_modify = e.Modifier(i,s,p,m,sa,id_emp);
    if (test_modify)
    {
        qDebug() << "modify employee done ";
        ui->table_modify->setModel(e.Afficher());
        QMessageBox::information(nullptr, QObject::tr("MODIFY EMPLOYEE"),
                                 QObject::tr("DONE.\nClick OK to exit."), QMessageBox::Ok);
    }
    else
    {
         qDebug() << "modify employee not done ";
        QMessageBox::information(nullptr, QObject::tr("MODIFY EMPLOYEE"),
                            QObject::tr("NOT DONE.\nClick OK to exit."), QMessageBox::Ok);
    }
}
