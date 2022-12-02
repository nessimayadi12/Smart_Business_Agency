#include "pdf.h"
#include "ui_pdf.h"
#include"employe.h"
#include"mainwindow.h"
#include<QPdfWriter>
#include<QMessageBox>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
    setWindowTitle("PDF");
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushButton_clicked() // pdf //
{
    QPdfWriter pdf("C:/Users/khalil/OneDrive/Bureau/DETAILS.pdf");
    QPainter painter(&pdf);
    QString id = ui->line_pdf->text();
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from EMPLOYES where IDENTIFIANT_E= :id");
    test.bindValue(":id",id);
    test.exec();
    if (test.next())
    {
    if (test.value(0).toInt() == 1)
    {
    QSqlQuery query ;
    query.prepare("select IDENTIFIANT_E , NOM_E ,PRENOM_E , STATUS_E , PHONE_E , MAIL_E , AGE_E , SALAIRE_E , NATIONALITE_E , DATE_AJOUT_E , EMP_IDENTIFIANT_E from EMPLOYES where IDENTIFIANT_E= :id");
    query.bindValue(":id",id);
    query.exec();
    if (query.next())
    {
    QString ident = query.value(0).toString();
    QString nom = query.value(1).toString();
    QString prenom = query.value(2).toString();
    QString status = query.value(3).toString();
    QString phone = query.value(4).toString();
    QString mail= query.value(5).toString();
    QString age = query.value(6).toString();
    QString salary = query.value(7).toString();
    QString nat= query.value(8).toString();
    QString date = query.value(9).toString();
    QString id_chef = query.value(10).toString();

    painter.setPen(Qt::red);
    painter.drawText(600,500,"IDENTIFIANT : ");
    painter.drawText(600,700,"NOM : ");
    painter.drawText(600,900,"PRENOM : ");
    painter.drawText(600,1100,"STATUS : ");
    painter.drawText(600,1300,"PHONE NUMBER : ");
    painter.drawText(600,1500,"MAIL : ");
    painter.drawText(600,1700,"AGE : ");
    painter.drawText(600,1900,"SALARY : ");
    painter.drawText(600,2100,"NATIONALITY : ");
    painter.drawText(600,2300,"RECRRUITMENT DATE : ");
    painter.drawText(600,2500,"IDENTIFIANT CHEF : ");

    painter.setPen(Qt::black);
    painter.drawText(1500,500,ident);
    painter.drawText(1500,700,nom);
    painter.drawText(1500,900,prenom);
    painter.drawText(1500,1100,status);
    painter.drawText(1700,1300,phone);
    painter.drawText(1500,1500,mail);
    painter.drawText(1500,1700,age);
    painter.drawText(1500,1900,salary);
    painter.drawText(1700,2100,nat);
    painter.drawText(2000,2300,date);
    painter.drawText(1850,2500,id_chef);
    painter.end();

    }
    qDebug()<<"PDF EMPLOYEE DONE";
 }
  else
  {
     qDebug()<<"PDF EMPLOYEE NOT DONE";
  }
  }
}
