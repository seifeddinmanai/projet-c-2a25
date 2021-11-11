#ifndef FORMATION_H
#define FORMATION_H

#include <QMainWindow>

namespace Ui {
class formation;
}

class formation : public QMainWindow
{
    Q_OBJECT

public:
    explicit formation(QWidget *parent = nullptr);
    ~formation();

private:
    Ui::formation *ui;
};

#endif // FORMATION_H
