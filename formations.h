#ifndef FORMATIONS_H
#define FORMATIONS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <connection.h>

class formations
{
public:
    formations();
    formations(QString type,QString prix,QString duree,QString formateur,QString niveau);
    QString Get_id();
    QString Get_type();
    QString Get_prix();
    QString Get_duree();
    QString Get_niveau();
    QString Get_formateur();

    bool ajouterFormation();
    QSqlQueryModel * afficherFormation(int);
    bool supprimerFormation(int);
    bool modifierFormation(QString);
private:
    QString type,prix,duree,formateur,niveau;
};

#endif // FORMATIONS_H
