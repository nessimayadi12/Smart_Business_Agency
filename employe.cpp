#include "employe.h"
#include "modify.h"
#include <QDebug>

bool Employe::Ajouter()
{ //YWRkIGVtcGxveWU=//
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES(IDENTIFIANT_E, NOM_E, PRENOM_E, STATUS_E, PHONE_E, MAIL_E,"
                  "AGE_E, SALAIRE_E, NATIONALITE_E, DATE_AJOUT_E, EMP_IDENTIFIANT_E) "
                  "VALUES (:id, :nom, :prenom, :status, :phone, :mail, :age, :salaire, :nat, :date, :id_emp)");
    query.bindValue(":id", this->getID());
    query.bindValue(":nom", this->getNom());
    query.bindValue(":prenom", this->getPrenom());
    query.bindValue(":status", this->getStatus());
    query.bindValue(":phone", this->getPhone());
    query.bindValue(":mail", this->getMail());
    query.bindValue(":age", this->getAge());
    query.bindValue(":salaire", this->getSal());
    query.bindValue(":nat", this->getNat());
    query.bindValue(":date", QDate::currentDate().toString());
    query.bindValue(":id_emp", this->getID_emp());
    return query.exec();
}

bool Employe::Modifier(QString id,QString status,QString phone,QString mail,int salaire,QString id_emp) //update //
{
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from EMPLOYES where IDENTIFIANT_E= :id");
    test.bindValue(":id",id);
    test.exec();
    if (test.next())
    {
  if (test.value(0).toInt() == 1)
  {
    QSqlQuery query ;
    query.prepare("UPDATE EMPLOYES SET STATUS_E= :status,PHONE_E= :phone,MAIL_E= :mail,SALAIRE_E= :salaire,EMP_IDENTIFIANT_E= :id_emp where IDENTIFIANT_E = :id");
    query.bindValue(":id",id);
    query.bindValue(":status",status);
    query.bindValue(":phone",phone);
    query.bindValue(":mail",mail);
    query.bindValue(":salaire",salaire);
    query.bindValue(":id_emp",id_emp);
    return query.exec();
  }
  else
  {return false ; }
    }
}

QSqlQueryModel * Employe::Afficher()
{ //afffichage1//
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT IDENTIFIANT_E, NOM_E, PRENOM_E, STATUS_E, PHONE_E, MAIL_E FROM EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_E"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_E"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS_E"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PHONE_E"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL_E"));

    return model;
}

QSqlQueryModel * Employe::Afficher_2()//afffichage2//
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT IDENTIFIANT_E, NOM_E, PRENOM_E, STATUS_E, PHONE_E, MAIL_E FROM EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_E"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_E"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS_E"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PHONE_E"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL_E"));

    return model;
}

bool Employe::Supprimer(QString id) //supprimer//
{
  QSqlQuery test ;
  test.prepare("SELECT COUNT(*) from EMPLOYES where IDENTIFIANT_E= :id");
  test.bindValue(":id",id);
  test.exec();
  if (test.next())
  {
if (test.value(0).toInt() == 1)
{
    QSqlQuery query ;
    query.prepare("Delete from EMPLOYES where IDENTIFIANT_E= :id");
    query.bindValue(":id",id);
    return query.exec();
}
   else
    return false;
  }
}
QSqlQueryModel * Employe::researchid(QString i)
{
    QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from EMPLOYES where upper(IDENTIFIANT_E) like upper ('%"+i+"%') ");
         model->setHeaderData(0, Qt::Vertical, QObject::tr("IDENTIFIANT_E"));
         model->setHeaderData(1, Qt::Vertical, QObject::tr("NOM_E"));
         model->setHeaderData(2, Qt::Vertical, QObject::tr("PRENOM_E"));
         model->setHeaderData(3, Qt::Vertical, QObject::tr("STATUS_E"));
         model->setHeaderData(4, Qt::Vertical, QObject::tr("PHONE_E"));
         model->setHeaderData(5, Qt::Vertical, QObject::tr("MAIL_E"));
             return model;
}

