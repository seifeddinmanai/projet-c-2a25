#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cnx.ouvrirconnexion();
    ui->lineEdit_prix->setValidator(new QDoubleValidator(0.0,250.0,1,this));//prix
        ui->lineEdit_Prix_formation_modifier->setValidator(new QDoubleValidator(0.0,250.0,1,this));//prix
        ui->lineEdit_duree->setValidator(new QIntValidator(0,999,this));
        ui->lineEdit_Duree_formation_modifier->setValidator(new QIntValidator(0,999,this));

    ui->stackedWidget_formation->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    cnx.fermerconnexion();
}


void MainWindow::on_button_ajouter_formation_clicked()
{
    ui->stackedWidget_formation->setCurrentIndex(0);
}


// ********************************************* Ajouter Formation *****************************************************

void MainWindow::on_pushButton_ajouter_formation_clicked()
{



                QString type=ui->lineEdit_type->text().toUpper(),
                          prix = ui->lineEdit_prix->text(),
                          duree= ui->lineEdit_duree->text(),
                          formateur=ui->lineEdit_formateur->text().toUpper(),
                          niveau=ui->comboBox_niveau->currentText().toUpper();

                          formations f(type,prix,duree,formateur,niveau);

                            if(f.ajouterFormation())
                             {
                                QMessageBox::information(nullptr,QObject::tr("Ajouter Terminer"),QObject::tr("succes.\n"),QMessageBox::Ok);
                                ui->lineEdit_duree->clear();
                                ui->lineEdit_formateur->clear();
                                ui->lineEdit_prix->clear();
                                ui->lineEdit_type->clear();
                             }

}

// ********************************************* Afficher Formation *****************************************************

void MainWindow::on_button_afficher_formation_clicked()
{
    ui->stackedWidget_formation->setCurrentIndex(1);

    ui->tab_formation->setModel(tmpformation.afficherFormation(0));



}

// ********************************************* TRIER Formation *****************************************************

void MainWindow::on_pushButton_Trier_clicked()
{
        int tri=0;

        //****** 1 + 2
        if( ui->checkBox_Duree->isChecked() && ui->checkBox_Formateur->isChecked())
            tri=3;
        //****** 1 + 3
        if( ui->checkBox_Duree->isChecked() && ui->checkBox_Prix->isChecked())
            tri=5;
        //****** 2 + 3
        if(ui->checkBox_Formateur->isChecked() && ui->checkBox_Prix->isChecked())
            tri=6;
        //****** 1 + 2 + 3
        if( ui->checkBox_Duree->isChecked() && ui->checkBox_Formateur->isChecked() && ui->checkBox_Prix->isChecked())
            tri=7;
        if( ui->checkBox_Duree->isChecked())
            tri=1;
        if(ui->checkBox_Formateur->isChecked())
            tri=2;
        if(ui->checkBox_Prix->isChecked())
            tri=4;
        ui->tab_formation->setModel(tmpformation.afficherFormation(tri));
}

void MainWindow::on_tab_formation_doubleClicked(const QModelIndex &index)
{
    if (ui->tab_formation->model()->data(index).toString()[0]>'0' &&
        ui->tab_formation->model()->data(index).toString()[0]<'9')
    {
        ui->stackedWidget_formation->setCurrentIndex(2);
        ui->lineEdit_id_formation->setText(ui->tab_formation->model()->data(index).toString());

    }
}

// ********************************************* Modifier Formation *****************************************************


void MainWindow::on_pushButton_modifier_formation_clicked()
{
    if(ui->lineEdit_id_formation->text()!="")
    {
        QString type=ui->lineEdit_type_formation_modifier->text()
                ,prix=ui->lineEdit_Prix_formation_modifier->text()
                ,duree=ui->lineEdit_Duree_formation_modifier->text()
                ,formateur=ui->lineEdit_formateur_modifier->text()
                ,niveau=ui->comboBox_formation_modifier->currentText();
              formations f(type,prix,duree,formateur,niveau);

              if(f.modifierFormation(ui->lineEdit_id_formation->text()))
              {
                  ui->lineEdit_type_formation_modifier->clear();ui->lineEdit_Prix_formation_modifier->clear();
                  ui->lineEdit_Duree_formation_modifier->clear();ui->lineEdit_formateur_modifier->clear();
                  ui->lineEdit_id_formation->clear();
              }


    }
}


// ********************************************* Supprimer Formation *****************************************************


void MainWindow::on_pushButton_supprimer_formation_clicked()
{
    if(ui->lineEdit_id_formation->text()!="")
         {
            tmpformation.supprimerFormation(ui->lineEdit_id_formation->text().toInt());
            ui->lineEdit_id_formation->clear();
         }

}
