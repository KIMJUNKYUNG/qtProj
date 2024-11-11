#include "mainwindow.h"

#include <QApplication>

#define width 281
#define height 430

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(width,height);
    w.show();

    return a.exec();
}
