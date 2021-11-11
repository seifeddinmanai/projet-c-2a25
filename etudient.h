#ifndef ETUDIANT_H
#define ETUDIANT_H

#include<QSqlQueryModel>
#include<QSqlQuery>





class Etudiant
{ QString nom,prenom,naissance,salaire,code,sexe,lieu,mail;
    int id;


public:
    Etudiant(){}
    Etudiant(int,QString,QString,QString,QString,QString,QString,QString);
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getID(){return id;}

    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setID(int id){this->id=id;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);



};

#endif // ETUDIANT_H
