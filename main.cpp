#include "mainwindow.h"

#include <QApplication>

#define width 282
#define height 300

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   // w.setFixedSize(width,height);
    w.show();

    return a.exec();
}
