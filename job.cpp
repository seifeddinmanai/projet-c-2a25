#include "job.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>



Job::Job()
{
reference=0;salaire=0;experience=0;
nom="";poste="",niveau="";
}


Job::Job(QString nom,QString poste,int experience,int reference ,int salaire,QString niveau)
{
this->nom=nom;
    this->poste=poste;
    this->experience=experience;
    this->reference=reference;
    this->salaire=salaire;
    this->niveau=niveau;
}

int Job::getreference(){return  reference;}
int Job::getsalaire(){return salaire;}
int Job::getexperience(){return experience;}
QString Job::getnom(){return nom;}
QString Job::getposte(){return poste;}
QString Job::getniveau(){return niveau;}
void Job::setreference(int reference){this->reference=reference;}
void Job::setsalaire(int salaire){this->salaire=salaire;}
void Job::setexperience(int exerience){this->experience=exerience;}
void Job::setnom(QString nom){this->nom=nom;}
void Job::setprenom(QString poste){this->poste=poste;}
void Job::setniveau(QString niveau){this->niveau=niveau;}

bool Job::ajouter()
{
    QSqlQuery query;
    QString reference_string=QString::number(reference);
    QString salaire_string=QString::number(salaire);
    QString experience_string=QString::number(experience);
          query.prepare("INSERT INTO jobb (nom,poste, experience,reference,salaire,niveau) "
                        "VALUES (:nom, :poste, :experience, :reference, :salaire, :niveau)");
          query.bindValue(":nom", nom);
          query.bindValue(":poste", poste);
          query.bindValue(":experience", experience_string);
          query.bindValue(":reference", reference_string);
          query.bindValue(":salaire", salaire_string);
          query.bindValue(":niveau", niveau);
          return query.exec();
}

QSqlQueryModel* Job::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
         model->setQuery("SELECT* FROM jobb");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("POSTE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("experience"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("niveau"));
    return  model ;
}
bool Job::supprimer(int reference)
{
    QSqlQuery query;
    query.prepare("delete from jobb where reference=:reference");
    query.bindValue(0,reference);
    return query.exec();
}


bool Job::modifier(QString nom,QString poste,int reference,int salaire,int experience,QString niveau  )
{  QSqlQuery query;
    QString ref= QString::number(reference);
    QString sal= QString::number(salaire);
    QString exp= QString::number(experience);


    query.prepare("UPDATE jobb SET   nom=:nom,poste=:poste ,experience=:experience,reference=:reference,salaire=:salaire,niveau=:niveau     where reference=:reference");
    query.bindValue(":nom",nom );
    query.bindValue(":poste", poste);
     query.bindValue(":experience", exp);
    query.bindValue(":reference",ref);
      query.bindValue(":salaire", sal);

      query.bindValue(":niveau", niveau);
    return query.exec();
}
QSqlQueryModel *Job:: trier(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from jobb  order by reference desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("POSTE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("experience"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("niveau"));
return  model ;
}

QSqlQueryModel *Job::rechercher(QString nom){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from jobb WHERE(nom='"+nom+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("POSTE"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("experience"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("reference"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("niveau"));
return  model ;
}
