#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("gul10");//inserer nom de l'utilisateur
db.setPassword("kais11");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
