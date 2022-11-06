#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
   protected: // attributs //
        QString id;
        QString id_emp;
        QString nom;
        QString prenom;
        QString status;
        QString mail;
        int age;
        QString nat;
        QString phone;
        int salaire;
    public: // methode //
        Employe(){};
        Employe(QString i, QString n, QString p, QString s, QString m, int a, QString nationalite, QString tel, int sal, QString b)
        {
            this->id = i;
            this->nom = n;
            this->prenom = p;
            this->status = s;
            this->mail = m;
            this->age = a;
            this->nat = nationalite;
            this->phone = tel;
            this->salaire = sal;
            this->id_emp= b ;
        };
        Employe(QString i,QString s,QString m,QString tel,int sal,QString b)
{
        this->id = i;
        this->status = s;
        this->mail = m;
        this->phone = tel;
        this->salaire = sal;
        this->id_emp= b ;
}
        QString getID(){return this->id;};
        QString getNom(){return this->nom;};
        QString getPrenom(){return this->prenom;};
        QString getStatus(){return this->status;};
        QString getMail(){return this->mail;};
        int getAge(){return this->age;};
        QString getNat(){return this->nat;};
        QString getPhone(){return this->phone;};
        int getSal(){return this->salaire;};
        QString getID_emp(){return this->id_emp;}
        // set functions //
        void setID(QString);
        bool Ajouter();
        bool Supprimer(QString);
        bool Modifier(QString,QString,QString,QString,int,QString);
        QSqlQueryModel * researchid(QString i);
        QSqlQueryModel * Afficher();
        QSqlQueryModel * Afficher_2();
};

#endif // EMPLOYE_H
