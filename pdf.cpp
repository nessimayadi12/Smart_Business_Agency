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
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushButton_clicked() // pdf //
{
    QPdfWriter pdf("C:/Users/khalil/OneDrive/Bureau/5lil.pdf");
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
    query.prepare("select IDENTIFIANT_E , NOM_E ,PRENOM_E , STATUS_E , PHONE_E , MAIL_E from EMPLOYES where IDENTIFIANT_E= :id");
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
    painter.setPen(Qt::red);
    painter.drawText(100,300,"ERAAAA");
    painter.drawText(200,500,"IDENTIFIANT : ");
    painter.drawText(100,500,"NOM : ");
    painter.drawText(100,500,"PRENOM : ");
    painter.drawText(100,500,"STATUS : ");
    painter.drawText(100,500,"PHONE : ");

     painter.setPen(Qt::black);
    painter.drawText(720,500,ident);
    painter.drawText(720,700,nom);
    painter.drawText(720,900,prenom);
    painter.drawText(720,1100,status);
    painter.drawText(720,1300,phone);
    painter.drawText(720,1500,mail);
    painter.end();
    QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("pdf done.\n"
                                         "Click ok to exit."), QMessageBox::Ok);
    }
 }
  else
  {
      QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr("pdf not done.\n"
                                          "Click ok to exit."), QMessageBox::Ok);
  }
  }
}
