#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class update;
}

class update : public QDialog
{
    Q_OBJECT

public:
    explicit update(QWidget *parent = nullptr);
    ~update();

private slots:
    void on_load_modifier_2_clicked();

    void on_comboBox_modifier_2_currentIndexChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::update *ui;
};

#endif // UPDATE_H
