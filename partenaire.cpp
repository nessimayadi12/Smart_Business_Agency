#include "partenaire.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QPdfWriter>
#include<QPainter>

partenaire::partenaire ()
{cin=""; nom="";local="";nom_soc="";num="";mail="";modi="";}

partenaire::partenaire (QString cin, QString nom,QString local,QString nom_soc,QString num,QString mail,QString modi)
{this->cin=cin;this->nom=nom;this->local=local;this->nom_soc=nom_soc;this->num=num;this->mail=mail;this->modi=modi;}

  QString partenaire::getcin(){return cin;}
 QString partenaire::getnom(){return nom;}
 QString partenaire::getlocal(){return local;}
 QString partenaire::getnom_soc() {return nom_soc;}
 QString partenaire::getnum(){return num;}
 QString partenaire::getmail(){return mail;}
QString partenaire::getmodi(){return modi;}

 void partenaire::setcin(QString cin){this->cin=cin;}
 void partenaire::setnom(QString nom){this->nom=nom;}
  void partenaire::setlocal(QString local){this->local=local;}
   void partenaire::setnom_soc(QString nom_soc){this->nom_soc=nom_soc;}
    void partenaire::setnum(QString num){this->num=num;}
    void partenaire::setmail(QString mail){this->mail=mail;}
    void partenaire::setmodi(QString modi){this->modi=modi;}


    bool partenaire::ajouter(){

        QSqlQuery query;

       // QString cin_string= QString::number(cin);
        // QString num_string= QString::number(num);

//REQU2TE SQL
        query.prepare("INSERT INTO PARTENAIRE(CIN_P,NOM_P,LOCAL_P,NOM_SOCIETE_P,NUM_TEL_P,MAIL_P)VALUES (:cin,:nom,:local,:nom_soc,:num,:mail)");

        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":local",local);
        query.bindValue(":nom_soc",nom_soc);
        query.bindValue(":num",num);
        query.bindValue(":mail",mail);
        return    query.exec();

    }

    bool partenaire::supprimer(int cin)
    {
        QSqlQuery query;
        QString cin_string= QString::number(cin);

         query.prepare("Delete from PARTENAIRE where CIN_P=:cin");
         query.bindValue(":cin",cin_string);
          return    query.exec();
    }


    QSqlQueryModel * partenaire::afficher()
    {
        QSqlQueryModel * model =new QSqlQueryModel();
        model->setQuery("select * from PARTENAIRE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("LOCAL"));
                model->setHeaderData(3,Qt::Horizontal,QObject::tr("SOCITE"));
                model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL"));
                model->setHeaderData(5,Qt::Horizontal,QObject::tr("MAIL"));
                return  model;
    }

    bool partenaire::modifier(int modi)
     {
         QSqlQuery query;
         QString res=QString::number(modi);

               query.prepare("update PARTENAIRE set CIN_P=:cin,NOM_P=:nom,LOCAL_P=:local,NOM_SOCIETE_P=:nom_soc,NUM_TEL_P=:num,MAIL_P=:mail where CIN_P=:modi");
               query.bindValue(":modi",res);
               query.bindValue(":cin", cin);
               query.bindValue(":nom",nom);
               query.bindValue(":local",local);
               query.bindValue(":nom_soc",nom_soc);
               query.bindValue(":num",num);
               query.bindValue(":mail",mail);


               return query.exec();
     }
    QSqlQueryModel * partenaire::triecin()
     {
         QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PARTENAIRE ORDER BY CIN_P");
         model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_P"));
         model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_P"));
         model->setHeaderData(2, Qt::Horizontal, QObject:: tr("LOCAL_P"));
         model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NOM_SOCIETE_P"));
         model->setHeaderData(4, Qt::Horizontal, QObject:: tr("NUM_TEL_P"));
         model->setHeaderData(5, Qt::Horizontal, QObject:: tr("MAIL_P"));

         return model;
     }
     QSqlQueryModel * partenaire::trienum_tel()
     {
         QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PARTENAIRE ORDER BY NUM_TEL_P");
         model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_P"));
         model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_P"));
         model->setHeaderData(2, Qt::Horizontal, QObject:: tr("LOCAL_P"));
         model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NOM_SOCIETE_P"));
         model->setHeaderData(4, Qt::Horizontal, QObject:: tr("NUM_TEL_P"));
         model->setHeaderData(5, Qt::Horizontal, QObject:: tr("MAIL_P"));

         return model;
     }
     QSqlQueryModel * partenaire::trienom()
     {
         QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PARTENAIRE ORDER BY NOM_P");
         model->setHeaderData(0, Qt::Horizontal,QObject:: tr("CIN_P"));
         model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM_P"));
         model->setHeaderData(2, Qt::Horizontal, QObject:: tr("LOCAL_P"));
         model->setHeaderData(3, Qt::Horizontal, QObject:: tr("NOM_SOCIETE_P"));
         model->setHeaderData(4, Qt::Horizontal, QObject:: tr("NUM_TEL_P"));
         model->setHeaderData(5, Qt::Horizontal, QObject:: tr("MAIL_P"));

         return model;
     }
     void partenaire::recherche(QTableView * table, QString rech)
      {
          QSqlQueryModel *model= new QSqlQueryModel();
          QSqlQuery *query=new QSqlQuery;
              query->prepare("select * from PARTENAIRE where NOM_P like '%"+rech+"%' or LOCAL_P like '%"+rech+"%' or NOM_SOCIETE_P like '%"+rech+"%';");
              query->exec();
              model->setQuery(*query);
              table->setModel(model);
              table->show();

      }

     void  partenaire::telechargerPDF(){

                           QPdfWriter pdf("C:/Users/elbootic.com/Desktop/ExportPDF/PDF.pdf");



                           QPainter painter(&pdf);
                          int i = 4000;



                               painter.setPen(Qt::blue);
                                painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                               painter.drawText(2000,1500,"LISTES DES PARTENAIRE");
                               painter.setPen(Qt::black);
                               painter.drawRect(0,2700,9600,500);
                               painter.setFont(QFont("Calibri",14,QFont::Bold));
                               painter.drawText(200,3000,"cin");
                               painter.drawText(1800,3000,"nom");
                               painter.drawText(3100,3000,"local");
                               painter.drawText(4900,3000,"nom_soc");
                               painter.drawText(6800,3000,"num");
                               painter.drawText(8600,3000,"mail");



                               QSqlQuery query;

                               query.prepare("select * from PARTENAIRE");
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



