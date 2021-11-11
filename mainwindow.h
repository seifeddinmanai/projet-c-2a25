#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "etudiant.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_text_id_textChanged(const QString &arg1);
    void on_text_nom_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void afficher_tab();
    void on_tableView_2_clicked(const QModelIndex &index);

    void on_tableView_2_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Etudiant Etmp;
};

#endif // MAINWINDOW_H
