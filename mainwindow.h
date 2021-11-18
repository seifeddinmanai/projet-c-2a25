#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "job.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintQR(QPainter &painter, const QSize sz, const QString &data, QColor fg);


private slots:
    void on_pt_ajouter_clicked();

    void on_push_load_clicked();

    void on_push_supprimer_clicked();

    void on_bouton_modifier_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();



    void on_camera_pt_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pdf_pt_clicked();



    void on_qrcode_pt_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_tab_job_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Job j ;
};

#endif // MAINWINDOW_H
