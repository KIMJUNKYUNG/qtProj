#include "mainwindow.h"
#include "./ui_mainwindow.h"

#define height 457

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btnOptions <<"pushButton_0"<<"pushButton_1" <<"pushButton_2" <<"pushButton_3" <<"pushButton_4"
               <<"pushButton_5" <<"pushButton_6" <<"pushButton_7" <<"pushButton_8" <<"pushButton_9"
               <<"pushButton_plus"<<"pushButton_subtraction"<<"pushButton_multiply"<<"pushButton_divide"
               <<"pushButton_equal"<<"pushButton_dot"<<"pushButton_plusMinus";

    connect(ui->pushButton_0, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_1, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);

    connect(ui->pushButton_plus, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_subtraction, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_multiply, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_divide, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);

    connect(ui->pushButton_equal, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_dot, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);
    connect(ui->pushButton_plusMinus, &QPushButton::released, this, &MainWindow::slotUiBtnPushed);

    connect(ui->pushButton_clear, &QPushButton::released, this, &MainWindow::signalClear);
    connect(ui->pushButton_escape, &QPushButton::released, this, &MainWindow::signalEscape);

    ui->listWidgetNumbers->setStyleSheet("QScrollBar {height:0px;}");
    ui->listWidgetCalculator->setStyleSheet("QScrollBar {height:0px;}");

    ui->pushButton_clear->setStyleSheet("QPushButton { color: red; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDisabledCalBtn(){

    ui->pushButton_divide->setDisabled(true);
    ui->pushButton_multiply->setDisabled(true);
    ui->pushButton_escape->setDisabled(true);
    ui->pushButton_divide->setDisabled(true);

    ui->pushButton_plusMinus->setDisabled(true);
    ui->pushButton_escape->setDisabled(true);
}

void MainWindow::setEnabledCalBtn(){
    ui->pushButton_divide->setEnabled(true);
    ui->pushButton_divide->setEnabled(true);
    ui->pushButton_multiply->setEnabled(true);
    ui->pushButton_escape->setEnabled(true);

    ui->pushButton_plusMinus->setEnabled(true);
    ui->pushButton_escape->setEnabled(true);
}

void MainWindow::slotUiBtnPushed(){

    QString senderName = QObject::sender()->objectName();
    int senderIndex = btnOptions.indexOf(senderName);

    switch (senderIndex) {
        case 0:
            emit signalBtnPushedToCtrl("0");
            break;
        case 1:
            emit signalBtnPushedToCtrl("1");
            break;
        case 2:
            emit signalBtnPushedToCtrl("2");
            break;
        case 3:
            emit signalBtnPushedToCtrl("3");
            break;
        case 4:
            emit signalBtnPushedToCtrl("4");
            break;
        case 5:
            emit signalBtnPushedToCtrl("5");
            break;
        case 6:
            emit signalBtnPushedToCtrl("6");
            break;
        case 7:
            emit signalBtnPushedToCtrl("7");
            break;
        case 8:
            emit signalBtnPushedToCtrl("8");
            break;
        case 9:
            emit signalBtnPushedToCtrl("9");
            break;
        case 10:
            emit signalBtnPushedToCtrl("10");   // +
            break;
        case 11:
            emit signalBtnPushedToCtrl("11");    // -
            break;
        case 12:
            emit signalBtnPushedToCtrl("12");    // *
            break;
        case 13:
            emit signalBtnPushedToCtrl("13");    // "/"
            break;
        case 14:
            emit signalBtnPushedToCtrl("14");    // =
            break;
        case 15:
            emit signalBtnPushedToCtrl("15");    // .
            break;
        case 16:
            emit signalBtnPushedToCtrl("16");       // +-
            break;
        }
}

void MainWindow::updateUiData(QStringList qStrListNumbers, QStringList qStrListCalculator)
{

    ui->listWidgetNumbers->clear();
    ui->listWidgetCalculator->clear();

    ui->listWidgetNumbers->addItems(qStrListNumbers);

    ui->listWidgetCalculator->addItem("");
    ui->listWidgetCalculator->addItems(qStrListCalculator);

    ui->listWidgetNumbers->scrollToBottom();
    ui->listWidgetCalculator->scrollToBottom();
}

void MainWindow::resetUiPolicy(int len)
{
    for(int i = 0; i < len + 1; i++){
        ui->listWidgetCalculator->item(i)->setForeground(Qt::green);
        ui->listWidgetCalculator->item(i)->setTextAlignment(Qt::AlignHCenter);

        ui->listWidgetNumbers->item(i)->setTextAlignment(Qt::AlignRight);
    }
}
