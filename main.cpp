#include "mainwindow.h"

#include <QApplication>
#include "gra.h"

Gra *gra;//wskaznik na nowa gre

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
