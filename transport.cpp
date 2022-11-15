#include "transport.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QString>
#include"QDate"
#include <QTableView>
#include <QMessageBox>

//constructeur
Transport::Transport()
{
   identifiant_T=0;
    prix_T=0;
    moyen_transport_T="";
    type_T="";
    date_T="";
    horaire_T="";
    lieu_depart_T="";
    lieu_arrivee="";
    etat_T="";
    rech_id=0;


}



//constructeur
Transport::Transport(int identifiant_T,float prix_T,QString moyen_transport_T,QString type_T,QString date_T,QString horaire_T,QString lieu_depart_T,QString lieu_arrivee,QString etat_T)

{
    this->identifiant_T=identifiant_T;
    this->prix_T=prix_T;
    this->moyen_transport_T=moyen_transport_T;
    this->type_T=type_T;
    this->date_T=date_T;
    this->horaire_T=horaire_T;
    this->lieu_depart_T=lieu_depart_T;
    this->lieu_arrivee=lieu_arrivee;
    this->etat_T=etat_T;
}



//setters
void Transport:: setidentifiant_T(int identifiant_T  ){this->identifiant_T=identifiant_T;}
void Transport::setprix_T(float prix_T ){this->prix_T=prix_T;}
void Transport:: setmoyen_transport_T(QString moyen_transport_T ){this->moyen_transport_T=moyen_transport_T;}
void Transport:: settype_T(QString type_T){this->type_T=type_T;}
void Transport:: setdate_T(QString date_T ){this->date_T=date_T;}
void Transport:: sethoraire_T(QString horaire_T){this->horaire_T=horaire_T;}
void Transport:: setlieu_depart_T(QString lieu_depart_T ){this->lieu_depart_T=lieu_depart_T;}
void Transport:: setlieu_arrivee(QString lieu_arrivee ){this->lieu_arrivee=lieu_arrivee;}
void Transport:: setetat_T(QString etat_T ){this->etat_T=etat_T;}


//getters
int Transport:: getidentifiant_T(){return identifiant_T;}
float Transport:: getprix_T(){return prix_T;}
QString Transport:: getmoyen_transport_T(){return moyen_transport_T;}
QString Transport:: gettype_T(){return type_T;}
QString Transport:: getdate_T(){return date_T;}
QString Transport:: gethoraire_T(){return horaire_T;}
QString Transport:: getlieu_depart_T(){return lieu_depart_T;}
QString Transport::getlieu_arrivee(){return lieu_arrivee;}
QString Transport:: getetat_T(){return etat_T;}
int Transport::getrech_id(){return rech_id;}


//ajout

void Transport::ajouter(Transport T)
{
 QSqlQuery query;
 QString identifiant_string= QString::number(identifiant_T);
 QString prix_string= QString::number(prix_T);

 QString sQuery="INSERT INTO TRANSPORT (identifiant_T,prix_T,moyen_transport_T,type_T,date_T,horaire_T,lieu_depart_T,lieu_arrivee,etat_T) VALUES (:identifiant_T,:prix_T,:moyen_transport_T,:type_T, :date_T,:horaire_T,:lieu_depart_T, :lieu_arrivee, :etat_T)";

      query.prepare(sQuery);
      query.bindValue(":identifiant_T",identifiant_string);
      query.bindValue(":prix_T",prix_string);
      query.bindValue(":moyen_transport_T",moyen_transport_T);
      query.bindValue(":type_T",type_T);
      query.bindValue(":date_T",date_T);
      query.bindValue(":horaire_T", horaire_T);
      query.bindValue(":lieu_depart_T",lieu_depart_T);
      query.bindValue(":lieu_arrivee",lieu_arrivee);
      query.bindValue(":etat_T",etat_T);

   if(query.exec())
   {
      QMessageBox:: critical(nullptr, QObject::tr("OK"),
                                         QObject::tr("Ajout effectué\n"
                                                     "click cancel to exit."),QMessageBox::Cancel);

      }
  else
     { QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Ajout non effectué.\n"
                                        "click Cancel to exit."),QMessageBox::Cancel);}




}




//suppression

void Transport::supprimer(Transport T)
{
    QString id=QString::number(identifiant_T);
    QSqlQuery query;
    QString sQuery="Delete from TRANSPORT where id='"+id+"'";
         query.prepare(sQuery);

         if(query.exec())
         {

             QMessageBox::information(nullptr,QObject::tr("Suppression d'un reservation de transport"),
                                      QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

     }






//affichage
QSqlQueryModel* Transport::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM TRANSPORT");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant_T"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix_T"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("moyen_transport_T"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("type_T"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("date_T"));
   model->setHeaderData(5,Qt::Horizontal,QObject::tr("horaire_T"));
   model->setHeaderData(6,Qt::Horizontal,QObject::tr("lieu_depart_T"));
   model->setHeaderData(7,Qt::Horizontal,QObject::tr("lieu_arrivee"));
   model->setHeaderData(8,Qt::Horizontal,QObject::tr("etat_T"));

  return  model;
}




//modifier

void  Transport:: modifier(Transport T)

 {
     QSqlQuery query ;
     QString identifiant_string= QString::number(identifiant_T);
     QString prix_string= QString::number(prix_T);

     query.prepare("update TRANSPORT set identifiant_T=:identifiant_T ,date_T=:date_T, horaire_T=:horaire_T, prix_T=:prix_T,moyen_transport_T=:moyen_transport_T,type_T=:type_T, lieu_depart_T=:lieu_depart_T,lieu_arrivee=:lieu_arrivee,etat_T=:etat_T");

     query.bindValue(":identifiant_T",identifiant_string);
     query.bindValue(":date_T",date_T);
     query.bindValue(":horaire_T",horaire_T);
     query.bindValue(":prix_T",prix_string);
     query.bindValue(":moyen_transport_T",moyen_transport_T);
     query.bindValue(":type_T",type_T);
     query.bindValue(":lieu_depart_T",lieu_depart_T);
     query.bindValue(":lieu_arrivee",lieu_arrivee);
     query.bindValue(":etat_T",etat_T);

   if(query.exec())
     {

     QMessageBox::information(nullptr, QObject::tr("modifier le reservation de transport"),
                       QObject::tr("reservation de transport modifié.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

     }
       else
           QMessageBox::critical(nullptr, QObject::tr("modifier le reservation de transport"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


}

//chercher

QSqlQueryModel *Transport::chercher_transport(int rech_id)
{

    QString sQuery("select * from Transport where identifiant_T:=rech_id ");
    QSqlQueryModel * model4 = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(sQuery);

    query.exec();


  return model4;
}



//trie prix
QSqlQueryModel* Transport::afficher_client_trie_prix(){
    QString sQuery="SELECT * FROM TRANSPORT ORDER BY prix_T";

    QSqlQueryModel*model1=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model1->setQuery(qry);
return model1;
}



//trie date
QSqlQueryModel* Transport::afficher_client_trie_date(){
    QString sQuery="SELECT * FROM TRANSPORT ORDER BY date_T";

    QSqlQueryModel*model2=new QSqlQueryModel();

    QSqlQuery qry;

    qry.prepare(sQuery);

    qry.exec();
    model2->setQuery(qry);
return model2;
}

