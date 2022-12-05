#include "mission.h"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QObject>
#include<QDebug>
#include<QVariant>



Mission::Mission()
{
id=0; num_du_guide=0;
nom=" ";prenom=" "; logement=" ";
    moyen_de_transport=" ";
    nature_de_la_mission=" ";nom_du_guide=" ";

}

Mission::Mission(int id,QString nom,QString prenom,
                 QString logement,
                 QString moyen_de_transport,
                 QString nature_de_la_mission,QString nom_du_guide,int num_du_guide)
{
this->id=id; this->num_du_guide=num_du_guide;
this->nom=nom; this->prenom=prenom; this->logement=logement;
this->nom_du_guide=nom_du_guide;
this->moyen_de_transport=moyen_de_transport;
this->nature_de_la_mission=nature_de_la_mission;
}
int  Mission::getid(){return id;}
long Mission::getnum_du_guide(){return num_du_guide;}
QString Mission::getnom(){return nom;}
QString Mission::getprenom(){return prenom;}
QString Mission::getlogement(){return logement;}
QString Mission::getmoyen_de_transport(){return moyen_de_transport;}
QString Mission::getnature_de_la_mission(){return nature_de_la_mission;}
QString Mission::getnom_du_guide(){return nom_du_guide;}

void Mission::setid(int id){this->id=id;}
void Mission::setnum_du_guide(int num_du_guide){this->num_du_guide=num_du_guide;}
void Mission::setnom(QString nom){this->nom=nom;}
void Mission::setprenom(QString prenom){this->prenom=prenom;}
void Mission::setlogement(QString logement){this->logement=logement;}
void Mission::setmoyen_de_transport(QString moyen_de_transport){this->moyen_de_transport=moyen_de_transport;}
void Mission::setnature_de_la_mission(QString nature_de_la_mission){this->nature_de_la_mission=nature_de_la_mission;}
void Mission::setnom_du_guide(QString nom_du_guide){this->nom_du_guide=nom_du_guide;}

bool Mission::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(num_du_guide);
    query.prepare("INSERT INTO missions (ID_M, NOM_M, PRENOM_M, LOGEMENT, MOYEN_DE_TRANSPORT, NATURE_DE_LA_MISSION, NOM_DU_GUIDE, NUMERO_DU_GUIDE)"
                  "values (:id, :nom, :prenom, :logement, :moyen_de_transport, :nature_de_la_mission, :nom_du_guide, :num_du_guide)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":logement",logement);
    query.bindValue(":moyen_de_transport",moyen_de_transport);
    query.bindValue(":nature_de_la_mission",nature_de_la_mission);
    query.bindValue(":nom_du_guide",nom_du_guide);
    query.bindValue(":num_du_guide",res1);
    return query.exec();
}
QSqlQueryModel * Mission::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM missions");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identfiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("logement"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("moyen de transport"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("nature de la mission"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("nom du guide"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("numero du guide"));


    return model;
}

QSqlQueryModel * Mission::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *  FROM MISSIONS ORDER BY NOM_M");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identfiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("logement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("moyen de transport"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nature de la mission"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nom du guide"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numero du guide"));

    return model;
}
QSqlQueryModel * Mission::tri2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *  FROM MISSIONS ORDER BY ID_M");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identfiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("logement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("moyen de transport"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nature de la mission"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nom du guide"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("numero du guide"));

    return model;
}
bool Mission::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from missions where ID_M= :id_M");
    query.bindValue(":id_M",res);
    return query.exec();
}
bool Mission::modifier(int ID_M, QString NOM_M,QString PRENOM_M,QString LOGEMENT,QString MOYEN_DE_TRANSPORT,QString NATURE_DE_LA_MISSION,QString NOM_DU_GUIDE,int NUMERO_DU_GUIDE)
{
    QSqlQuery query;
    query.prepare ("select * from missions where ID_M=:val ");
    query.prepare("update missions set ID_M=:ID_M, NOM_M=:NOM_M, PRENOM_M=:PRENOM_M, LOGEMENT=:LOGEMENT, MOYEN_DE_TRANSPORT=:MOYEN_DE_TRANSPORT, NATURE_DE_LA_MISSION=:NATURE_DE_LA_MISSION, NOM_DU_GUIDE=:NOM_DU_GUIDE, NUMERO_DU_GUIDE=:NUMERO_DU_GUIDE where ID_M=:ID_M ");
    query.bindValue(":ID_M",ID_M);
    query.bindValue(":NOM_M",NOM_M);
    query.bindValue(":PRENOM_M",PRENOM_M);
    query.bindValue(":LOGEMENT",LOGEMENT);
    query.bindValue(":MOYEN_DE_TRANSPORT",MOYEN_DE_TRANSPORT);
    query.bindValue(":NATURE_DE_LA_MISSION",NATURE_DE_LA_MISSION);
    query.bindValue(":NOM_DU_GUIDE",NOM_DU_GUIDE);
    query.bindValue(":NUMERO_DU_GUIDE",NUMERO_DU_GUIDE);
    return query.exec();
}

QSqlQueryModel* Mission::Trouver(QString recherche){
    QSqlQueryModel* trouve = new QSqlQueryModel();


       trouve->setQuery("SELECT * FROM missions WHERE ID_M LIKE '%"+recherche+"%' ");

       trouve->setHeaderData(0, Qt::Horizontal, QObject::tr("Identfiant"));
       trouve->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       trouve->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
       trouve->setHeaderData(3, Qt::Horizontal, QObject::tr("logement"));
       trouve->setHeaderData(4, Qt::Horizontal, QObject::tr("moyen de transport"));
       trouve->setHeaderData(5, Qt::Horizontal, QObject::tr("nature de la mission"));
       trouve->setHeaderData(6, Qt::Horizontal, QObject::tr("nom du guide"));
       trouve->setHeaderData(7, Qt::Horizontal, QObject::tr("numero du guide"));
       return trouve;
}
