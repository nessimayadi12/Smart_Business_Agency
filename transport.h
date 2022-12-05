#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <QApplication>
#include"connection.h"
#include<QMessageBox>
#include<QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

#include <QtWidgets>
#include<QObject>
#include <QtCharts>
#include <QColor>
#include <QtSql>
#include <cmath>
#include <QtWidgets>
#include <QTextCharFormat>
class transport
{
protected: // attributs //

     QString identifiant_T;
     int prix_T;
     QString moyen_transport_T;
     QString date_T;
     QString horaire_T;
     QString lieu_depart_T;
     QString lieu_arrivee;


public:  // methode //
        //contructeurs
        transport(){};
        transport(QString i,int p,QString m,QString d,QString h,QString ld,QString la)
{
        this->identifiant_T=i;
        this->prix_T=p;
        this->moyen_transport_T=m;
        this->date_T=d;
        this->horaire_T=h;
        this->lieu_depart_T=ld;
        this->lieu_arrivee=la;
};
    //getters
    QString getidentifiant_T(){return this->identifiant_T; };
    int getprix_T(){return this->prix_T;};
    QString getmoyen_transport_T(){return this->moyen_transport_T;};
    QString getdate_T(){return this->date_T;};
    QString gethoraire_T(){return this->horaire_T;};
    QString getlieu_depart_T(){return this->lieu_depart_T;};
    QString getlieu_arrivee(){return this->lieu_arrivee;};


    //fonctionnalités
    bool Ajouter();
    bool supprimer(QString id);
    bool modifier(QString,QString ,int,QString ,QString ,QString ,QString ,QString);

    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher_client_trie_prix();
    QSqlQueryModel* afficher_client_trie_date();

    QSqlQueryModel * researchid(QString i);
    QSqlQueryModel* tri_id_asc();
    QSqlQueryModel* tri_id_desc();
    void stat_transport();


};

#endif // TRANSPORT_H
