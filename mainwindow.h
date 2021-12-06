#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "candidats.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool control_saisie_chaine(QString ch){
        {
            ch=ch.toUpper();
            if(ch=="")
                return true;
            else
            for(int i=0;i<ch.length();i++)
                if((ch[i]<'A' || ch[i]>'Z') && ch[i]!=" " )
                    return true;

            return false;
        }
    }
    bool controle_saisie_email(QString);


private slots:
    void on_pushButton_Ajouter_clicked();


    void on_pushButton_Afficher_clicked();

    void on_pushButton_Trier_clicked();

    void on_tab_candidats_doubleClicked(const QModelIndex &index);

    void on_pushButton_non_supprimer_clicked();

    void on_pushButton_choisir_supprimer_clicked();

    void on_pushButton_annuler_modifier_clicked();

    void on_pushButton_choisir_modifier_clicked();

    void on_pushButton_oui_supprimer_clicked();

    void on_pushButton_modifier_terminer_clicked();

private:
    Ui::MainWindow *ui;
    connection c;
    candidats tmpcandidats;
};
#endif // MAINWINDOW_H
