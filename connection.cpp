#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("seif01");//inserer nom de l'utilisateur
db.setPassword("wxcvbn123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
