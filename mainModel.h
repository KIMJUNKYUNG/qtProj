#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>

class MainModel : public QObject
{
    Q_OBJECT

public:
    QStringList qStrListNumbers;
    QStringList qStrListCalculator;

public:
    MainModel();
    ~MainModel();

    void initMdl();
private:
};
#endif // MAINMODEL_H_H
