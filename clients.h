#ifndef CLIENTS_H
#define CLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

//
class clients
{
public :
    clients();
    clients(QString,QString,QString,QString,QString,QString,QString);

    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setdestination(QString);
    void setdatedenaissance(QString);
    void setnumero(QString);
    void setnum0(QString);

    QString get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_destination();
    QString get_datedenaissance();
    QString get_numero();
    QString get_num0();


    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool modifier(int);
    QSqlQueryModel * triecin();
    QSqlQueryModel * trienumero();
    QSqlQueryModel * triedatedenaissance();
    void recherche(QTableView * table, QString);
    void telechargerPDF();
    bool facture(QString nom,QString periode,QString prix,QString total);
    QSqlQueryModel * afficherfacture();



private:
    QString cin,nom,prenom,destination,datedenaissance,numero,num0;
};
#endif // CLIENTS_H
