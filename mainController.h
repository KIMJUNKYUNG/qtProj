#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "mainModel.h"

class MainController : public QObject
{
    Q_OBJECT
public:
    MainController(MainWindow &view, MainModel &model);

    ~MainController();

private:
};
#endif // MAINWINDOW_H
