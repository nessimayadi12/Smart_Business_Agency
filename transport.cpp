#include "transport.h"
#include <QDebug>
#include <QSqlQuery>

#include <QtWidgets>
#include<QObject>
#include <QtCharts>
#include <QColor>
#include <QtSql>
#include <cmath>
#include <QtWidgets>
#include <QTextCharFormat>
bool transport::modifier(QString id_a_modif,QString id ,int p,QString moy ,QString d ,QString h ,QString ld ,QString la)

{
     QSqlQuery query ;
     QString prix_string= QString::number(p);

     query.prepare("UPDATE TRANSPORT SET identifiant_T= :identifiant_T , date_T= :date_T, horaire_T= :horaire_T, prix_T= :prix_T, moyen_transport_T= :moyen_transport_T, lieu_depart_T= :lieu_depart_T, lieu_arrivee= :lieu_arrivee where identifiant_T= :id_a_modif ");

     query.bindValue(":identifiant_T",id);
     query.bindValue(":id_a_modif",id_a_modif);

     query.bindValue(":date_T",d);
     query.bindValue(":horaire_T",h);
     query.bindValue(":prix_T",prix_string);
     query.bindValue(":moyen_transport_T",moy);
     query.bindValue(":lieu_depart_T",ld);
     query.bindValue(":lieu_arrivee",la);
     return  query.exec();


}
// ajout bara nchlh zena //
bool transport::Ajouter()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO TRANSPORT(identifiant_T,prix_T,moyen_transport_T,date_T,horaire_T,lieu_depart_T,lieu_arrivee)VALUES( :id, :prix, :moyen, :date, :horaire, :lieu_depart, :lieu_arrivee)");
    query.bindValue(":id",this->getidentifiant_T());
    query.bindValue(":prix",this->getprix_T());
    query.bindValue(":moyen",this->getmoyen_transport_T());
    query.bindValue(":date",this->getdate_T());
    query.bindValue(":horaire", this->gethoraire_T());
    query.bindValue(":lieu_depart", this->getlieu_depart_T());
    query.bindValue(":lieu_arrivee", this->getlieu_arrivee());
    return  query.exec();
}

//suppression mregla //

bool transport::supprimer(QString id)
{
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from TRANSPORT where identifiant_T= :id");
    test.bindValue(":id",id);
    test.exec();
    if (test.next())
    {
  if (test.value(0).toInt() == 1)
  {
      QSqlQuery query ;
      query.prepare("Delete from TRANSPORT where IDENTIFIANT_T= :id");
      query.bindValue(":id",id);
      return query.exec();
  }
     else
      return false;
    }
}

//affichage mregl //
QSqlQueryModel* transport::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT identifiant_T,prix_T,moyen_transport_T,date_T,horaire_T,lieu_depart_T,lieu_arrivee FROM TRANSPORT");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prix"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("MoyenTransport"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("horaire"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("Lieu de depart"));
   model->setHeaderData(6,Qt::Horizontal,QObject::tr("Lieu d'arrivee"));

  return  model;
}

//chercher

QSqlQueryModel * transport::researchid(QString i)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM TRANSPORT where IDENTIFIANT_T Like'%"+i+"%'" ); //Acces au contenu de la table
    return model;
}
QSqlQueryModel* transport::tri_id_asc()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM TRANSPORT ORDER BY PRIX_T ASC");
    return model;
}
QSqlQueryModel* transport::tri_id_desc()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM TRANSPORT ORDER BY PRIX_T DESC");
    return model;
}


//stat

void transport::stat_transport(){
QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("select * from TRANSPORT where MOYEN_TRANSPORT_T='avion' ");
 int number1=model->rowCount();
 model->setQuery("select * from TRANSPORT where MOYEN_TRANSPORT_T='bus' ");
 int number2=model->rowCount();
model->setQuery("select * from TRANSPORT where MOYEN_TRANSPORT_T='voiture' ");
 int number3=model->rowCount();
model->setQuery("select * from TRANSPORT where MOYEN_TRANSPORT_T='bateau' ");
 int number4=model->rowCount();


 int total=number1+number2+number3+number4;

 QString a = QString("avion"+QString::number((number1*100)/total,'f',2)+"%" );
 QString b = QString("bus"+QString::number((number2*100)/total,'f',2)+"%" );
 QString c = QString("voiture"+QString::number((number3*100)/total,'f',2)+"%" );
 QString d = QString("bateau" +QString::number((number4*100)/total,'f',2)+"%" );

QPieSeries *series = new QPieSeries();
 series->append(a,number1);
 series->append(b,number2);
 series->append(c,number3);
 series->append(d,number4);
 if (number1!= 0)
 {
     QPieSlice *slice = series->slices().at(0);
     slice->setLabelVisible();
     slice->setPen(QPen());
 }
 if (number2!=0)
 {
          QPieSlice *slice1 = series->slices().at(1);
          slice1->setLabelVisible();
 }
 if(number3!=0)
 {
          QPieSlice *slice2 = series->slices().at(2);
          slice2->setLabelVisible();
 }
 if(number4!=0)
 {
          QPieSlice *slice3 = series->slices().at(3);
          slice3->setLabelVisible();
 }

         // Create the chart widget
         QChart *chart = new QChart();
         // Add data to chart with title and hide legend
         chart->addSeries(series);
         chart->setTitle("Pourcentage par moyen de transport "+ QString::number(total));
         chart->legend()->hide();
         // Used to display the chart
         QChartView *chartView = new QChartView(chart);
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(1000,500);
         chartView->show();

}
