#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QStringList btnOptions;

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void updateUiData(QStringList, QStringList);
    void resetUiPolicy(int);

    void setDisabledCalBtn();
    void setEnabledCalBtn();

public slots:
    void slotUiBtnPushed();
signals:
    void signalBtnPushedToCtrl(QString);
    void signalClear();
    void signalEscape();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
