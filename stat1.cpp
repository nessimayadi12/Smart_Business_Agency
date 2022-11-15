#include "stat1.h"
#include "ui_stat1.h"
#include <QString>
#include"employe.h"
#include<qsqlquery.h>
#include <qdebug.h>

stat1::stat1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat1)
{
    ui->setupUi(this);
    setWindowTitle("STATISTICS");
}

stat1::~stat1()
{
    delete ui;
}

void stat1::make_nationalite()
{
    qDebug()<<"pst";
    int total;
    int nat_tn ;
    int nat_fr=0 ;
    QString Nat_tn;
    QString Nat_fr;
    QSqlQuery q;
    q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES where NATIONALITE_E ='TN' ");
            q.exec();
            q.first() ;
            nat_tn=(q.value(0).toInt());
    q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES where NATIONALITE_E ='FR' ");
            q.exec();
            q.first() ;
            nat_fr=(q.value(0).toInt());
            q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES ");
                    q.exec();
                    q.first() ;
                    total=(q.value(0).toInt());
     nat_fr=((double)nat_fr/(double)total)*100;
     nat_tn = 100-nat_fr;
     Nat_tn = QString::number(nat_tn);
     Nat_fr = QString::number(nat_fr);

     QPieSeries *series;
              series= new  QPieSeries();
              series->append("TUNISIAN NATIONALITY "+Nat_tn+"%",nat_tn);
              series->append("FRENCH NATIONALITY "+Nat_fr+"%",nat_fr);
              QPieSlice *slice0 = series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);
                  slice1->setExploded();
                  slice1->setLabelVisible();
                  slice1->setPen(QPen(Qt::red, 2));
                  slice1->setBrush(Qt::blue);

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("Statistics on employees nationalities");
                   chart->legend()->show();
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
ui->verticalLayout1->addWidget(chartView);
qDebug()<<"pst";
}

void stat1::make_salary()
{
    int total;
    int nat_tn ;
    int nat_fr=0 ;
    QString Nat_tn;
    QString Nat_fr;
    QSqlQuery q;
    q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES where STATUS_E ='Online' ");
            q.exec();
            q.first() ;
            nat_tn=(q.value(0).toInt());
    q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES where STATUS_E ='Offline' ");
            q.exec();
            q.first() ;
            nat_fr=(q.value(0).toInt());
            q.prepare("SELECT COUNT(IDENTIFIANT_E) FROM EMPLOYES ");
                    q.exec();
                    q.first() ;
                    total=(q.value(0).toInt());
     nat_fr=((double)nat_fr/(double)total)*100;
     nat_tn = 100-nat_fr;
     Nat_tn = QString::number(nat_tn);
     Nat_fr = QString::number(nat_fr);

     QPieSeries *series;
              series= new  QPieSeries();
              series->append("ONLINE WORKERS"+Nat_tn+"%",nat_tn);
              series->append("OFFLINE WORKORS"+Nat_fr+"%",nat_fr);
              QPieSlice *slice0 = series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);
                  slice1->setExploded();
                  slice1->setLabelVisible();
                  slice1->setPen(QPen(Qt::blue, 2));
                  slice1->setBrush(Qt::red);

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("Employees work style statistics");
                   chart->legend()->show();
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
ui->verticalLayout2->addWidget(chartView);
qDebug()<<"pst";

}
