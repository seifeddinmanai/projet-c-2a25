#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtSql>

class connection
{
private:
    QSqlDatabase db;
    int userdb;
    QString passworddb;

public:
    connection();
    bool ouvrirconnexion();
    void fermerconnexion();
    void ecrire();

};

#endif // CONNECTION_H
