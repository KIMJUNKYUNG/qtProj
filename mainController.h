#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "mainwindow.h"
#include "mainModel.h"

class MainController : public QObject
{
    Q_OBJECT

public slots:
    void slotPushedButton(QString);
    void slotClear();
    void slotEscape();
private:
    MainWindow *mainWindow;
    MainModel   *mainModel;

    double calculate(double, double, QString);
    void updateUiData();
public:
    MainController(MainWindow &view, MainModel &model);

    ~MainController();
};
#endif // MAINWINDOW_H
