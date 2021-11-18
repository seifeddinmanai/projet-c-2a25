#ifndef JOB_H
#define JOB_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSystemTrayIcon>


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
      QSqlQueryModel * trier1();
      QSqlQueryModel * trier2();
      QSqlQueryModel* rechercher(QString nom);
      QSqlQueryModel* rechercher1(QString a);
      void notification_ajoute();

      void notification_supprimer();

      void notification_modifier();
private:
    int reference,salaire,experience;
    QString nom , poste,niveau;

};

#endif // JOB_H
