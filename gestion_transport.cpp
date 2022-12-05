#include "gestion_transport.h"
#include "ui_gestion_transport.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"QDate"
#include "transport.h"
#include<QObject>
#include <QMessageBox>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDir>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QDesktopServices>
#include <QHeaderView>
#include "QImage"
#include <QPainter>
#include "iostream"
#include<QtCharts/QtCharts>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include "qrcode.h"
#include "qrwidget.h"
#include "qrcodegenerateworker.h"
#include <QtDebug>
#include <QVariant>
#include <QString>
#include "excel.h"

gestion_transport::gestion_transport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gestion_transport)
{
    ui->setupUi(this);
    ui->tableView->setModel(T.afficher());
}

gestion_transport::~gestion_transport()
{
    delete ui;
}
//ajouter//

void gestion_transport::on_pushButton_ajouter_2_clicked()
{
    QString identifiant_T=ui->id->text();
    int prix = ui->prix->text().toInt();
    QString moyen_transport =ui->moyt->text() ;
    QString date = ui->date->text();
    QString horaire =ui->horaire->text();
    QString lieu_depart =ui->lieudep->text();
    QString lieu_arrivee =ui->lieuar->text();
    transport m(identifiant_T,prix,moyen_transport,date,horaire,lieu_depart,lieu_arrivee);
    bool test = true ;
    if (test)
    {
        m.Ajouter();
        QMessageBox::information(nullptr, QObject::tr("ADD EMPLOYEE"),
                                     QObject::tr("THE EMPLOYEE HAS BEEN ADDED SUCCESSFULLY.\nClick Cancel to exit."), QMessageBox::Ok);
        ui->tableView->setModel(m.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ADD EMPLOYEE"),
                                QObject::tr("THE EMPLOYEE HAS NOT BEEN ADDED SUCCESSFULLY.\nClick Cancel to exit."), QMessageBox::Ok);
    }
}

//modifier

