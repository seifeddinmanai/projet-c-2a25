#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>

#include "connection.h"
#include "formations.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QSystemTrayIcon;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool verifALPHA(QString);

private slots:
    void on_button_ajouter_formation_clicked();

    void on_button_afficher_formation_clicked();

    void on_pushButton_ajouter_formation_clicked();

    void on_pushButton_Trier_clicked();

    void on_tab_formation_doubleClicked(const QModelIndex &index);

    void on_pushButton_modifier_formation_clicked();

    void on_pushButton_supprimer_formation_clicked();

    void on_pushButton__Historique_clicked();

    void on_lineEdit_Rechercher_formation_textChanged(const QString &arg1);

    void on_pushButton_statistique_clicked();

private:
    Ui::MainWindow *ui;
    formations tmpformation;
    connection c;
    histrorique tmphistorique;
    QSystemTrayIcon *mSystemTrayIcoon;

};
#endif // MAINWINDOW_H
