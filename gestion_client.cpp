#include "gestion_client.h"
#include "ui_gestion_client.h"

#include "connection.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QValidator>
#include <QPixmap>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include "stat_achref.h"



gestion_client::~gestion_client()
{
    delete ui;
}



   gestion_client::gestion_client(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::gestion_client)
{

       ui->setupUi(this);

       ui->tableView->setModel(etmp.afficher());
       ui->tableView_2->setModel(etmp.afficherfacture());
       //controle de saisie
       ui->lineEdit_cin->setValidator(new QIntValidator(0,999999,this));
       ui->lineEdit_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->lineEdit_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->lineEdit_destination->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->lineEdit_numero->setValidator(new QIntValidator(0,999999,this));
}


void gestion_client::on_pb_ajouter_client_clicked()
{
    client res;


    res.setcin(ui->lineEdit_cin->text());
    res.setnom(ui->lineEdit_nom->text());
    res.setprenom(ui->lineEdit_prenom->text());
    res.setdestination(ui->lineEdit_destination->text());
    res.setdatedenaissance(ui->lineEdit_date->text());
    res.setnumero(ui->lineEdit_numero->text());
    bool test=res.ajouter();
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }
    ui->lineEdit_cin->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_destination->clear();
    ui->lineEdit_date->clear();
    ui->lineEdit_numero->clear();
}

void gestion_client::on_pb_supprimer_client_clicked()
{
    int cin=ui->lineEdit_cin->text().toInt();
    bool test=etmp.supprimer(cin);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }
}

void gestion_client::on_pb_modifier_client_clicked()
{
    client res;
    int num0=ui->lineEdit_num_modif->text().toInt() ;
    res.setcin(ui->lineEdit_cin->text());
    res.setnom(ui->lineEdit_nom->text());
    res.setprenom(ui->lineEdit_prenom->text());
    res.setdestination(ui->lineEdit_destination->text());
    res.setdatedenaissance(ui->lineEdit_date->text());
    res.setnumero(ui->lineEdit_numero->text());
    bool test=res.modifier(num0);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }
}


void gestion_client::on_radioButton_cin_clicked()
{
    ui->tableView->setModel(etmp.triecin());
}


void gestion_client::on_radioButton_num_clicked()
{
    ui->tableView->setModel(etmp.trienumero());
}

void gestion_client::on_radioButton_date_clicked()
{
    ui->tableView->setModel(etmp.triedatedenaissance());
}

void gestion_client::on_lineEdit_rech_cin_textChanged(const QString &arg1)
{
    QString rech = ui->lineEdit_rech_cin->text();

                     etmp.recherche(ui->tableView,rech);

                     if (ui->lineEdit_rech_cin->text().isEmpty())

                     {

                         ui->tableView->setModel(etmp.afficher());

                     }
}

void gestion_client::on_pb_PDF_client_clicked()
{
    etmp.telechargerPDF();



            QMessageBox::information(nullptr,QObject::tr("OK"),

                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}

void gestion_client::on_pb_stat_client_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from CLIENT where DESTINATION_C = 'tunis'");
                   float dispo1=model->rowCount();

                   model->setQuery("select * from CLIENT where DESTINATION_C = 'espagne'");
                   float dispo=model->rowCount();

                   model->setQuery("select * from CLIENT where DESTINATION_C = 'france'");
                   float dispo3=model->rowCount();

                   float total=dispo1+dispo+dispo3;
                       QString a=QString("tunis " +QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("espagne " +QString::number((dispo*100)/total,'f',2)+"%" );
                       QString c=QString("france  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a,dispo1);
                       series->append(b,dispo);
                       series->append(c,dispo3);
                   if (dispo1!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}
                   if ( dispo!=0)
                   {
                       QPieSlice *slice1 = series->slices().at(1);
                       slice1->setLabelVisible();
                       slice1->setPen(QPen());
                   }
                   if (dispo3!=0)
                   {QPieSlice *slice = series->slices().at(2);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}

                   QChart *chart = new QChart();


                   chart->addSeries(series);
                   chart->setTitle("Nombre: "+ QString::number(total));



                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1300,800);
                   chartView->show();
}

void gestion_client::on_pb_facture_client_clicked()
{
    client c1;
    QString nom=ui->lineEdit_name->text();
    QString periode=ui->lineEdit_periode->text();
    QString prix=ui->lineEdit_prix->text();
    int total=prix.toInt()*periode.toInt();
    QString totals=QString::number(total);
    bool test=c1.facture(nom,periode,prix,totals);
    float totalt=0;

    ui->tableView_2->setModel(c1.afficherfacture());
    //calcul total total
    QSqlQuery query;
    query.prepare("SELECT total FROM FACTURE " );
    while(query.next())
    {
        totalt+=query.value(3).toInt();
    }
    query.exec();
    totals=QString::number(totalt);
    //ui->ltotal->setText(totals);
}



void gestion_client::on_pb_whatsapp_client_clicked()
{

    QDesktopServices::openUrl(QUrl("https://wa.me/+21652724070", QUrl::TolerantMode));
}
