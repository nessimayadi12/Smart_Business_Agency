#include "login.h"
#include "ui_login.h"
#include<QSqlQuery>
#include "mission.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::setmission(Mission M)
{

    ui->le_login->setText(M.getnom());
    ui->le_mp->setText(M.getprenom());
}
void login::on_pushButton_2_clicked()
{
    Mission M;
    QSqlQuery query;
    QString user=ui->le_login->text();
    QString mp=ui->le_mp->text();
    if( query.exec("select * from MISSIONS where NOM_M='"+user+"'and PRENOM_M='"+mp+ "'"))
        {
            int count=0;
            while (query.next())
            {count++;}
            if(count==1)
                ui->verif_label->setText("correct");


            if(count>1)
                ui->verif_label->setText("dublicate");

            if(count<1)
                ui->verif_label->setText("incorrect");
        }
}
