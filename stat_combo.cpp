#include "stat_combo.h"
#include "ui_stat_combo.h"

stat_combo::stat_combo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}

//bar chart
void stat_combo::choix_bar()
{
QSqlQuery q1,q2,q3,q4,q5;
qreal tot=0,c1=0,c2=0,c3=0,c4=0;

q1.prepare("SELECT * FROM missions");
q1.exec();

q2.prepare("SELECT * FROM missions WHERE logement='Hotel'");
q2.exec();

q3.prepare("SELECT * FROM missions WHERE logement='Maison'");
q3.exec();

q3.prepare("SELECT * FROM missions WHERE logement='colocation'");
q4.exec();

q3.prepare("SELECT * FROM missions WHERE logement='AirBnB'");
q5.exec();

while (q1.next()){tot++;}
while (q2.next()){c1++;}
while (q3.next()){c2++;}
while (q4.next()){c3++;}
while (q5.next()){c4++;}


c1=c1/tot;
c2=c2/tot;
c3=c3/tot;
c4=c4/tot;

        QBarSet *set0 = new QBarSet("Hotel ");
        QBarSet *set1 = new QBarSet("Maison ");
        QBarSet *set2 = new QBarSet("colocation ");
        QBarSet *set3 = new QBarSet("AirBnB ");

        *set0 << c1;
        *set1 << c2;
        *set2 << c3;
        *set3 << c4;

        QBarSeries *series = new QBarSeries();


        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);

        QChart *chart = new QChart();

        chart->addSeries(series);

        QPalette pal = qApp->palette();

        pal.setColor(QPalette::Window, QRgb(0xffffff));
        pal.setColor(QPalette::WindowText, QRgb(0x404044));

        qApp->setPalette(pal);

chartView = new QChartView(chart,ui->label_stat);
chartView->setRenderHint(QPainter::Antialiasing);
chartView->setMinimumSize(400,400);

chartView->show();
}

    void stat_combo::choix_pie()
    {
        QSqlQuery q1,q2,q3,q4,q5;
        qreal tot=0,c1=0,c2=0,c3=0,c4=0;

        q1.prepare("SELECT * FROM missions");
        q1.exec();

        q2.prepare("SELECT * FROM missions WHERE logement='Hotel'");
        q2.exec();

        q3.prepare("SELECT * FROM missions WHERE logement='Maison'");
        q3.exec();

        q3.prepare("SELECT * FROM missions WHERE logement='colocation'");
        q4.exec();

        q3.prepare("SELECT * FROM missions WHERE logement='AirBnB'");
        q5.exec();

        while (q1.next()){tot++;}
        while (q2.next()){c1++;}
        while (q3.next()){c2++;}
        while (q4.next()){c3++;}
        while (q5.next()){c4++;}


        c1=c1/tot;
        c2=c2/tot;
        c3=c3/tot;
        c4=c4/tot;

    QPieSeries *series = new QPieSeries();
    series->append("Hotel",c1);
    series->append("Maison ",c2);
    series->append("colocation ",c3);
    series->append("AirBnB ",c4);

    QChart *chart = new QChart();


    chart->addSeries(series);
    chart->legend()->show();



    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);

    chartView->show();
    }
