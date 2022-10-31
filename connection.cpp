#include "connection.h"
Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("eraa");
db.setUserName("system");
db.setPassword("khalil");

if (db.open())
test=true;
    return  test;
}
