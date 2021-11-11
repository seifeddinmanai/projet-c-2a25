#include "etudiant.h"


Etudiant::Etudiant(int id,QString nom,QString prenom,QString naissance,QString salaire,QString lieu,QString mail,QString code)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->naissance=naissance;
    this->salaire=salaire;
    this->lieu=lieu;
    this->mail=mail;
    this->code=code;


}

bool Etudiant::ajouter()
{ QSqlQuery query;
    QString res =QString::number(id);
    query.prepare("insert into facture (id,nom,prenom,naissance,salaire,lieu,mail)""values(:id,:nom,:prenom,:naissance,:salaire,:lieu,:mail)");

    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":naissance",naissance);
    query.bindValue(":salaire",salaire);
    query.bindValue(":code",code);
    query.bindValue(":lieu",lieu);
    query.bindValue(":mail",mail);




    return  query.exec();
}
QSqlQueryModel * Etudiant::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from facture");
  /*  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));*/

    return  model;

}


bool Etudiant::supprimer(int id)
{
  QSqlQuery query;
  QString res = QString::number(id);

  query.prepare("Delete from facture where ID= :id");
  query.bindValue(":id",res);

  return query.exec();
}
