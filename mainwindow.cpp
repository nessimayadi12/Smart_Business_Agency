#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "clients.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>

//aaa

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(etmp.afficher());
    ui->tableView_2->setModel(etmp.afficherfacture());
    //controle de saisie
    ui->le_cin->setValidator(new QIntValidator(0,999999,this));
    ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->la_destination->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
    ui->le_numero->setValidator(new QIntValidator(0,999999,this));



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    clients res;


    res.setcin(ui->le_cin->text());
    res.setnom(ui->le_nom->text());
    res.setprenom(ui->le_prenom->text());
    res.setdestination(ui->la_destination->text());
    res.setdatedenaissance(ui->la_date->text());
    res.setnumero(ui->le_numero->text());
    bool test=res.ajouter();
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }
    ui->le_cin->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->la_destination->clear();
    ui->la_date->clear();
    ui->le_numero->clear();




}

void MainWindow::on_pb_supprimer_clicked()
{
    int cin=ui->le_cin->text().toInt();
    bool test=etmp.supprimer(cin);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }
}
void MainWindow::on_pb_modifier_clicked()
{
    clients res;
    int num0=ui->num_modif->text().toInt() ;
    res.setcin(ui->le_cin->text());
    res.setnom(ui->le_nom->text());
    res.setprenom(ui->le_prenom->text());
    res.setdestination(ui->la_destination->text());
    res.setdatedenaissance(ui->la_date->text());
    res.setnumero(ui->le_numero->text());
    bool test=res.modifier(num0);
    if(test)
    {
        ui->tableView->setModel(etmp.afficher());
    }

}
void MainWindow::on_radioButton_clicked()
{
    ui->tableView->setModel(etmp.triecin());
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView->setModel(etmp.trienumero());
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->tableView->setModel(etmp.triedatedenaissance());
}


void MainWindow::on_le_cin_2_textChanged(const QString &arg1)
{
    QString rech = ui->le_cin_2->text();

                     etmp.recherche(ui->tableView,rech);

                     if (ui->le_cin_2->text().isEmpty())

                     {

                         ui->tableView->setModel(etmp.afficher());

                     }
}


void MainWindow::on_pb_ajouter_2_clicked()
{
    etmp.telechargerPDF();



            QMessageBox::information(nullptr,QObject::tr("OK"),

                       QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}

void MainWindow::on_pb_stat_clicked()
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



void MainWindow::on_pb_ajouter_3_clicked()
{
    clients c1;
    QString nom=ui->name->text();
    QString periode=ui->la_periode->text();
    QString prix=ui->le_prix->text();
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

void MainWindow::on_pb_ajouter_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21652724070", QUrl::TolerantMode));
}
