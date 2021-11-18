#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    // void setconnection(connection c);

       int get_cin();
       QString get_nom();
       QString get_prenom();
       int get_age();
       QString get_email();
       QString get_post();
       QString get_expe,rience();
       QString get_experience();


       void setcin(int n);
       void setnom(QString n);
       void setprenom(QString n);
       void setage(int n);
       void setemail(QString n);
       void setpost(QString n);
       void setexperience(QString n);
       void setid(QString n);

    employe();
    bool ajouterEmploye();

        QSqlQueryModel* afficherEmploye();

        bool supprimerEmploye(int);
        bool supprimertout();

        bool modifierEmploye(int ,QString ,QString ,int,QString ,QString ,QString );
        void  chercherEmploye(employe E);
        void trierEmploye( employe E);


        employe(int,QString,QString,int,QString,QString,QString);

        QSqlQueryModel* trierEmploye();
        QSqlQueryModel* rechercheEmploye(int);
        QSqlQueryModel* recherche3(QString a);


    private:
        int cin,age;
        QString nom, prenom, email, post ,experience;
};

#endif // EMPLOYE_H
