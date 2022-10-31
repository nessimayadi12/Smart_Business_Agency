#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mission.h"
#include<QMessageBox>
#include<QIntValidator>
#include "login.h"
#include<QValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_mission->setModel(M.afficher());
    //controle de saisie
    ui->le_id->setValidator (new QIntValidator (0,999999,this));
       ui->le_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->le_prenom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->le_logement->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->le_transportL->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->la_mission->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->le_nom_guide->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
       ui->le_num_guide->setValidator (new QIntValidator (0,999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString logement=ui->le_logement->text();
    QString moyen_de_transport=ui->le_transportL->text();
    QString nature_de_la_mission=ui->la_mission->text();
    QString nom_du_guide=ui->le_nom_guide->text();
    int num_du_guide=ui->le_num_guide->text().toInt();

    Mission M(id, nom, prenom, logement, moyen_de_transport, nature_de_la_mission, nom_du_guide, num_du_guide);
   bool test=M.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_mission->setModel(M.afficher());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                    QObject::tr("OUPS, Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_clicked()
{
Mission M1;
M1.setid(ui->le_id_supp->text().toInt());
bool test=M1.supprimer(M1.getid());
if(test)
{
    QMessageBox::information(nullptr, QObject::tr("Suppression"),
                QObject::tr("Suppression effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_mission->setModel(M.afficher());
}
else
    QMessageBox::critical(nullptr, QObject::tr("Suppression"),
                QObject::tr("OUPS, Suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString logement=ui->le_logement->text();
    QString moyen_de_transport=ui->le_transportL->text();
    QString nature_de_la_mission=ui->la_mission->text();
    QString nom_du_guide=ui->le_nom_guide->text();
    int num_du_guide=ui->le_num_guide->text().toInt();

    Mission M(id, nom, prenom, logement, moyen_de_transport, nature_de_la_mission, nom_du_guide, num_du_guide);
   bool test=M.modifier(id, nom, prenom, logement, moyen_de_transport, nature_de_la_mission, nom_du_guide, num_du_guide);
    if(test)
    {
         ui->tab_mission->setModel(M.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                    QObject::tr("La modification est effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification"),
                    QObject::tr("OUPS, La modification n'a pas été effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_11_clicked()
{
    login l;
    //l.setmission(M);
    l.exec();
}