void gestion_transport::on_pushButton_modifier_2_clicked()
{bool modif;
    QString identifiant_T=ui->id->text();
    int prix_T=ui->prix->text().toInt();
    QString id_a_modif=ui->id_a_modif->text();
    QString moyen_transport_T=ui->moyt->text() ;
    QString date_T=ui->date->text();
    QString horaire_T=ui->horaire->text();
    QString lieu_depart_T=ui->lieudep->text();
    QString lieu_arrivee=ui->lieuar->text();


   //transport m (identifiant_T,prix_T,moyen_transport_T,date_T, horaire_T, lieu_depart_T, lieu_arrivee);
   modif= m.modifier(id_a_modif,identifiant_T,prix_T,moyen_transport_T,date_T, horaire_T, lieu_depart_T, lieu_arrivee);

    if(modif)
      {
        ui->tableView->setModel(m.afficher());

      QMessageBox::information(nullptr, QObject::tr("modifier le reservation de transport"),
                        QObject::tr("reservation de transport modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier le reservation de transport"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);




}


//EXPORT pdf

void gestion_transport::on_pushButton_pdf_clicked()
{
       QString identifiant_T=ui->id->text();
       int prix_T=ui->prix->text().toInt();
       QString prix_pdf=QString::number(prix_T);
       QString moyen_transport_T=ui->moyt->text() ;
       QString date_T=ui->date->text();
       QString horaire_T=ui->horaire->text();
       QString lieu_depart_T=ui->lieudep->text();
       QString lieu_arrivee=ui->lieuar->text();

    QPrinter printer;
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName("transport.pdf");
         QPainter painter;
         painter.begin(&printer);
         QFont font;

         font.setPixelSize(40);
         painter.setFont(font);
         painter.setPen(Qt::red);
         painter.drawText(250,150,"Fiche Des Réservation des transport : ");
         font.setPixelSize(20);
         painter.setFont(font);
         painter.setPen(Qt::red);
         painter.drawText(100,300,"identifiant: ");
         painter.drawText(100,350,"Prix: ");
         painter.drawText(100,400,"moyen de transport ::");
         painter.drawText(100,450,"date:");
         painter.drawText(100,500,"horaire:");
         painter.drawText(100,550,"lieu de depart: ");
         painter.drawText(100,600,"lieu d'arriver: ");


         painter.setFont(font);
              painter.setPen(Qt::black);
              painter.drawText(300,300,identifiant_T);
              painter.drawText(300,350,prix_pdf);
              painter.drawText(300,400,moyen_transport_T);
              painter.drawText(300,450,date_T);
              painter.drawText(300,500,horaire_T);
              painter.drawText(300,550,lieu_depart_T);
              painter.drawText(300,600,lieu_arrivee);

QDesktopServices::openUrl(QUrl("transport.pdf"));

         painter.end();

}

void gestion_transport::on_pushButton_clicked()
{
    QString identifiant_T=ui->id->text();
    int prix_T=ui->prix->text().toInt();
    QString prix_pdf=QString::number(prix_T);
    QString moyen_transport_T=ui->moyt->text() ;
    QString date_T=ui->date->text();
    QString horaire_T=ui->horaire->text();
    QString lieu_depart_T=ui->lieudep->text();
    QString lieu_arrivee=ui->lieuar->text();

 QPrinter printer;
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("transport.pdf");
      QPainter painter;
      painter.begin(&printer);
      QFont font;

      font.setPixelSize(40);
      painter.setFont(font);
      painter.setPen(Qt::red);
      painter.drawText(250,150,"Fiche Des Réservation des transport : ");
      font.setPixelSize(20);
      painter.setFont(font);
      painter.setPen(Qt::red);
      painter.drawText(100,300,"identifiant: ");
      painter.drawText(100,350,"Prix: ");
      painter.drawText(100,400,"moyen de transport ::");
      painter.drawText(100,450,"date:");
      painter.drawText(100,500,"horaire:");
      painter.drawText(100,550,"lieu de depart: ");
      painter.drawText(100,600,"lieu d'arriver: ");


      painter.setFont(font);
           painter.setPen(Qt::black);
           painter.drawText(300,300,identifiant_T);
           painter.drawText(300,350,prix_pdf);
           painter.drawText(300,400,moyen_transport_T);
           painter.drawText(300,450,date_T);
           painter.drawText(300,500,horaire_T);
           painter.drawText(300,550,lieu_depart_T);
           painter.drawText(300,600,lieu_arrivee);

QDesktopServices::openUrl(QUrl("transport.pdf"));

      painter.end();

}



void gestion_transport::on_pushButton_pdf_2_clicked()
{
    QString identifiant_T=ui->id->text();
    int prix_T=ui->prix->text().toInt();
    QString prix_pdf=QString::number(prix_T);
    QString moyen_transport_T=ui->moyt->text() ;
    QString date_T=ui->date->text();
    QString horaire_T=ui->horaire->text();
    QString lieu_depart_T=ui->lieudep->text();
    QString lieu_arrivee=ui->lieuar->text();

 QPrinter printer;
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("transport.pdf");
      QPainter painter;
      painter.begin(&printer);
      QFont font;

      font.setPixelSize(40);
      painter.setFont(font);
      painter.setPen(Qt::red);
      painter.drawText(250,150,"Fiche Des Réservation des transport : ");
      font.setPixelSize(20);
      painter.setFont(font);
      painter.setPen(Qt::red);
      painter.drawText(100,300,"identifiant: ");
      painter.drawText(100,350,"Prix: ");
      painter.drawText(100,400,"moyen de transport ::");
      painter.drawText(100,450,"date:");
      painter.drawText(100,500,"horaire:");
      painter.drawText(100,550,"lieu de depart: ");
      painter.drawText(100,600,"lieu d'arriver: ");


      painter.setFont(font);
           painter.setPen(Qt::black);
           painter.drawText(300,300,identifiant_T);
           painter.drawText(300,350,prix_pdf);
           painter.drawText(300,400,moyen_transport_T);
           painter.drawText(300,450,date_T);
           painter.drawText(300,500,horaire_T);
           painter.drawText(300,550,lieu_depart_T);
           painter.drawText(300,600,lieu_arrivee);

QDesktopServices::openUrl(QUrl("transport.pdf"));

      painter.end();

}


//qr


void gestion_transport::on_pushButton_qr_3_clicked()
{
    if(ui->tableView->currentIndex().row()==-1)
                           QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                    QObject::tr("Veuillez Choisir un employé du Tableau.\n"
                                                                "Click Ok to exit."), QMessageBox::Ok);
                       else
                       {

        int  identifiant_T=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
        const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(std::to_string(identifiant_T).c_str(), qrcodegen::QrCode::Ecc::LOW);
                             std::ofstream myfile;
                             myfile.open ("qrcode.svg") ;
                                myfile << qr.toSvgString(2);
                                myfile.close();
                                QSvgRenderer svgRenderer(QString("qrcode.svg"));
                                QPixmap pix( QSize(90, 90));
                                QPainter pixPainter( &pix );
                                svgRenderer.render(&pixPainter);
                             ui->label_15->setPixmap(pix);
                        }
}



void gestion_transport::on_delete_transport_clicked()
{
    QString d=ui->id_2->text();
    bool test=supp.supprimer(d);
        if(test)
        {

             QMessageBox::information(nullptr, QObject::tr("DELETE EMPLOYEE"),
                                     QObject::tr("THE EMPLOYEE HAS BEEN DELETED SUCCESSFULLY.\n"
                                                 "CLICK OK TO RETURN."), QMessageBox::Ok);
              }
                  else
            {
            QMessageBox::information(nullptr, QObject::tr("DELETE EMPLOYEE"),
                                  QObject::tr("THE EMPLOYEE DOES NOT EXIST.\n"
                                            "CLICK OK TO RETURN."), QMessageBox::Ok);
            }

         ui->tableView->setModel(T.afficher());
}

void gestion_transport::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM TRANSPORT WHERE IDENTIFIANT_T= :IDENTIFIANT_T");
    qry.bindValue(":IDENTIFIANT_T",val);
    if(qry.exec())
    {
        while(qry.next())
        {


             ui->id->setText(qry.value(0).toString());
             ui->prix->setText(qry.value(1).toString());
             ui->moyt->setText(qry.value(2).toString());
             ui->date ->setText(qry.value(2).toString());
             ui->horaire ->setText(qry.value(3).toString());
             ui->lieudep ->setText(qry.value(4).toString());
             ui->lieuar->setText(qry.value(5).toString());
             ui->id_a_modif->setText(qry.value(0).toString());

        }
    }
}

