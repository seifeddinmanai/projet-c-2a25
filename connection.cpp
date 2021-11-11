#include "connection.h"
connection::connection()
{}



bool connection::ouvrirconnexion()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-db");
    db.setUserName("nasreddine");//nom utilisateur
    db.setPassword("nasreddine");//mot de passe utilisateur
    if(db.open())
        test=true;
    else throw QString ("Erreur Paramétres"+test);



 return test ;
}

void connection::ecrire()
{

}

void connection::fermerconnexion()
{
    db.close();
}
