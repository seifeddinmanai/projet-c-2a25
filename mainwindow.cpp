#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    mSystemTrayIcoon= new QSystemTrayIcon(this);
    mSystemTrayIcoon->setVisible(true);
    mSystemTrayIcoon->setIcon(QIcon(":/icon.png"));




    ui->setupUi(this);
    c.ouvrirconnexion();

    ui->stackedWidget_formation->setCurrentIndex(0);


    ui->lineEdit_prix->setValidator(new QDoubleValidator(0.0,250.0,1,this));//prix
    ui->lineEdit_Prix_formation_modifier->setValidator(new QDoubleValidator(0.0,250.0,1,this));//prix
    ui->lineEdit_duree->setValidator(new QIntValidator(0,999,this));
    ui->lineEdit_Duree_formation_modifier->setValidator(new QIntValidator(0,999,this));


}

MainWindow::~MainWindow()
{
    delete ui;
    c.fermerconnexion();
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

                          if(type!="" & prix!="" & duree!="" & formateur!="" & niveau!="")
                          {
                              if(!verifALPHA(formateur))
                              {
                                formations f(type,prix,duree,formateur,niveau);

                                 if(f.ajouterFormation())
                                    {
                                        mSystemTrayIcoon->showMessage(tr(" Ajouter "),tr("avec Succes ."));
                                        ui->lineEdit_duree->clear();
                                        ui->lineEdit_formateur->clear();
                                        ui->lineEdit_prix->clear();
                                        ui->lineEdit_type->clear();
                                      }
                               }
                                else
                                  mSystemTrayIcoon->showMessage(tr(" Alert "),tr("Le nom de formateur doit être Alphabétique ."));
                          }
                          else
                          {
                             mSystemTrayIcoon->showMessage(tr("Alert"),tr("Tout les champs sont obligatoire."));
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
    bool test;
    if(ui->lineEdit_id_formation->text()!="")
    {
        QString type=ui->lineEdit_type_formation_modifier->text()
                ,prix=ui->lineEdit_Prix_formation_modifier->text()
                ,duree=ui->lineEdit_Duree_formation_modifier->text()
                ,formateur=ui->lineEdit_formateur_modifier->text()
                ,niveau=ui->comboBox_formation_modifier->currentText();

        if(formateur=="")
            test=true;
        else
        {
            if(!verifALPHA(formateur))
                test=true;
            else
            {mSystemTrayIcoon->showMessage(tr(" Alert "),tr("Le nom de formateur doit être Alphabétique ."));
             test=false;}

        }


            if(test)
            {
            formations f(type,prix,duree,formateur,niveau);
              if(f.modifierFormation(ui->lineEdit_id_formation->text()))
              {
                  ui->lineEdit_type_formation_modifier->clear();ui->lineEdit_Prix_formation_modifier->clear();
                  ui->lineEdit_Duree_formation_modifier->clear();ui->lineEdit_formateur_modifier->clear();
                  ui->lineEdit_id_formation->clear();
                  mSystemTrayIcoon->showMessage(tr(" Modifier "),tr(" avec succes ."));
              }
              else
                  mSystemTrayIcoon->showMessage(tr(" Information "),tr(" auccun modification ."));
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

void MainWindow::on_pushButton__Historique_clicked()
{
    ui->tab_formation->setModel(tmphistorique.afficherHistorique());

}


void MainWindow::on_lineEdit_Rechercher_formation_textChanged(const QString &arg1)
{
    ui->tab_formation->setModel(tmpformation.rechercher_formation(arg1.toUpper()));

}















bool MainWindow::verifALPHA(QString chaine)
{
    chaine=chaine.toUpper();
    if(chaine=="")
        return true;
    else
    for(int i=0;i<chaine.length();i++)
        if((chaine[i]<'A' || chaine[i]>'Z') && chaine[i]!=" " )
            return true;

    return false;
}







void MainWindow::on_pushButton_statistique_clicked()
{
        int BAC= tmpformation.Get_somme_bac(),BTP= tmpformation.Get_somme_btp(),BTS= tmpformation.Get_somme_bts();
        int somme=BAC+BTP+BTS;

        QString CH_BAC ="BAC % "+ QString::number(BAC*100/somme),CH_BTP ="BTP % "+ QString::number(BTP*100/somme),CH_BTS ="BTS % "+ QString::number(BTS*100/somme);

        QPieSeries *series = new QPieSeries();
           series->setHoleSize(0.40);

           series->append(CH_BAC,BAC);
           series->append(CH_BTP,BTP);
           series->append(CH_BTS,BTS);

           QChartView *chartView = new QChartView();
           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->chart()->setTitle("Formations");
           chartView->chart()->addSeries(series);
           chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
           chartView->chart()->setTheme(QChart::ChartThemeDark);
           chartView->chart()->legend()->setFont(QFont("Arial", 7));
           chartView->show();
           chartView->resize(550,450);


}

