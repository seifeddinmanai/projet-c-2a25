#include "mainwindow.h"
#include "candidats.h"
#include "connection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    w.show();
    return a.exec();
}
