#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QString>


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
