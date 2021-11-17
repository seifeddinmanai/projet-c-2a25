#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_suprimer_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_chercher_clicked();



    //void on_label_login_linkActivated(const QString &link);


    //void on_pushButton_statistique_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_statistique_clicked();

private:
    Ui::MainWindow *ui;
    employe E;
};
#endif // MAINWINDOW_H
