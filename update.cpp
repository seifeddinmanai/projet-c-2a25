#include "ui_update.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "job.h"
#include <QMessageBox>
#include"update.h"
update::update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update)
{
    ui->setupUi(this);
}

update::~update()
{
    delete ui;
}

void update::on_load_modifier_2_clicked()
{

    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT reference from jobb");
         query->exec();
         model->setQuery(*query);
         ui->comboBox_modifier_2->setModel(model);
}

void update::on_comboBox_modifier_2_currentIndexChanged(const QString &arg1)
{
    QString referenc=arg1;
 QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery   *query= new QSqlQuery();
      query->prepare("SELECT * from jobb where reference='"+referenc+"'");
      if(query->exec())
      {
          while (query->next())
          {

              ui->nom_modifier_2->setText(query->value(0).toString());
              ui->poste_modifier_3->setText(query->value(1).toString());
              ui->experience_modifier_3->setText(query->value(2).toString());
              ui->reference_modifier_3->setText(query->value(3).toString());
                 ui->salaire_modifier_3->setText(query->value(4).toString());
              ui->niveau_modifier_3->setText(query->value(5).toString());

          }
      }
      model->setQuery(*query);
}


void update::on_buttonBox_accepted()
{
    Job e1;
    e1.setnom(ui->nom_modifier_2->text());
    e1.setprenom(ui->poste_modifier_3->text());
         e1.setreference(ui->reference_modifier_3->text().toInt());
         e1.setsalaire(ui->salaire_modifier_3->text().toInt());
         e1.setexperience(ui->experience_modifier_3->text().toInt());
         e1.setniveau(ui->niveau_modifier_3->text());

        bool test=e1.modifier(e1.getnom(),e1.getposte(),e1.getreference(),e1.getsalaire(),e1.getexperience(),e1.getniveau());
       if(test)

       {
           e1.notification_modifier();
           QMessageBox::information(nullptr, QObject::tr("modifier avec succes"),
                                      QObject::tr("update successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                  }
                      else
                          QMessageBox::critical(nullptr, QObject::tr("modifier errer"),
                                      QObject::tr("update failed.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}



