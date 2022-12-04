#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QPdfWriter>
#include<QPainter>


//aaaa
client::client()
{
    cin="";
    nom="";
    prenom="";
    destination="";
    datedenaissance="";
    numero="";
    num0="";
}
 //client::client(QString cin,QString nom,QString prenom,QString destination,QString datedenaissance,QString numero,QString num0)
 //;{this->cin=cin; this->nom=nom;this->prenom=prenom;this->destination=destination;this->datedenaissance=datedenaissance;this->numero=numero;this->num0=num0}
 QString client::get_cin(){return cin;}
 QString client::get_nom(){return nom;}
 QString client::get_prenom(){return prenom;}
 QString client::get_destination(){return destination;}
 QString client::get_datedenaissance(){return datedenaissance;}
 QString client:: get_numero(){return numero;}
 QString client:: get_num0(){return num0;}

 void client::setcin(QString cin){this->cin=cin;}
 void client::setnom(QString nom){this->nom=nom;}
 void client::setprenom(QString prenom){this->prenom=prenom;}
 void client::setdestination(QString destination){this->destination=destination;}
 void client::setdatedenaissance(QString datedenaissance){this->datedenaissance=datedenaissance;}
 void client::setnumero(QString numero){this->numero=numero;}
 void client::setnum0(QString num0){this->num0=num0;}

 bool client::ajouter()
 {
     QSqlQuery query;



           query.prepare("insert into CLIENT (CIN_C, NOM_C, PRENOM_C,DESTINATION_C,DATEDENAISSANCE_C,NUMERO) "
                         "values (:cin, :nom, :prenom, :destination, :datedenaissance, :numero)");
           query.bindValue(":cin", cin);
           query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":destination", destination);
           query.bindValue(":datedenaissance", datedenaissance);
           query.bindValue(":numero", numero);
           return query.exec();
 }
 bool client::supprimer(int cin)
 {
     QSqlQuery query;
     QString res=QString::number(cin);
     query.prepare("delete from CLIENT where CIN_C= :cin");
     query.bindValue(":cin",res);
     return query.exec();
 }
 QSqlQueryModel * client::afficher()
 {
     QSqlQueryModel * model=new QSqlQueryModel () ;
     model->setQuery("select * from CLIENT");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_C"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_C"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_C"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESTINATION_C"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATEDENAISSANCE_C"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("NUMERO_C"));
     return model;

 }
 bool client::modifier(int num0)
 {
     QSqlQuery query;
     QString res=QString::number(num0);

           query.prepare("update CLIENT set CIN_C=:cin, NOM_C=:nom,PRENOM_C=:prenom,DESTINATION_C=:destination,DATEDENAISSANCE_C=:datedenaissance,NUMERO=:numero Where CIN_C=:num0 ");
           query.bindValue(":num0",res);
           query.bindValue(":cin", cin);
           query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":destination", destination);
           query.bindValue(":datedenaissance", datedenaissance);
           query.bindValue(":numero", numero);


           return query.exec();
 }
 QSqlQueryModel * client::triecin()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENT ORDER BY CIN_C");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_C"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_C"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("PRENOM_C"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DESTINATION_C"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEDENAISSANCE_C"));
     model->setHeaderData(5, Qt::Horizontal, QObject:: tr("NUMERO"));

     return model;
 }
 QSqlQueryModel * client::trienumero()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENT ORDER BY NUMERO");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_C"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_C"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("PRENOM_C"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DESTINATION_C"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEDENAISSANCE_C"));
     model->setHeaderData(5, Qt::Horizontal, QObject:: tr("NUMERO"));

     return model;
 }
 QSqlQueryModel * client::triedatedenaissance()
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM CLIENT ORDER BY DATEDENAISSANCE_C");
     model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_C"));
     model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_C"));
     model->setHeaderData(2, Qt::Horizontal, QObject:: tr("PRENOM_C"));
     model->setHeaderData(3, Qt::Horizontal, QObject:: tr("DESTINATION_C"));
     model->setHeaderData(4, Qt::Horizontal, QObject:: tr("DATEDENAISSANCE_C"));
     model->setHeaderData(5, Qt::Horizontal, QObject:: tr("NUMERO"));

     return model;
 }
 void client::recherche(QTableView * table, QString rech)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery *query=new QSqlQuery;
         query->prepare("select * from CLIENT where NOM_C like '%"+rech+"%' or DESTINATION_C like '%"+rech+"%' or PRENOM_C like '%"+rech+"%';");
         query->exec();
         model->setQuery(*query);
         table->setModel(model);
         table->show();
 }
 void  client::telechargerPDF(){

                      QPdfWriter pdf("C:/Users/user/OneDrive/Bureau/exportpdf/PDF.pdf");



                      QPainter painter(&pdf);
                     int i = 4000;



                          painter.setPen(Qt::blue);
                           painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                          painter.drawText(2000,1500,"LISTES DES client");
                          painter.setPen(Qt::black);
                          painter.drawRect(0,2700,9600,500);
                          painter.setFont(QFont("Calibri",14,QFont::Bold));
                          painter.drawText(200,3000,"cin");
                          painter.drawText(1800,3000,"nom");
                          painter.drawText(3100,3000,"prenom");
                          painter.drawText(4900,3000,"destination");
                          painter.drawText(6800,3000,"date naissance");
                          painter.drawText(8600,3000,"numero");



                          QSqlQuery query;

                          query.prepare("select * from CLIENT");
                          query.exec();
                          while (query.next())
                          {
                                 painter.setFont(QFont("Calibri",13));
                              painter.drawText(200,i,query.value(1).toString());
                              painter.drawText(1800,i,query.value(0).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(4900,i,query.value(3).toString());
                              painter.drawText(6900,i,query.value(4).toString());
                              painter.drawText(8600,i,query.value(5).toString());



                             i = i + 500;
                          }}
 bool client::facture(QString nom,QString periode,QString prix,QString total)
 {

     QSqlQuery query;

     query.prepare("INSERT INTO FACTURE(NOM, PERIODE, PRIX , TOTAL)"
                    "VALUES (:NOM, :PERIODE, :PRIX, :TOTAL)");
      query.bindValue(":NOM",nom);
      query.bindValue(":PERIODE",periode);
      query.bindValue(":PRIX",prix);
      query.bindValue(":TOTAL",total);
      return query.exec();
 }
 QSqlQueryModel*    client::afficherfacture()
 {



     QSqlQueryModel* model=new QSqlQueryModel();

           model->setQuery("SELECT* from FACTURE");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("PERIODE "));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX  "));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("TOTAL "));


     return model;

 }





