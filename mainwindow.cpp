#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <Qt3DLogic/QLogicAspect>
#include"etudiant.h"




#include<QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>




#include <QSqlRecord>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QtPrintSupport>
#include<QTime>
#include<QDate>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QPixmap pix("C:/Users/msi/Downloads/Documents/codmobilesplash.png");
    ui->label_5->setPixmap(pix.scaled(400,350));*/
    ui->tableView->setModel(Etmp.afficher());
    afficher_tab();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::afficher_tab()
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    qry->prepare("select * from FACTURE");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();

    QSqlQuery qry;
    qry.prepare("select * from ID where ID='"+val+"' or NOM='"+val+"' or PRENOM='"+val+"' or MAIL='"+val+"' " );

    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_13->setText(qry.value(0).toString());
            ui->lineEdit_13->setText(qry.value(0).toString());
            ui->lineEdit_5->setText(qry.value(1).toString());
            ui->lineEdit_6->setText(qry.value(2).toString());
            ui->lineEdit_18->setText(qry.value(3).toString());

        }
    }
    else {
       // QMessageBox::critical(this,tr("ERROR"),qry.lastError().text);
    }



}
void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    QString naissance=ui->lineEdit_8->text();
    QString salaire=ui->lineEdit_9->text();
    QString code=ui->lineEdit_12->text();
    QString lieu=ui->lineEdit_10->text();
    QString mail=ui->lineEdit_11->text();

    Etudiant E(id,nom,prenom,naissance,salaire,code,lieu,mail);

    bool test=E.ajouter();
    if(test)
    {   ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("ajout effectue\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                   QObject::tr("ajout non effectue\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit_13->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {   ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("suppression effectue\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                   QObject::tr("suppression non effectue\n"
                                               "click cancel to exit."),QMessageBox::Cancel);
}
void MainWindow::on_text_id_textChanged(const QString &arg1)
    {

       QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString text=ui->text_id->text();

        if(text.isEmpty())
        {
            afficher_tab();
        }
        else
        {
            qry->prepare("select * from FACTURE where ID='"+text+"'");
            qry->exec();
            modal->setQuery(*qry);
            ui->tableView_3->setModel(modal);
        }



    }


    void MainWindow::on_text_nom_textChanged(const QString &arg1)
    {
        QSqlQueryModel * modal= new QSqlQueryModel ();
        QSqlQuery*qry=new QSqlQuery();
        QString text_nom=ui->text_nom->text();
        QString text_id=ui->text_id->text();

        if(text_nom.isEmpty())
        {
            afficher_tab();
        }
        else
        {
            if(text_id.isEmpty())
            {
                qry->prepare("select * from FACTURE where NOM='"+text_nom+"'");
                qry->exec();
                modal->setQuery(*qry);
                ui->tableView_3->setModel(modal);
            }
            else
            {
                qry->prepare("select * from FACTURE where NOM='"+text_nom+"' and ID='"+text_id+"'");
                qry->exec();
                modal->setQuery(*qry);
                ui->tableView_3->setModel(modal);
            }

        }
    }

void MainWindow::on_pushButton_3_clicked()
{ int id=ui->lineEdit_13->text().toInt();
    bool test=Etmp.supprimer(id);
    /*if(test)
    {   ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("suppression effectue\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                   QObject::tr("suppression non effectue\n"
                                               "click cancel to exit."),QMessageBox::Cancel);*/
    int id1=ui->lineEdit_13->text().toInt();
    QString nom=ui->lineEdit_5->text();
    QString prenom=ui->lineEdit_6->text();
    QString naissance=ui->lineEdit_7->text();
    QString salaire=ui->lineEdit_14->text();
    QString code=ui->lineEdit_16->text();
    QString lieu=ui->lineEdit_17->text();
    QString mail=ui->lineEdit_18->text();

    Etudiant E(id1,nom,prenom,naissance,salaire,code,lieu,mail);

    bool test2=E.ajouter();
    if(test2)
    {   ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr(" effectue\n"
                                           "click cancel to exit."),QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                   QObject::tr("non effectue\n"
                                               "click cancel to exit."),QMessageBox::Cancel);

}



void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    QString val=ui->tableView_2->model()->data(index).toString();


  //  Etudiant conn;
   // if(!conn.connOpen())
   // {
      //  qDebug()<<"failed to open the database";
      //  return;
   // }
    //conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select *from facture where id='"+val+"' or nom='"+val+"' or prenom='"+val+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_13->setText(qry.value(0).toString());
             ui->lineEdit_5->setText(qry.value(1).toString());
              ui->lineEdit_6->setText(qry.value(2).toString());

        }
       // conn.connClose();
    }
    else
    {
       // QMessageBox::critical(this,tr("error::"),qry.lastError().text());

    }


}


