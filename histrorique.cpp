#include "histrorique.h"

histrorique::histrorique()
{
    date=QDateTime::currentDateTime();

}
histrorique::histrorique(QString etat)
{

    date=QDateTime::currentDateTime();
    this->etat=etat;

}
void histrorique::ajouter_historique()
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE VALUES(ID_HISTORIQUE.nextval,:etat,:DATE_HISTORIQUE ) ");
    query.bindValue(":etat",etat);
    query.bindValue(":DATE_HISTORIQUE",date.toString());

    query.exec();


}
void histrorique::setEtat(QString etat)
{
    this->etat=etat;
}

QSqlQueryModel * histrorique::afficherHistorique()
{
    QSqlQueryModel * model= new QSqlQueryModel();


        model->setQuery("select ETAT,DATE_HISTORIQUE FROM HISTORIQUE order by id_historique DESC ;");



    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date"));


    return model;
}
