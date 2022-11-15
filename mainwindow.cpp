#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include "mainwindow.h"
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
#include "stat1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Transport T;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//ajout

void MainWindow::on_enregistre_clicked()
{

    int identifiant_T=ui->id->text().toInt();
    float prix_T=ui->prixx->text().toInt();
    QString moyen_transport_T=ui->moyen->text() ;
    QString type_T=ui->typee->text();
    QString date_T=ui->datee->text();
    QString horaire_T=ui->horairee->text();
    QString lieu_depart_T=ui->lieudep->text();
    QString lieu_arrivee=ui->lieuarr->text();
    QString etat_T=ui->etatt->text();
    Transport T(identifiant_T,prix_T,moyen_transport_T, type_T, date_T, horaire_T, lieu_depart_T, lieu_arrivee, etat_T);

    T.ajouter(T);

                    ui->tab_transport->setModel(T.afficher());

        }





//suppression
void MainWindow::on_pb_supprimer_clicked()
{
    Transport T;
    T.setidentifiant_T(ui->id_supp->text().toInt());
    T.supprimer(T);
    ui->id_supp->setText("");
    ui->tab_transport->setModel(T.afficher());

       }


//modifier
void MainWindow::on_pb_modifier_clicked()
{

        int identifiant_T=ui->id_2->text().toInt();
        float prix_T=ui->prixx_2->text().toInt();
        QString moyen_transport_T=ui->moyen_2->text() ;
        QString type_T=ui->typee->text();
        QString date_T=ui->datee_2->text();
        QString horaire_T=ui->horairee_2->text();
        QString lieu_depart_T=ui->lieudep_2->text();
        QString lieu_arrivee=ui->lieuarr_2->text();
        QString etat_T=ui->etatt_2->text();
        Transport T (identifiant_T,prix_T,moyen_transport_T, type_T, date_T, horaire_T, lieu_depart_T, lieu_arrivee, etat_T);
        T.modifier(T);
        ui->tab_transport->setModel(T.afficher());

}


//chercher

void MainWindow::on_chercher_clicked()
    {
        Transport T;
    int rech_id =ui->id_ch->text().toInt();;
    ui->tab_transport->setModel(T.chercher_transport(rech_id));
    }



void MainWindow::on_afficher_clicked()
{
    Transport T;
    //afficher selon le prix
    if(QString::number(ui->comboBox->currentIndex())=="0"){
     ui->tab_transport->setModel(T.afficher_client_trie_prix());
    }
    //afficher selon la date
    else if(QString::number(ui->comboBox->currentIndex())=="1"){
        ui->tab_transport->setModel(T.afficher_client_trie_date());
    }
}


void MainWindow::on_pushButton_qr_clicked()
{
    if(ui->tab_transport->currentIndex().row()==-1)
                           QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                                    QObject::tr("Veuillez Choisir un employé du Tableau.\n"
                                                                "Click Ok to exit."), QMessageBox::Ok);
                       else
                       {
                            int  identifiant_T=ui->tab_transport->model()->data(ui->tab_transport->model()->index(ui->tab_transport->currentIndex().row(),0)).toInt();
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





//export PDF

void MainWindow::on_pushButton_pdf_clicked()

{



       int identifiant_T=ui->id->text().toInt();
       QString id_pdf=QString::number(identifiant_T);
       float prix_T=ui->prixx->text().toInt();
       QString prix_pdf=QString::number(prix_T);
       QString moyen_transport_T=ui->moyen->text() ;
       QString type_T=ui->typee->text();
       QString date_T=ui->datee->text();
       //QString date_pdf=QString::Date(date_T);


       QString horaire_T=ui->horairee->text();
       QString lieu_depart_T=ui->lieudep->text();
       QString lieu_arrivee=ui->lieuarr->text();
       QString etat_T=ui->etatt->text();



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
         painter.drawText(100,450,"Type:");
         painter.drawText(100,500,"date:");
         painter.drawText(100,550,"horaire:");
         painter.drawText(100,600,"lieu de depart: ");
         painter.drawText(100,650,"lieu d'e depart'arriver: ");
         painter.drawText(100,650,"lieu d'e depart'arriver: ");
         painter.drawText(100,700,"etat: ");

         painter.setFont(font);
              painter.setPen(Qt::black);
              painter.drawText(300,300,id_pdf);
              painter.drawText(300,350,prix_pdf);
              painter.drawText(300,400,moyen_transport_T);
              painter.drawText(300,450,type_T);
              painter.drawText(300,500,date_T);
              painter.drawText(300,550,horaire_T);
              painter.drawText(300,600,lieu_depart_T);
              painter.drawText(300,650,lieu_arrivee);
              painter.drawText(300,700,etat_T);

QDesktopServices::openUrl(QUrl("transport.pdf"));

         painter.end();

}


void MainWindow::on_pushButton_stat_clicked()
{ stat1 *w = new stat1();
    w->make_moytransport();

    w->show();

}