void gestion_transport::on_id_ch_textChanged(const QString &arg1)
{
    ui->tableView->setModel(m.researchid(arg1));


}

void gestion_transport::on_comboBox_currentIndexChanged(int index)
{
    if(index==1)
        ui->tableView->setModel(m.tri_id_asc());
    if(index==0)
        ui->tableView->setModel(m.tri_id_desc());
}



void gestion_transport::on_pushButton_afficher_clicked()
{
     QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                      tr("Excel Files (*.xls)"));
      if (fileName.isEmpty())
          return;

      ExportExcel obj(fileName, "gestion transport", ui->tableView);

      //colums to export
      obj.addField(0, "IDENTIFIANT_T", "char(20)");
      obj.addField(1, "PRIX_T", "int");
      obj.addField(2, "MOYEN_TRANSPORT_T", "char(20)");
      obj.addField(3, "DATE_T", "int");
      obj.addField(4, "HORAIRE_T", "char(20)");
      obj.addField(5, "LIEU_DEPART_T", "char(20)");
      obj.addField(6, "LIEU_ARRIVEE", "char(20)");





      int retVal = obj.export2Excel();
      if( retVal > 0)
      {
          QMessageBox::information(this, tr("Done"),
                                   tr("Toutes les informations ont été enregistrée"));
      }
}



void gestion_transport::on_pushButton_stat_clicked()
{
      m.stat_transport();
}
