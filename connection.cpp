#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
    db = QSqlDatabase:: addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("FINAL_FINAL");
db.setUserName("achref2002");//inserer nom de l'utilisateur
db.setPassword("BD2023");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
