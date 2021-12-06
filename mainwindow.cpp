#include "mainwindow.h"
#include "ui_mainwindow.h"
//
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c.ouvrirconnexion();
    ui->lineEdit_CIN->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_permis->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_tel->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_permis_modifier->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_tel_modifier->setValidator(new QIntValidator(0,99999999,this));

    ui->stackedWidget_candidat->setCurrentIndex(0);
    ui->tab_candidats->setModel(tmpcandidats.afficherCandidat());


}

MainWindow::~MainWindow()
{
    delete ui;
    c.fermerconnexion();
}


void MainWindow::on_pushButton_Ajouter_clicked()
{


    if(ui->lineEdit_CIN->text().length()!=8 || ui->lineEdit_CIN->text()=="")
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier CIN.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_nom->text()=="" || control_saisie_chaine(ui->lineEdit_nom->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Nom.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_prenom->text()=="" || control_saisie_chaine(ui->lineEdit_prenom->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Prenom.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_adresse->text()=="")
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Adresse.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_email->text()=="" || controle_saisie_email(ui->lineEdit_email->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Email.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_permis->text()=="")
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Permis.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_tel->text()=="" )
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Tel.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_diplome->text()=="" || control_saisie_chaine(ui->lineEdit_diplome->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Diplome.\n"),QMessageBox::Ok);
    else{
                QString
                CIN = ui->lineEdit_CIN->text(),
                nom=ui->lineEdit_nom->text(),
                prenom=ui->lineEdit_prenom->text(),
                date_nais= ui->dateEdit_dateNais->text(),
                TEL= ui->lineEdit_tel->text(),
                email=ui->lineEdit_email->text(),
                adresse= ui->lineEdit_adresse->text(),
                diplome=ui->lineEdit_diplome->text(),
                permis=ui->lineEdit_permis->text(),
                sexe=ui->comboBox_sexe->currentText();
                candidats c(CIN,nom,prenom,date_nais,email,adresse,diplome,sexe,TEL,permis);
                bool testajouter=c.ajouterCandidat();
                  if(testajouter)
                   {
                      QMessageBox::information(nullptr,QObject::tr("Ajouter"),QObject::tr("Terminer.\n"),QMessageBox::Ok);
                      ui->lineEdit_CIN->clear();ui->lineEdit_adresse->clear();ui->lineEdit_diplome->clear();ui->lineEdit_email->clear();
                      ui->lineEdit_prenom->clear();ui->lineEdit_permis->clear();ui->lineEdit_nom->clear();
                      ui->lineEdit_tel->clear();

                   }
                  else
                      QMessageBox::information(nullptr,QObject::tr("Ajouter"),QObject::tr("Deja exist.\n"),QMessageBox::Ok);

             }

    ui->tab_candidats->setModel(tmpcandidats.afficherCandidat());//refrech


}








bool MainWindow::controle_saisie_email(QString chaine)
{
        if(chaine=="")
            return true;
        if( chaine[0]=="@" || chaine[0]=="." || chaine[chaine.length()-1]=="@" || chaine[chaine.length()-1]=="." )
            return true;
        else
        {   int testALT=0,testpoint=0;
            for(int i=0;i<chaine.length();i++)
            {
                if( (chaine[i]<"a"|| chaine[i]>"z") && ( chaine[i]<"A" || chaine[i]>"Z") && (chaine[i]<"0"|| chaine[i]>"9")
                     && chaine[i]!="." && chaine[i]!="_" && chaine[i]!="@")
                    return true;
                if (chaine[i]=="@" && testALT==1)
                    return true;
                if(testpoint==1 && chaine[i]==".")
                    return true;
                if(chaine[i]=="@")
                    testALT=1;
                if(chaine[i]=="@" && (chaine[i+1]=="." || chaine[i-1]=="." ) )
                    return true;
                if(testALT==1 && chaine[i]=="." )
                    testpoint=1;
                if(chaine[i]=="." && chaine[i+1]==".")
                    return true;
            }
            if(testALT==0 || testpoint==0)
                return true;
        }
 return false;
}

void MainWindow::on_pushButton_Afficher_clicked()
{
    ui->tab_candidats->setModel(tmpcandidats.afficherCandidat());
}


void MainWindow::on_pushButton_Trier_clicked()
{
    ui->tab_candidats->setModel(tmpcandidats.trierCandidat());

}


void MainWindow::on_tab_candidats_doubleClicked(const QModelIndex &index)
{
       QString CIN=ui->tab_candidats->model()->data(index).toString();

        ui->lineEdit_supprimer->setText(CIN);
        ui->lineEdit_cin_modifier->setText(CIN);

        ui->stackedWidget_candidat->setCurrentIndex(3);



}


void MainWindow::on_pushButton_non_supprimer_clicked()
{
    ui->lineEdit_supprimer->clear();
    ui->stackedWidget_candidat->setCurrentIndex(0);
}


void MainWindow::on_pushButton_choisir_supprimer_clicked()
{
    ui->stackedWidget_candidat->setCurrentIndex(1);

}


void MainWindow::on_pushButton_annuler_modifier_clicked()
{
    ui->stackedWidget_candidat->setCurrentIndex(0);
    ui->lineEdit_cin_modifier->clear();

}


void MainWindow::on_pushButton_choisir_modifier_clicked()
{
    ui->stackedWidget_candidat->setCurrentIndex(2);
    ui->dateEdit_date_modifier->clear();


}


void MainWindow::on_pushButton_oui_supprimer_clicked()
{
    QString cin=ui->lineEdit_supprimer->text();
    bool test=tmpcandidats.supprimerCandidat(cin);
    if (test)
    {
        ui->tab_candidats->setModel(tmpcandidats.afficherCandidat());//refrech
        QMessageBox::information(nullptr,QObject::tr("Supprimer d'un candidat "),QObject::tr("est terminer.\n"),QMessageBox::Ok);
        ui->lineEdit_supprimer->clear();


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Supprimer d'un candidat "),QObject::tr("se candidat n'existe pas .\n"),QMessageBox::Ok);

    ui->stackedWidget_candidat->setCurrentIndex(0);

}






void MainWindow::on_pushButton_modifier_terminer_clicked()
{

    if(ui->lineEdit_nom_modifier->text()!="" && control_saisie_chaine(ui->lineEdit_nom_modifier->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Nom.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_prenom_modifier->text()!="" && control_saisie_chaine(ui->lineEdit_prenom_modifier->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Prenom.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_email_modifier->text()!="" && controle_saisie_email(ui->lineEdit_email_modifier->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Email.\n"),QMessageBox::Ok);
    else if(ui->lineEdit_diplome_modifier->text()!="" && control_saisie_chaine(ui->lineEdit_diplome_modifier->text()))
        QMessageBox::critical(nullptr,QObject::tr("Verification"),QObject::tr("verifier Diplome.\n"),QMessageBox::Ok);
    else{
                QString
                CIN = ui->lineEdit_cin_modifier->text(),
                nom=ui->lineEdit_nom_modifier->text(),
                prenom=ui->lineEdit_prenom_modifier->text(),
                date_nais= ui->dateEdit_date_modifier->text(),
                TEL= ui->lineEdit_tel_modifier->text(),
                email=ui->lineEdit_email_modifier->text(),
                adresse= ui->lineEdit_adresse_modifier->text(),
                diplome=ui->lineEdit_diplome_modifier->text(),
                permis=ui->lineEdit_permis_modifier->text(),
                sexe=ui->comboBox_sexe_modifier->currentText();
                candidats c(CIN,nom,prenom,date_nais,email,adresse,diplome,sexe,TEL,permis);
                bool testmodifier=c.modifierCandidat();
                  if(testmodifier)
                   {
                      QMessageBox::information(nullptr,QObject::tr("Modifier"),QObject::tr("Terminer.\n"),QMessageBox::Ok);
                      ui->lineEdit_cin_modifier->clear();ui->lineEdit_adresse_modifier->clear();ui->lineEdit_diplome_modifier->clear();ui->lineEdit_email_modifier->clear();
                      ui->lineEdit_prenom_modifier->clear();ui->lineEdit_permis_modifier->clear();ui->lineEdit_nom_modifier->clear();
                      ui->lineEdit_tel_modifier->clear();

                      ui->stackedWidget_candidat->setCurrentIndex(0);
                      ui->tab_candidats->setModel(tmpcandidats.afficherCandidat());//refrech

                   }
                  else
                      QMessageBox::information(nullptr,QObject::tr("Modifier"),QObject::tr("Error.\n"),QMessageBox::Ok);

             }




}

