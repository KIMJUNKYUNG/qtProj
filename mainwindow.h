#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QStringListModel>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void slotPushedButton();
    void slotClear();
    void slotEscape();

private:
    QStringList btnOptions;
    QPushButton *calButtonList[20];

    QStringList qStrListNumbers;
    QStringList qStrListCalculator;

    void initMdl();
    void resetUiPolicy();

    void setDisabledCalBtn();
    void setEnabledCalBtn();

    double calculate(double, double, QString);
public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
