#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class partenaire
{

    QString cin,num,nom, nom_soc,mail,local,modi;
public:
   partenaire();//CONSTRUCTEUR VIDE
   partenaire (QString, QString,QString,QString,QString,QString,QString);
//GETTERS
   QString getcin();
    QString getnom() ;
    QString getlocal() ;
    QString getnom_soc() ;
    QString getnum();
    QString getmail() ;
    QString getmodi() ;
///SETTERS
    void setcin(QString);
    void setnom(QString);
     void setlocal(QString);
      void setnom_soc(QString);
       void setnum(QString);
       void setmail(QString);
       void setmodi(QString);

bool ajouter();
bool supprimer(int);
QSqlQueryModel * afficher();
bool modifier(int);
QSqlQueryModel * triecin();
QSqlQueryModel * trienom();
QSqlQueryModel * trienum_tel();
void recherche(QTableView * table, QString);
void telechargerPDF();





};

#endif // PARTENAIRE_H
