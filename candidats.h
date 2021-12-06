#ifndef CANDIDATS_H
#define CANDIDATS_H
#include <connection.h>
#include <QSqlQueryModel>

//
class candidats
{
public:
    candidats();
    candidats(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);


    bool ajouterCandidat();
    QSqlQueryModel * afficherCandidat();
    QSqlQueryModel * trierCandidat();

    bool supprimerCandidat(QString);
    bool modifierCandidat();
    QSqlQueryModel * rechercherCandidat(QString);

private:
    QString nom,prenom,adresse,date_nais,diplome,sexe,email,cin,tel,permis;

};

#endif // CANDIDATS_H
