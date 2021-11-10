#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"job.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include "update.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->reference->setValidator(new QIntValidator(1000, 9999, this));
Job j ;

ui->tab_job->setModel(j.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pt_ajouter_clicked()
{
    int reference=ui->reference->text().toInt();
    int salaire=ui->salaire->text().toInt();
    int experience=ui->experience->text().toInt();
    QString nom=ui->nom->text();
    QString poste=ui->poste->text();
    QString niveau=ui->niveau->text();

    Job j(nom,poste,experience,reference,salaire,niveau);
bool test=j.ajouter();
     if(test)
      {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                    QObject::tr("ajout successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_job->setModel(j.afficher());

                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                    QObject::tr("ajout failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_push_load_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT reference from jobb");
             query->exec();
             model->setQuery(*query);
             ui->combo_chercher->setModel(model);
}


void MainWindow::on_push_supprimer_clicked()
{
    Job j;
        j.setreference(ui->combo_chercher->currentText().toInt());
        bool test;
        test=j.supprimer(j.getreference());
        if(test)
         {    QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
                                       QObject::tr("sup successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);

    ui->tab_job->setModel(j.afficher());
                   }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("sup errer"),
                                       QObject::tr("sup failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_bouton_modifier_clicked()
{

  update update ;
    update.setModal(true);
    update.exec();
}



void MainWindow::on_pushButton_13_clicked()
{/*trie*/
Job j;
  ui->tab_job->setModel(j.trier());


}

void MainWindow::on_pushButton_14_clicked()
{
    /*chercher*/
    Job j;
    QString rech=ui->rech->text();
    if (rech=="")
     ui->tab_job->setModel(j.afficher());
    else
        ui->tab_job->setModel(j.rechercher(rech));

}
