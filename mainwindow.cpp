#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
        int cin=ui->lineEdit_cin->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        int age=ui->lineEdit_age->text().toInt();
        QString post=ui->lineEdit_post->text();
        QString email=ui->lineEdit_email->text();
        QString experience=ui->lineEdit_experience->text();



            employe E(cin, nom,prenom,age,email,post,experience );
            bool test=E.ajouterEmploye();
            QMessageBox msgBox;

            if(test)
               {
                msgBox.setText("Ajout avec succes.");
                ui->tableView->setModel(E.afficherEmploye());
               }
            else
                msgBox.setText("Echec d'ajout.!!!");
                msgBox.exec() ;
}

void MainWindow::on_pushButton_afficher_clicked()
{
ui->tableView->setModel(E.afficherEmploye());
}

void MainWindow::on_pushButton_suprimer_clicked()
{
    employe E1;
         E1.setcin(ui->lineEdit_cin ->text().toInt());
         bool test=E1.supprimerEmploye(E1.get_cin());

         QMessageBox msgBox;

         if(test)
            { msgBox.setText("suppression  avec succes.");
             ui->tableView->setModel(E1.afficherEmploye());
            }
         else
             msgBox.setText("Echec de suppression.!!!");
             msgBox.exec();
}

void MainWindow::on_pushButton_modifier_clicked()
{

    int cin= ui ->lineEdit_cin->text().toInt();//conversion QString to int

       QString nom=ui->lineEdit_nom->text();
       QString prenom=ui->lineEdit_prenom->text();
       int age=ui->lineEdit_age->text().toInt();
       QString email=ui->lineEdit_email->text();
       QString post=ui->lineEdit_post->text();
       QString experience=ui->lineEdit_experience->text();


         ui->lineEdit_nom->setMaxLength(5); // max longueur de nom (line_edit)
          ui->lineEdit_prenom->setMaxLength(20);
          ui->lineEdit_email->setMaxLength(4);
                employe E  (cin,nom,prenom,age,post,email,experience);
               bool test=E.modifierEmploye(E.get_cin(),E.get_nom(),E.get_prenom(),E.get_age(),E.get_email(),E.get_post(),E.get_experience());//appel a la methode modifier
               if (test)
           {
           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Modification effectuée\n"
                               "Click Cancel non to exit.") , QMessageBox :: Cancel);

           ui->tableView->setModel((E.afficherEmploye()));


           }
           else
               QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Modification non effectuée.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
           ui->tableView->setModel((E.afficherEmploye()));
}

void MainWindow::on_pushButton_trier_clicked()
{
    if(E.trierEmploye())
    {
        ui->tableView->setModel(E.trierEmploye());
    }
}


void MainWindow::on_pushButton_chercher_clicked()
{

    E.setcin(ui->lineEdit_cin->text().toInt());
    ui->tableView->setModel(E.rechercheEmploye(E.get_cin()));
    ui->lineEdit_cin->clear();
    ui->lineEdit_nom->clear();
    ui->label_prenom->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_post->clear();
    ui->lineEdit_email->clear();
    ui->label_experience->clear();

}
/*

void MainWindow::on_pushButton_statistique_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
         QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("select * from GS_PRODUITS where PRIX < 50 ");
         float salaire=model->rowCount();
         model->setQuery("select * from GS_PRODUITS where PRIX  between 50 and 200 ");
         float salairee=model->rowCount();
         model->setQuery("select * from GS_PRODUITS where PRIX > 200 ");
         float salaireee=model->rowCount();
         float total=salaire+salairee+salaireee;

         QString a=QString("moins de 50 DT . "+QString::number((salaire*100)/total,'f',2)+"%" );
         QString b=QString("entre 50 et 200 DT.  "+QString::number((salairee*100)/total,'f',2)+"%" );
         QString c=QString("plus de 200 DT."+QString::number((salaireee*100)/total,'f',2)+"%" );

         QPieSeries *series = new QPieSeries();
         series->append(a,salaire);
         series->append(b,salairee);
         series->append(c,salaireee);
         if (salaire!=0)
         {QPieSlice *slice = series->slices().at(0);
             slice->setLabelVisible();
             slice->setPen(QPen());}
         if ( salairee!=0)
         {
             // Add label, explode and define brush for 2nd slice
             QPieSlice *slice1 = series->slices().at(1);
             //slice1->setExploded();
             slice1->setLabelVisible();
         }
         if(salaireee!=0)
         {
             // Add labels to rest of slices
             QPieSlice *slice2 = series->slices().at(2);
             //slice1->setExploded();
             slice2->setLabelVisible();
         }
         // Create the chart widget
         QChart *chart = new QChart();
         // Add data to chart with title and hide legend
         chart->addSeries(series); // widget
         chart->setTitle("Produits par Prix :Nombre Des Produits "+ QString::number(total));
         chart->legend()->hide();
         // Used to display the chart
         QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->resize(1000,500);
         chartView->show();
}
*/

void MainWindow::on_pushButton_Login_clicked()
{
        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();

               if (username == "admin" && password == "admin") {
                   QMessageBox::information(this, "Login", "Username and password are correct");
                ui->stackedWidget->setCurrentIndex(1);

               }
               else {
                   QMessageBox::warning(this, "Login", "Username and password are not correct");
               }
               ui->lineEdit_username->clear();
               ui->lineEdit_password->clear();
}

void MainWindow::on_pushButton_Reset_clicked()
{
    employe E1;
               bool test=E.supprimertout();
               if (test)
           {
           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("Reset Successful\n"
                               "Click Cancel non to exit.") , QMessageBox :: Cancel);

           ui->tableView->setModel((E.afficherEmploye()));// refresh


           }
           else
               QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                     QObject::tr("Reset failed.\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
           ui->tableView->setModel((E.afficherEmploye()));
}

void MainWindow::on_pushButton_statistique_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from EMPLOYE where AGE < 18 ");
        float salaire=model->rowCount();
        model->setQuery("select * from EMPLOYE where AGE  between 18 and 50 ");
        float salairee=model->rowCount();
        model->setQuery("select * from EMPLOYE where AGE >50  ");
        float salaireee=model->rowCount();
        float total=salaire+salairee+salaireee;

        QString a=QString("moins de 50 ANS . "+QString::number((salaire*100)/total,'f',2)+"%" );
        QString b=QString("entre 18 et 50 ANS.  "+QString::number((salairee*100)/total,'f',2)+"%" );
        QString c=QString("plus de 50 ANS."+QString::number((salaireee*100)/total,'f',2)+"%" );

        QPieSeries *series = new QPieSeries();
        series->append(a,salaire);
        series->append(b,salairee);
        series->append(c,salaireee);
        if (salaire!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( salairee!=0)
        {
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            //slice1->setExploded();
            slice1->setLabelVisible();
        }
        if(salaireee!=0)
        {
            // Add labels to rest of slices
            QPieSlice *slice2 = series->slices().at(2);
            //slice1->setExploded();
            slice2->setLabelVisible();
        }
        // Create the chart widget
        QChart *chart = new QChart();
        // Add data to chart with title and hide legend
        chart->addSeries(series); // widget
        chart->setTitle("STATISTIQUE DES EMPLOYEES SELON AGE  "+ QString::number(total));
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
 }

