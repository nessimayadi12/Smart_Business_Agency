#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "mission.h"
#include "map.h"
#include "stat_combo.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QValidator>
#include <QPixmap>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>


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
        ui->le_id->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_logement->clear();
        ui->le_transportL->clear();
        ui->la_mission->clear();
        ui->le_nom_guide->clear();
        ui->le_num_guide->clear();

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
        ui->le_id->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_logement->clear();
        ui->le_transportL->clear();
        ui->la_mission->clear();
        ui->le_nom_guide->clear();
        ui->le_num_guide->clear();


}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modification"),
                    QObject::tr("OUPS, La modification n'a pas été effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_PDF_clicked()
{
        QPdfWriter pdf("C:/Users/User/Desktop/Gestion_Mission/Liste des missions.pdf");

           QPainter painter(&pdf);

           int i = 4000;
           painter.setPen(Qt::blue);
           painter.setFont(QFont("Carmilla", 30));
           painter.drawPixmap(QRect(1300,3500,7500,7500),QPixmap("C:/Users/User/Desktop/Gestion_Mission/0.png"));
           painter.drawText(2000,1500,"LISTE DES MISSIONS");
           painter.setPen(Qt::red);
           painter.setFont(QFont("Apple Garamond", 50));
           painter.drawRect(1200,200,6300,2600);
           painter.drawRect(0,3000,9600,500);
           painter.setPen(Qt::black);
           painter.setFont(QFont("Apple Garamond", 5));
           painter.drawText(300,3300,"Identifiant");
           painter.drawText(1300,3300,"Nom");
           painter.drawText(2300,3300,"Prenom");
           painter.drawText(3300,3300,"Logement");
           painter.drawText(4300,3300,"Moyen de transport local");
           painter.drawText(5300,3300,"Nature de la mission");
           painter.drawText(6300,3300,"Nom du guide");
           painter.drawText(7300,3300,"Numero du guide");
           QSqlQuery query;
           query.prepare("select * from missions");
           query.exec();
           while (query.next())
           {
               painter.drawText(300,i,query.value(0).toString());
               painter.drawText(1300,i,query.value(1).toString());
               painter.drawText(2300,i,query.value(2).toString());
               painter.drawText(3300,i,query.value(3).toString());
               painter.drawText(4500,i,query.value(4).toString());
               painter.drawText(5500,i,query.value(5).toString());
               painter.drawText(6300,i,query.value(6).toString());
               painter.drawText(7300,i,query.value(7).toString());
               i = i +500;
           }

           int reponse = QMessageBox::question(this, "PDF généré avec succés", "Voulez vous afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
           if (reponse == QMessageBox::Yes)
           {
               QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/user/OneDrive/Bureau/gestion_employes/Liste.pdf"));

               painter.end();
           }
           if (reponse == QMessageBox::No)
           {
               painter.end();
           }
    }

void MainWindow::on_tab_mission_activated(const QModelIndex &index)
{
    QString val=ui->tab_mission->model()->data(index).toString();
    QSqlQuery query;
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString logement=ui->le_logement->text();
    QString moyen_de_transport=ui->le_transportL->text();
    QString nature_de_la_mission=ui->la_mission->text();
    QString nom_du_guide=ui->le_nom_guide->text();
    int num_du_guide=ui->le_num_guide->text().toInt();
    Mission M(id, nom, prenom, logement, moyen_de_transport, nature_de_la_mission, nom_du_guide, num_du_guide);

    M.modifier(id, nom, prenom, logement, moyen_de_transport, nature_de_la_mission, nom_du_guide, num_du_guide);

    if(query.exec())
    {
        while(query.next())
        {
            ui->le_id->setText(query.value(0).toString());
            ui->le_nom->setText(query.value(0).toString());
            ui->le_prenom->setText(query.value(0).toString());
            ui->le_logement->setText(query.value(0).toString());
            ui->le_transportL->setText(query.value(0).toString());
            ui->la_mission->setText(query.value(0).toString());
            ui->le_nom_guide->setText(query.value(0).toString());
            ui->le_num_guide->setText(query.value(0).toString());
            query.prepare ("select * from missions where ID_M=:val ");
        }
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),query.lastError().text());
    }
}

void MainWindow::on_Tri_clicked()
{
    ui->tab_mission->setModel(M.tri());
}


void MainWindow::on_Tri_2_clicked()
{
    ui->tab_mission->setModel(M.tri2());
}

void MainWindow::on_le_id_supp_textChanged(const QString &arg1)            //rechercher a partir le line edit supprimer//   //arg1 est un variable par defaut a partir le syntaxe//
{
    ui->le_id_supp->setValidator( new QIntValidator(0, 999999, this));
    if(ui->le_id_supp->text()!="")
    {
      QString recherche=ui->le_id_supp->text();
      ui->tab_mission->setModel(M.Trouver(recherche));
    }
    else
     ui->tab_mission->setModel(M.afficher());
}


void MainWindow::on_stat_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}


void MainWindow::on_map_clicked()
{
    m= new Map(this);
    m->show();

}


void MainWindow::on_arduino_pb_clicked()
{
    Connection c;

    data=A.read_from_arduino();

    ui->arduino_label->setText(data);

    QSqlQuery query(test_bd);
    QString select = "SELECT ID_M from MISSIONS where ID_M=?";
    qDebug() << select;
    query.prepare(select);
    query.addBindValue(ui->arduino_label->text());
    query.exec();
   if (query.exec())
    {

        int count=0;
        while (query.next())
        {
            count++;
        }
        if (count==1)
        {

            A.write_to_arduino("1");
            ui->arduino_label->setText("Welcome ");

        }

         else if (count<1)
        {
            A.write_to_arduino("0");

        }
    }
   if (data=="2"){
         ui->arduino_label->setText("No More Places");

   }
    //afficher on si les données reçues par arduino est 1

}
