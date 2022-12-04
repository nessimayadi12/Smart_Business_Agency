#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "connection.h"
#include "partenaire.h"
#include <QIntValidator>
#include <QTableView>
#include <QMessageBox>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ETMP.afficher());
    int ret=A.connect_arduino(); // lancer la connexion à arduino
                switch(ret){
                case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                    break;
                case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                   break;
                case(-1):qDebug() << "arduino is not available";
                }
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
                 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label2())); // permet de lancer
                 //le slot update_label suite à la reception du signal readyRead (reception des données).
                 //A.write_to_arduino("0");
                 A.read_from_arduino();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()

{

    QString nom=ui->nom->text();
    partenaire res;
    res.setcin(ui->cin->text());
    res.setnom(ui->nom->text());
    res.setlocal(ui->local->text());
    res.setnom_soc(ui->soc->text());
    res.setnum(ui->tel->text());
    res.setmail(ui->mail->text());


  bool test=res.ajouter();
  if (test)
  {//REFRESH TABLEVIEW
      ui->tableView->setModel(ETMP.afficher());
      QMessageBox::information(nullptr, QObject::tr("OK"),
              QObject::tr("Ajout effectué\n"
                          "click cancel to exit."), QMessageBox::Cancel);
      QString nomFile ="Historique";
                   QFile file("C:/Users/elbootic.com/Documents/partenaire/"+nomFile+".txt");
                   QString finalmsg="fichier modifie avec succes";
                    if(!file.exists()){
                    finalmsg="fichier cree avec succes";
                    }
                   file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                   QTextStream txt(&file);
                     QString d_info = QDateTime::currentDateTime().toString();

                   QString message2=d_info+" - Un partenaire a été ajoutée avec le nom "+ nom +"\n";
                   txt << message2;


}
  else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué\n""click cancel to exit"), QMessageBox::Cancel);


}

void MainWindow::on_pushButton2_clicked()

{
    int cin=ui->cin2->text().toInt();
    QString nom=ui->nom->text();
    bool test=ETMP.supprimer(cin);
    if (test)
    {//REFRESH TABLEVIEW
        ui->tableView->setModel(ETMP.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("suppression effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);
        QString nomFile ="Historique";
             QFile file("C:/Users/elbootic.com/Documents/partenaire/"+nomFile+".txt");
             QString finalmsg="fichier modifie avec succes";
              if(!file.exists()){
              finalmsg="fichier cree avec succes";
              }
             file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



             QTextStream txt(&file);
               QString d_info = QDateTime::currentDateTime().toString();

             QString message2=d_info+" - Un Partenaire a été suprimmé \n";
             txt << message2;

  }
    else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Suppression non effectué\n""click cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    partenaire res;
        int modi=ui->mail_2->text().toInt() ;
        QString nom=ui->nom->text();

        res.setcin(ui->cin->text());
        res.setnom(ui->nom->text());
        res.setlocal(ui->local->text());
        res.setnom_soc(ui->soc->text());
        res.setnum(ui->tel->text());
        res.setmail(ui->mail->text());
        bool test=res.modifier(modi);
        if(test)
        {
            ui->tableView->setModel(ETMP.afficher());

            QString nomFile ="Historique";
                     QFile file("C:/Users/elbootic.com/Documents/partenaire/"+nomFile+".txt");
                     QString finalmsg="fichier modifie avec succes";
                      if(!file.exists()){
                      finalmsg="fichier cree avec succes";
                      }
                     file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                     QTextStream txt(&file);
                       QString d_info = QDateTime::currentDateTime().toString();

                     QString message2=d_info+" - Un Emplacement a été modifie avec le nom "+ nom +"\n";
                     txt << message2;
        }
}


void MainWindow::on_radioButton_clicked()
{
   ui->tableView->setModel(ETMP.triecin());
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView->setModel(ETMP.trienom());
}


void MainWindow::on_radioButton_3_clicked()
{

ui->tableView->setModel(ETMP.trienum_tel());
}


void MainWindow::on_mail_3_textChanged(const QString &arg1)
{
    {
        QString rech = ui->mail_3->text();

        ETMP.recherche(ui->tableView,rech);

                         if (ui->mail_3->text().isEmpty())

                         {
                             ui->tableView->setModel(ETMP.afficher());

                             A.write_to_arduino("1");

                                 }


else {
          A.write_to_arduino("2");
    }


    }
}


void MainWindow::on_pushButton_4_clicked()
{
    ETMP.telechargerPDF();
    QMessageBox::information(nullptr,QObject::tr("OK"),

                           QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);
}





void MainWindow::on_ol1_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from PARTENAIRE where LOCAL_P = 'tunis'");
       float dispo1=model->rowCount();

       model->setQuery("select * from PARTENAIRE where LOCAL_P = 'italie'");
       float dispo=model->rowCount();

       model->setQuery("select * from PARTENAIRE where LOCAL_P = 'lamta'");
       float dispo2=model->rowCount();

       float total=dispo1+dispo+dispo2;
           QString a=QString("Tunis" +QString::number((dispo1*100)/total,'f',2)+"%" );
           QString b=QString("Italie"+QString::number((dispo*100)/total,'f',2)+"%" );
           QString c=QString("Lamta"+QString::number((dispo2*100)/total,'f',2)+"%" );
           QPieSeries *series = new QPieSeries();
           series->append(a,dispo1);
           series->append(b,dispo);
           series->append(c,dispo);
       if (dispo1!=0)
       {QPieSlice *slice = series->slices().at(0);
           slice->setLabelVisible();
           slice->setPen(QPen());}
       if ( dispo!=0)
       {
           QPieSlice *slice1 = series->slices().at(1);
           slice1->setLabelVisible();

       }
       if ( dispo2!=0)
       {
           QPieSlice *slice1 = series->slices().at(2);
           slice1->setLabelVisible();

       }

       QChart *chart = new QChart();


       chart->addSeries(series);
       chart->setTitle("Partenaires: "+ QString::number(total));



       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000,500);
       chartView->show();

}

void MainWindow::on_pushButton_5_clicked()
{
    QString nomFile="fichier excel ";
            QMessageBox msg;
            if(!nomFile.length()){

                msg.setText("entrer le nom du fichier");
                msg.exec();
            }
            else{
            QFile file("C:/Users/elbootic.com/Documents/partenaire/"+nomFile+".csv");
            QString finalmsg="fichier modifie avec succes";
             if(!file.exists()){
             finalmsg="fichier cree avec succes";
             }
            file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

            QTextStream txt(&file);
            txt<<"Cin \t\t                  Nom    \t\t                  local   \t\t                 nom_soc  \t\t                 num      \t\t                  mail    \n";

            for(int i=0;i<5;i++){

            QString cin= ui->tableView->model()->index(i,0).data().toString();
            QString num= ui->tableView->model()->index(i,1).data().toString();
            QString nom= ui->tableView->model()->index(i,2).data().toString();
            QString nom_soc= ui->tableView->model()->index(i,3).data().toString();
            QString mail= ui->tableView->model()->index(i,4).data().toString();
            QString local= ui->tableView->model()->index(i,5).data().toString();

            if(cin.length()){

            txt<< "'"+ cin +"' \t";
            txt<< "           '"+ nom +"' \t";
            txt<< "             '"+ local +"' \t";
            txt<< "             '"+ nom_soc +"' \t";
            txt<< "             '"+ num +"' \t";
            txt<< "             '"+ mail +"' \n";
            }
            }
            msg.setText(finalmsg);
            msg.exec();
            file.close();
            }
}

