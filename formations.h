#ifndef FORMATIONS_H
#define FORMATIONS_H

#include <connection.h>
#include "histrorique.h"

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
    QSqlQueryModel * rechercher_formation(QString);

    int Get_somme_bac();
    int Get_somme_btp();
    int Get_somme_bts();


private:
    QString type,prix,duree,formateur,niveau;



};

#endif // FORMATIONS_H
