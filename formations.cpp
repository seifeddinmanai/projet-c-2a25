#include "formations.h"

formations::formations()
{
    type="";
    prix="";
    niveau="";
    duree="";
    formateur="";
}
formations::formations(QString type,QString prix,QString duree,QString formateur,QString niveau)
{
    this->type=type;
    this->prix=prix;
    this->duree=duree;
    this->niveau=niveau;
    this->formateur=formateur;
}

//************************************************    AJOUTER FORMATION  *******************************

bool formations::ajouterFormation()
{
    QString etat="Ajouer : Type :"+type+" Prix : "+prix+" Duree : "+duree+" Formateur : "+formateur+" Niveau : "+niveau;
    histrorique histo(etat);
    histo.ajouter_historique();

    QSqlQuery query;
    query.prepare("INSERT INTO formations VALUES(id_formation.nextval,:type_formation,:prix,:duree,:formateur,:niveau ) ");
    query.bindValue(":type_formation",type);
    query.bindValue(":prix",prix);
    query.bindValue(":duree",duree);
    query.bindValue(":formateur",formateur);
    query.bindValue(":niveau",niveau);
    return query.exec();
}

//*************************************************   SUPPRIMER FORMATION  ******************************
bool formations::supprimerFormation(int idd)
{
    QString id=QString::number(idd);

    QString etat="Supprimer : l'id de formation supprimer est :"+id;
    histrorique histo(etat);

    QSqlQuery query;
    query.prepare("Delete FROM FORMATIONS where ID_FORMATION=:id");
    query.bindValue(":id",id);

    histo.ajouter_historique();

    return query.exec();
}


//************************************************    MODIFIER EMPLOYEURS *****************************
bool formations::modifierFormation(QString ID_rechercher)
{
    histrorique histo;
    QString etat="Modifier : id formation : "+ID_rechercher;

    QSqlQuery query;
    bool Testquery=false;
    QSqlQuery qry;
    qry.prepare("SELECT ID_FORMATION FROM FORMATIONS where ID_FORMATION=?;");
    qry.addBindValue(ID_rechercher);


    bool exist=false;
    if(qry.exec())
        if(qry.next())
            {
            QVariant ch=qry.value(0);
            QString verif = QVariant(ch).toString();
            if(verif==ID_rechercher)
                exist=true;
             }
    if(exist)
       {
            if(type!="")
            {   type=type.toUpper();
                query.prepare("UPDATE FORMATIONS SET TYPE_FORMATION =? WHERE ID_FORMATION='"+ID_rechercher+"';");
                query.addBindValue(type);query.exec();Testquery=true;
                etat=etat+" Type de formation au : " +type;

            }
            if(formateur!="")
            {
                formateur=formateur.toUpper();
                query.prepare("UPDATE FORMATIONS SET FORMATEUR =? WHERE ID_FORMATION='"+ID_rechercher+"';");
                query.addBindValue(formateur);query.exec();Testquery=true;
                etat=etat+" Formateur au : " +formateur;

            }
            if(niveau!="")
            {
                query.prepare("UPDATE FORMATIONS SET NIVEAU =? WHERE ID_FORMATION='"+ID_rechercher+"';");
                query.addBindValue(niveau);query.exec();Testquery=true;
                etat=etat+" Niveau de formation au : " +niveau;



            }
            if(duree!=0)
             {
                query.prepare("UPDATE FORMATIONS SET DUREE =? WHERE ID_FORMATION='"+ID_rechercher+"';");
                query.addBindValue(duree);query.exec();Testquery=true;
                etat=etat+" Duree de formation au : " +duree;


            }

            if(prix!=0)
             {
                query.prepare("UPDATE FORMATIONS SET PRIX =? WHERE ID_FORMATION='"+ID_rechercher+"';");
                query.addBindValue(prix);query.exec();Testquery=true;
                etat=etat+" Prix de formation au : " +prix;


            }

        }
    histo.setEtat(etat);
    histo.ajouter_historique();

 return Testquery;
}










//************************************************    AFFICHAGE FORMATION ********************

QSqlQueryModel * formations::afficherFormation(int tri)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    switch (tri) {
    case 0:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ;");
        break;
    case 1:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY DUREE ;");
        break;
    case 2:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY FORMATEUR ;");
        break;
    case 4:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY PRIX ;");
        break;
    case 5:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY DUREE,PRIX ;");
        break;
    case 3:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY DUREE,FORMATEUR ;");
        break;
    case 6:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY PRIX,FORMATEUR ;");
        break;
    case 7:
        model->setQuery("select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU FROM FORMATIONS ORDER BY PRIX,FORMATEUR,DUREE ;");
        break;

    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("FORMATEUR"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NIVEAU"));

    return model;
}
//************************************************    RECHERCHER FORMATION *************************************


QSqlQueryModel * formations::rechercher_formation(QString rechercher)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QString select="select ID_FORMATION,TYPE_FORMATION,DUREE,PRIX,FORMATEUR,NIVEAU "
                   "FROM FORMATIONS where ID_FORMATION LIKE'"+rechercher+"%' OR TYPE_FORMATION LIKE'"+rechercher+"%' OR DUREE LIKE'"+rechercher+"%'"
                    "OR PRIX LIKE'"+rechercher+"%' OR FORMATEUR LIKE'"+rechercher+"%' OR NIVEAU LIKE'"+rechercher+"%';";
    model->setQuery(select);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DUREE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("FORMATEUR"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NIVEAU"));

    return model;
}


//************************************************    STAT FORMATION *************************************


int formations::Get_somme_bac()
{
    QSqlQuery query;

    query.prepare("select count(*) from formations where niveau='BAC';");
    query.exec();
    query.next();

    QVariant valeur=query.value(0);
    int val = QVariant(valeur).toInt();
    return val;




}

int formations::Get_somme_btp()
{

    QSqlQuery query;

    query.prepare("select count(*) from formations where niveau='BTP';");
    query.exec();
    query.next();

    QVariant valeur=query.value(0);
    int val = QVariant(valeur).toInt();
    return val;

}

int formations::Get_somme_bts()
{

    QSqlQuery query;

    query.prepare("select count(*) from formations where niveau='BTS';");
    query.exec();
    query.next();

    QVariant valeur=query.value(0);
    int val = QVariant(valeur).toInt();
    return val;

}
