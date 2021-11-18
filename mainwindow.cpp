#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"job.h"
#include<QIntValidator>
#include <QApplication>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "update.h"
#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPdfWriter>
#include "qrcode.h"
#include <QSystemTrayIcon>
#include<qrwidget.h>

#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>

#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include "qrcode.h"




#include<QRegularExpression>


#include <QPainter>

#include <QSqlQueryModel>

#include <QSystemTrayIcon>


#include <QTextStream>

#include<QDirModel>


using qrcodegen::QrCode;
using qrcodegen::QrSegment;

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
      {
         j.notification_ajoute();
         QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
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
         {  j.notification_supprimer();
            QMessageBox::information(nullptr, QObject::tr("supp avec succes"),
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

  update u ;
    u.setModal(true);
    u.exec();
}

void MainWindow::on_pushButton_13_clicked()
{/*trie reference*/
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



void MainWindow::on_camera_pt_clicked()
{
    Widget w ;
    w.setModal(true);
    w.exec();


}

void MainWindow::on_pushButton_clicked()
{    /*trie salaire*/
    Job j;
      ui->tab_job->setModel(j.trier1());
}

void MainWindow::on_pushButton_2_clicked()
{    /*trie experience*/
    Job j;
      ui->tab_job->setModel(j.trier2());
}


void MainWindow::on_pdf_pt_clicked()
{

        QPdfWriter pdf("C:\\Users\\Saif Manai\\Desktop\\Atelier_Connexion\\Atelier_Connexion\\pdf\\offre d'emploi.pdf");

       QPainter painter(&pdf);
       int i = 4000;
              painter.setPen(Qt::blue);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"Liste Des offre d'emploi");
              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 10));
              painter.drawText(500,3300,"NOM");
              painter.drawText(1500,3300,"POSTE");
              painter.drawText(2500,3300,"experience");
              painter.drawText(3500,3300,"reference");
              painter.drawText(4500,3300,"salaire");
              painter.drawText(5500,3300,"niveau");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from jobb");
              query.exec();
              while (query.next())
              {
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(1500,i,query.value(1).toString());
                  painter.drawText(2500,i,query.value(2).toString());
                  painter.drawText(3500,i,query.value(3).toString());
                  painter.drawText(4500,i,query.value(4).toString());
                  painter.drawText(5500,i,query.value(5).toString());

                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }






void MainWindow::on_qrcode_pt_clicked()
{
    if(ui->tab_job->currentIndex().row()==-1)
               QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                        QObject::tr("Veuillez Choisir du Tableau.\n"
                                                    "Click Ok to exit."), QMessageBox::Ok);
           else
           {

                int reference=ui->tab_job->model()->data(ui->tab_job->model()->index(ui->tab_job->currentIndex().row(),3)).toInt();
                const QrCode qr = QrCode::encodeText(std::to_string(reference).c_str(), QrCode::Ecc::LOW);
                std::ofstream myfile;
                myfile.open ("qrcode.svg") ;
                myfile << qr.toSvgString(1);
                myfile.close();
                QSvgRenderer svgRenderer(QString("qrcode.svg"));
                QPixmap pix( QSize(90, 90) );
                QPainter pixPainter( &pix );
                svgRenderer.render( &pixPainter );
                ui->QRCODE_3->setPixmap(pix);
           }
}



void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    ui->tab_job->setModel(j.rechercher1(arg1));
}

void MainWindow::on_tab_job_activated(const QModelIndex &index)
{

        ui->nom->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),0)).toString());
         ui->poste->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),1)).toString());
          ui->experience->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),2)).toString());
           ui->reference->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),3)).toString());
            ui->salaire->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),4)).toString());
              ui->niveau->setText(ui->tab_job->model()->data(ui->tab_job->model()->index(index.row(),5)).toString());

}
