#include "employe.h"
#include<QObject>

employe::employe()
{
    cin=0;
    nom="";
     prenom="";
     age=0;
     email="";
     post="";
     experience="";
}

void employe::setcin(int n){cin=n;}
void employe::setprenom(QString n){prenom=n;}
void employe::setnom(QString n){nom=n;}
void employe::setage(int n){age=n;}
void employe::setemail(QString n){email=n;}
void employe::setexperience(QString n){experience=n;}
void employe::setpost (QString n){post=n;}
int employe::get_cin(){return cin;}
QString employe::get_prenom(){return prenom;}
QString employe::get_nom(){return nom;}
int employe::get_age(){return age;}
QString employe::get_post(){return post;}
QString employe::get_email(){return email;}
QString employe::get_experience(){return experience;}


employe::employe(int cin,QString nom,QString prenom,int age,QString email,QString post,QString experience)
{
   this->cin=cin;//declaration
   this->nom=nom;
   this->prenom=prenom;
   this->age=age;
   this->email=email;
   this->post=post;
   this->experience=experience;

}


bool employe::ajouterEmploye()
{


//bool test=false;

   QSqlQuery query;

     query.prepare("INSERT INTO EMPLOYE (CIN, NOM, PRENOM ,AGE ,EMAIL,POST,EXPERIENCE) "
                   "VALUES (:cin, :nom, :prenom, :age, :email, :post, :experience)");
     query.bindValue(":cin", cin);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":age",age);
     query.bindValue(":email",email );
     query.bindValue(":post",post );
     query.bindValue(":experience",experience );


     return query.exec();



   // return test;
}


QSqlQueryModel* employe::afficherEmploye()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;


    model->setQuery("SELECT* FROM EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("POST"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EXPERIENCE"));
//set header : l'un a cote de l'autre in data



return model;

}



bool employe::supprimerEmploye(int cin)
{

    QSqlQuery query;

         query.prepare("delete from EMPLOYE where cin=:CIN");
         query.bindValue(":CIN", cin);
              return query.exec();

}


bool employe::modifierEmploye(int cin,QString nom,QString prenom,int age,QString post,QString experience,QString email)
{   QSqlQuery query;
    query.prepare( "UPDATE employe SET cin=:cin,nom=:nom,prenom=:prenom,age=:age,email=:email,post=:post ,experience=:experience WHERE cin=:cin");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":post", post);
    query.bindValue(":experience",experience);
    query.bindValue(":email",email);



 return query.exec();
}



QSqlQueryModel * employe::trierEmploye()
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM EMPLOYE order by AGE ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel* employe::rechercheEmploye(int cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from EMPLOYE where CIN like :CIN");
    query.bindValue(":CIN",cin);

    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("post"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("experience"));



return model;

}
/*
void employe::statistique(QVector<double>* ticks,QVector<QString> *labels)
{   QSqlQuery q;
    int i=0;
    q.exec("select matricule from employe");
    while (q.next()) {
        QString refer = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<refer;
}}*/
/*
QSqlQueryModel * Client::enregistrer()
{
    QSqlQueryModel * Modal=new  QSqlQueryModel();

    QSqlQuery qry;
     qry.prepare("SELECT * FROM Clients");
     qry.exec();
     Modal->setQuery(qry);
     return Modal;
}
*/

    bool employe::supprimertout()
    {
        QSqlQuery query;
        query.prepare("delete from EMPLOYE");
        return query.exec();

    }
