#ifndef JOB_H
#define JOB_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class Job
{
public:
    Job();
    Job(QString,QString,int,int,int,QString);
    int getreference();
    int getsalaire();
    int getexperience();
    QString getnom();
    QString getposte();
    QString getniveau();
    void setreference(int);
    void setsalaire(int);
    void setexperience(int);
    void setnom(QString);
    void setprenom(QString);
    void setniveau(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(QString,QString,int,int,int,QString);
      QSqlQueryModel * trier();
      QSqlQueryModel* rechercher(QString nom);




private:
    int reference,salaire,experience;
    QString nom , poste,niveau;


};

#endif // JOB_H
