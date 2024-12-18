#include <QApplication>

#include "mainwindow.h"
#include "mainController.h"
#include "mainModel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    MainModel m;
    MainController c(w, m);

    return a.exec();
}
