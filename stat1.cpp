#include "stat1.h"
#include "ui_stat1.h"
#include <QString>
#include"transport.h"
#include<qsqlquery.h>
#include <qdebug.h>
stat1::stat1(QWidget *parent) :
     QDialog(parent),
     ui(new Ui::stat1)
{
    ui->setupUi(this);
}

stat1::~stat1()
{
    delete ui;
}

void stat1::make_moytransport()
{
    qDebug()<<"pst";
    int total;
    int avion ;
    int bus=0 ;
    QString Avion;
    QString Bus;
    QSqlQuery q;
    q.prepare("SELECT COUNT(identifiant_T) FROM TRANSPORT where moyen_transport_T ='avion' ");
            q.exec();
            q.first() ;
            avion=(q.value(0).toInt());
    q.prepare("COUNT(identifiant_T) FROM TRANSPORT where moyen_transport_T ='bus' ");
            q.exec();
            q.first() ;
            bus=(q.value(0).toInt());
            q.prepare("COUNT(identifiant_T) FROM TRANSPORT  ");
                    q.exec();
                    q.first() ;
                    total=(q.value(0).toInt());
     avion=((double)avion/(double)total)*100;
     bus = 100-avion;
     Bus = QString::number(bus);
     Avion = QString::number(avion);

     QPieSeries *series;
              series= new  QPieSeries();
              series->append("transport avec bus"+Bus+"%",bus);
              series->append("transport avec avion"+Avion+"%",avion);
              QPieSlice *slice0 = series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);
                  slice1->setExploded();
                  slice1->setLabelVisible();
                  slice1->setPen(QPen(Qt::darkRed, 2));
                  slice1->setBrush(Qt::black);

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("Statistiques sur les transport resérver par les client");
                   chart->legend()->show();
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   qDebug()<<"pst";
ui->verticalLayout1->addWidget(chartView);
}
