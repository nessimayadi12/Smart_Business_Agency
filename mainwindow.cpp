#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "modify.h"
#include "pdf.h"
#include <qdebug.h>
#include"smtp.h"
#include <QSound>
#include "stat1.h"
#include "QMessageBox"
#include <QMediaPlayer>
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
    //for email tab
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(d.Afficher_2());
    setWindowTitle("EMPLOYEES MANAGMENT");
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

    if ( ui->lineNat_E->text() == "TUNISIA")
    {
    if (ui->spinAge_E->value()>=25 && ui->spinAge_E->value()<=60)
    {
    if (ui->lineSalaire_E->text().toInt()>=1500 && ui->lineSalaire_E->text().toInt()<=3500)
    {
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
        QSound s("C:/Users/khalil/OneDrive/Bureau/FINAL/click.wav");
        s.play();
        E.Ajouter();
        QMessageBox::information(nullptr, QObject::tr("ADD EMPLOYEE"),
                                     QObject::tr("THE EMPLOYEE HAS BEEN ADDED SUCCESSFULLY.\nClick Cancel to exit."), QMessageBox::Ok);

        }
        else
        {
        QMessageBox::critical(nullptr, QObject::tr("ADD EMPLOYEE"),
                                QObject::tr("THE EMPLOYEE HAS BEEN ADDED SUCCESSFULLY.\nClick Cancel to exit."), QMessageBox::Ok);
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
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INVALID SALARY .\nClick CANCEL to exit."), QMessageBox::Ok);
    }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INVALID AGE VALUE.\nClick CANCEL to exit."), QMessageBox::Ok);
    }
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("ONLY TUNISIAN WORKERS EXIST.\nCLICK CANCEL TO RETURN."), QMessageBox::Ok);
    }
}

void MainWindow::on_pushButton_2_clicked()// delete //
{
    QString d=ui->lineID_d->text();
    bool test=supp.Supprimer(d);
     if(test)
     {

          QMessageBox::information(nullptr, QObject::tr("DELETE EMPLOYEE"),
                                  QObject::tr("THE EMPLOYEE HAS BEEN DELETED SUCCESSFULLY.\n"
                                              "CLICK OK TO RETURN."), QMessageBox::Ok);
           }
               else
         {
         QMessageBox::information(nullptr, QObject::tr("DELETE EMPLOYEE"),
                               QObject::tr("THE EMPLOYEE DOES NOT EXIST.\n"
                                         "CLICK OK TO RETURN."), QMessageBox::Ok);
         }
ui->tableView->setModel(g.Afficher());
ui->tableView_delete->setModel(g.Afficher());
}

void MainWindow::on_checkBox_stateChanged(int arg1) //search //
{
    if (ui->checkBox->isChecked())
    {
    Employe s ;
    QString id = ui->line_research->text();
    ui->tableView->setModel(s.researchid(id));
    }
    else {
        ui->tableView->setModel(g.Afficher());
        ui->tableView_delete->setModel(g.Afficher());
}
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
                   if (ui->radioButton->isChecked())
                   {
                            ui->tableView->setModel(model);
                            ui->tableView->show();
                            qDebug()<<"TRI DONE" ;
                   }
                   else {

                       ui->tableView->setModel(g.Afficher());
                       ui->tableView_delete->setModel(g.Afficher());
                   }
}

void MainWindow::on_pushButton_3_clicked()
{
    pdf p;
    p.setModal(true);
    p.exec();
    qDebug()<<"pdf window open";
}

void MainWindow::on_pushButton_4_clicked()
{
    stat1 *w = new stat1();
               w->make_salary();
               w->make_nationalite();
               w->show();
               qDebug()<<"stat window open";
}

// mail //
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
    fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );
    ui->file->setText( fileListString );

}

void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("khalil.bouazizi@esprit.tn",ui->mail_pass->text(),"smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(" ", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
    QMessageBox::warning(nullptr, tr( "MAILLING" ), tr( "MESSAGE SENT\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

