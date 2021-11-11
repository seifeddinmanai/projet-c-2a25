#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "formations.h"
#include <QMessageBox>

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
    void on_button_ajouter_formation_clicked();

    void on_button_afficher_formation_clicked();

    void on_pushButton_ajouter_formation_clicked();

    void on_pushButton_Trier_clicked();

    void on_tab_formation_doubleClicked(const QModelIndex &index);

    void on_pushButton_modifier_formation_clicked();

    void on_pushButton_supprimer_formation_clicked();

private:
    Ui::MainWindow *ui;
    formations tmpformation;
    connection cnx;


};
#endif // MAINWINDOW_H
