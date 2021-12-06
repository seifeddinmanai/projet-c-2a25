#include "candidats.h"

//
candidats::candidats()//constucteur
{
  cin="";
  nom="";
  prenom="";
  email="";
  adresse="";
  date_nais="";
  tel="";
  sexe="";
  diplome="";
  permis="";
}
candidats::candidats(QString cin,QString nom,QString prenom,QString date_nais,QString email,QString adresse,QString diplome,QString sexe,QString tel,QString permis)
{
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->adresse=adresse;
  this->date_nais=date_nais;
  this->tel=tel;
  this->sexe=sexe;
  this->diplome=diplome;
  this->permis=permis;
}


bool candidats::ajouterCandidat()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CANDIDATS VALUES(:CIN,:NOM,:PRENOM,TO_DATE(:DATE_NAISSANCE,'dd/mm/yyyy'),:EMAIL,:ADRESSE,:DIPLOME,:SEXE,:TEL,:PERMIS ) ");
    query.bindValue(":CIN",cin);
    query.bindValue(":NOM",nom);
    query.bindValue(":PRENOM",prenom);
    query.bindValue(":DATE_NAISSANCE",date_nais);
    query.bindValue(":EMAIL",email);
    query.bindValue(":ADRESSE",adresse);
    query.bindValue(":DIPLOME",diplome);
    query.bindValue(":SEXE",sexe);
    query.bindValue(":TEL",tel);
    query.bindValue(":PERMIS",permis);

    return query.exec();
}


bool candidats::supprimerCandidat(QString CIN)
{
    QSqlQuery query;
    query.prepare("Delete FROM CANDIDATS where CIN=:CIN");
    query.bindValue(":CIN",CIN);

    return query.exec();
}

QSqlQueryModel * candidats::afficherCandidat()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT TO_CHAR(CIN),nom,prenom,TO_CHAR(date_naissance, 'dd/mm/yyyy'),email,adresse,diplome,sexe,TO_CHAR(tel),TO_CHAR(permis) from CANDIDATS;");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date_Nais"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Diplome"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Telephone"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("Permis"));




    return model;

}

QSqlQueryModel * candidats::trierCandidat()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT TO_CHAR(CIN),nom,prenom,TO_CHAR(date_naissance, 'dd/mm/yyyy'),email,adresse,diplome,sexe,TO_CHAR(tel),TO_CHAR(permis) from CANDIDATS order by NOM ;");

    model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date_Nais"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Diplome"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Telephone"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("Permis"));




    return model;

}









bool candidats::modifierCandidat()
{   QSqlQuery query;
    bool verif=false;


            if(nom!="")
            {

                query.prepare("UPDATE CANDIDATS SET NOM=:NOM WHERE CIN='"+cin+"';");
                query.bindValue(":NOM",nom);
                query.exec();
                verif=true;
            }
            if(prenom!="")
            {

                query.prepare("UPDATE CANDIDATS SET prenom=:PRENOM WHERE CIN='"+cin+"';");
                query.bindValue(":PRENOM",prenom);
                query.exec();
                verif=true;
            }
            if(email!="")
            {

                query.prepare("UPDATE CANDIDATS SET EMAIL=:EMAIL WHERE CIN='"+cin+"';");
                query.bindValue(":EMAIL",email);
                query.exec();
                verif=true;
            }
            if(adresse!="")
            {

                query.prepare("UPDATE CANDIDATS SET ADRESSE=:ADRESSE WHERE CIN='"+cin+"';");
                query.bindValue(":ADRESSE",adresse);
                query.exec();
                verif=true;
            }
            if(sexe!="")
            {

                query.prepare("UPDATE CANDIDATS SET SEXE=:SEXE WHERE CIN='"+cin+"';");
                query.bindValue(":SEXE",sexe);
                query.exec();
                verif=true;
            }
            if(diplome!="")
            {

                query.prepare("UPDATE CANDIDATS SET DIPLOME=:DIPLOME WHERE CIN='"+cin+"';");
                query.bindValue(":DIPLOME",diplome);
                query.exec();
                verif=true;
            }
            if(tel!="")
            {

                query.prepare("UPDATE CANDIDATS SET TEL=:TEL WHERE CIN='"+cin+"';");
                query.bindValue(":TEL",tel);
                query.exec();
                verif=true;
            }
            if(permis!="")
            {

                query.prepare("UPDATE CANDIDATS SET PERMIS=:PERMIS WHERE CIN='"+cin+"';");
                query.bindValue(":PERMIS",permis);
                query.exec();
                verif=true;
            }
            if(date_nais.length()==10)
            {
                query.prepare("UPDATE CANDIDATS SET date_naissance =TO_DATE(:date_naissance,'dd/mm/yyyy') WHERE CIN='"+cin+"';");
                query.bindValue(":date_naissance",date_nais);
                query.exec();
                verif=true;

            }




 return verif;
}





