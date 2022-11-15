#ifndef TRANSPORT_H
#define TRANSPORT_H
#include<QString>
#include"QDate"
#include"QDebug"
#include <QSqlQuery>
#include <QSqlQueryModel>

class Transport
{int identifiant_T,rech_id;
    float prix_T;
    QString type_T,etat_T,moyen_transport_T,lieu_depart_T,lieu_arrivee,horaire_T;
    QString date_T;
public:
    //contructeurs
    Transport();
    Transport(int,float,QString,QString,QString,QString,QString,QString,QString);
    //getters
    int getidentifiant_T();
    float getprix_T();
    QString getmoyen_transport_T();
    QString gettype_T();
    QString getdate_T();
    QString gethoraire_T();
    QString getlieu_depart_T();
    QString getlieu_arrivee();
    QString getetat_T();
    int getrech_id();

    //setters
    void setidentifiant_T(int );
    void setprix_T(float );
    void setmoyen_transport_T(QString );
    void settype_T(QString );
    void setdate_T(QString );
    void sethoraire_T(QString );
    void setlieu_depart_T(QString );
    void setlieu_arrivee(QString );
    void setetat_T(QString );





    //fonctionnalités
    void ajouter(Transport T);
    void supprimer(Transport T);
    void modifier(Transport T);
    QSqlQueryModel * chercher_transport(int rech_id);
    QSqlQueryModel* afficher();



    QSqlQueryModel* afficher_client_trie_prix();
    QSqlQueryModel* afficher_client_trie_date();

    //  void clearTable(QTableView * table);
   // void rechercher(QTableView *table, int x);



};
#endif // TRANSPORT_H
