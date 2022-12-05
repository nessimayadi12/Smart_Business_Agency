#ifndef MISSION_H
#define MISSION_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Mission
{
public:
    //Constructors
    Mission ();
    Mission(int,QString,QString,QString,QString,QString,QString,int);

    //getters
    int getid();
    long getnum_du_guide();
    QString getnom(),getprenom(), getlogement(),
    getmoyen_de_transport(),
    getnature_de_la_mission(),getnom_du_guide();

    //setters
    void setid(int);
    void setnum_du_guide(int);
    void setnom(QString),setprenom(QString), setlogement(QString),
    setmoyen_de_transport(QString),
    setnature_de_la_mission(QString),setnom_du_guide(QString);

    //Fonctionnalités de base relatives à l'entite mission
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri();
    QSqlQueryModel * tri2();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,QString,int);
QSqlQueryModel * Trouver(QString);
private:
    int id;
    long num_du_guide;
    QString nom,prenom, logement
    ,moyen_de_transport,
    nature_de_la_mission,nom_du_guide;
};

#endif // MISSION_H
