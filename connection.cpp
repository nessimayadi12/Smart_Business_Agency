#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
 db = QSqlDatabase::addDatabase("QODBC");
 bool test=false;
db.setDatabaseName("projet");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("sandid");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connection::closeConnection(){db.close(); }
