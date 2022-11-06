#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "modify.h"
#include "QMessageBox"
#include <bits/stdc++.h>
using namespace std;

// valid id code : only uppercase and number (4 caracters exaclty) //
bool valid_id(QString id)
{
    for (int i = 0;i < id.length(); i++)
    {
       if((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= '0' && id[i] <= '9'))
       {

       }
           else
       {
       return false ;
       }
    }
    return true ;
}
// valid first name && last name //
bool valid_names(QString name)
{
    for (int i = 0;i < name.length(); i++)
    {
 if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))
 {

 }
 else return false;
    }
         return true ;
}

bool isChar(QChar c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(QChar c)
{
    return (c >= '0' && c <= '9');
}
bool nbis_valid(QString numb)
{
    for (int i = 0; i < numb.length(); i++) {
        if(!isDigit(numb[i])){
            return false;
        }
        else {
            return true;
        }
    }
}
bool is_valid(QString email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;i < email.length(); i++)
    {
        // If the character is '@'
        if (email[i] == '@')
        {
            At = i;
        }
        // If character is '.'
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(d.Afficher_2());

    qDebug()<<"start";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_modify_clicked() //second window opener function //
{
    modify m;
    m.setModal(true);
    m.exec();
    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(g.Afficher());
}

void MainWindow::on_pushButton_clicked()
{
    QString id = ui->lineID_E->text();
    QString nom = ui->lineNom_E->text();
    QString prenom = ui->linePrenom_E->text();
    QString status = ui->combo_status->currentText();
    QString phone = ui->linePhone_E->text();
    QString mail = ui->lineMail_E->text();
    int age = ui->spinAge_E->value();
    QString nat = ui->lineNat_E->text();
    int salaire = ui->lineSalaire_E->text().toInt();
    QString id_emp = ui->lineID_chef->text();

    Employe E(id, nom, prenom, status, mail, age, nat, phone, salaire, id_emp);
    bool test = true;


 if (ui->lineID_E->text().size() == 4 && valid_id(ui->lineID_E->text()) && ui->lineID_chef->text().size() == 4 && valid_id(ui->lineID_chef->text()))
    {
     if (valid_names(ui->lineNom_E->text()) && valid_names(ui->linePrenom_E->text()))
     {
    if (ui->linePhone_E->text().size() == 8 && nbis_valid(ui->linePhone_E->text()))
    {
    if (is_valid(ui->lineMail_E->text()))
    {
    if(test)
        {
        E.Ajouter();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("Ajout avec succés.\nClick Cancel to exit."), QMessageBox::Ok);

        }
        else
        {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                QObject::tr("Ajout échoué.\nClick Cancel to exit."), QMessageBox::Ok);
        qDebug() << "test";
        }
    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(g.Afficher());
}
    else {

        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INVALID MAIL.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    }
    else
{ QMessageBox::information(nullptr, QObject::tr("a"),
                           QObject::tr("INVALID PHONE NUMBER.\nClick Cancel to exit."), QMessageBox::Ok);

    }
}
else
{
    QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                    QObject::tr("INVALID FIRST NAME OR LAST NAME.\nClick Cancel to exit."), QMessageBox::Ok);
}
}
 else
 {
     QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                     QObject::tr("INVALID ID .\nClick CANCEL to exit."), QMessageBox::Ok);
 }
}

void MainWindow::on_pushButton_2_clicked()// delete //
{
    QString d=ui->lineID_d->text();
    bool test=supp.Supprimer(d);
     if(test)
     {

          QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("suppression effectué.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
           }
               else
         {
         QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                               QObject::tr("suppression echouée.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
ui->tableView->setModel(g.Afficher());
ui->tableView_delete->setModel(g.Afficher());
}

void MainWindow::on_checkBox_stateChanged(int arg1) //search //
{
    Employe s ;
    QString id = ui->line_research->text();
    ui->tableView->setModel(s.researchid(id));
}


void MainWindow::on_radioButton_clicked()
{
    QMessageBox msgBox ;
                QSqlQueryModel * model= new QSqlQueryModel();

                   model->setQuery("select * from EMPLOYES order by DATE_AJOUT_E");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT_E"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_E"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_E"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS_E"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("PHONE_E"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL_E"));
                            ui->tableView->setModel(model);
                            ui->tableView->show();
                            msgBox.setText("Tri avec succés.");
                            msgBox.exec();
}
