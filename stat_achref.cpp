#include "stat_achref.h"
#include "ui_stat_achref.h"
#include "QSqlQuery"

stat_achref::stat_achref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stat_achref)
{
    ui->setupUi(this);
}

stat_achref::~stat_achref()
{
    delete ui;
}

void stat_achref::make_logement()
{
    int total;
    int num_hotel ;
    int num_maison ;
    int num_airbnb=0 ;
    QString Num_hotel;
    QString Num_maison;
    QString Num_airbnb;
    QSqlQuery q;
    q.prepare("SELECT COUNT(ID_M) FROM MISSIONS where LOGEMENT = 'hotel'");
            q.exec();
            q.first() ;
            num_hotel=(q.value(0).toInt());
            q.prepare("SELECT COUNT(ID_M) FROM MISSIONS where LOGEMENT ='airbnb' ");
                    q.exec();
                    q.first() ;
                    num_airbnb=(q.value(0).toInt());
            q.prepare("SELECT COUNT(ID_M) FROM MISSIONS ");
                    q.exec();
                    q.first() ;
                    total=(q.value(0).toInt());
     num_hotel=((double)num_hotel/(double)total)*100; // stat mta3 hotel //
     num_airbnb = 100-num_hotel;
     Num_hotel = QString::number(num_hotel);
     Num_airbnb = QString::number(num_airbnb);


     QPieSeries *series;
              series= new  QPieSeries();
              series->append("HOTELS: "+Num_hotel+"%",num_hotel);
              series->append("AIRBNB: "+Num_airbnb+"%",num_airbnb);
              QPieSlice *slice0 = series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);
                  slice1->setExploded();
                  slice1->setLabelVisible();
                  slice1->setPen(QPen(Qt::blue, 2));
                  slice1->setBrush(Qt::red);

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("LOGEMENT STATISTICS");
                   chart->legend()->show();
                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
ui->achref_stat->addWidget(chartView);
qDebug()<<"stat achref done";
}
