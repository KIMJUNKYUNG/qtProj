#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btnOptions <<"pushButton_0"<<"pushButton_1" <<"pushButton_2" <<"pushButton_3" <<"pushButton_4"
               <<"pushButton_5" <<"pushButton_6" <<"pushButton_7" <<"pushButton_8" <<"pushButton_9";

    connect(ui->pushButton_1, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::slotPushedButton);

    ui->lineEdit->setText("");
}


void MainWindow::slotPushedButton()
{
    QString senderName = QObject::sender()->objectName();
    QString curText = ui->lineEdit->text();
    switch (btnOptions.indexOf(senderName)) {
    case 0:
        ui->lineEdit->setText(curText + "0");
        break;
    case 1:
        ui->lineEdit->setText(curText + "1");
        break;
    case 2:
        ui->lineEdit->setText(curText + "2");
        break;
    case 3:
        ui->lineEdit->setText(curText + "3");
        break;
    case 4:
        ui->lineEdit->setText(curText + "4");
        break;
    case 5:
        ui->lineEdit->setText(curText + "5");
        break;
    case 6:
        ui->lineEdit->setText(curText + "6");
        break;
    case 7:
        ui->lineEdit->setText(curText + "7");
        break;
    case 8:
        ui->lineEdit->setText(curText + "8");
        break;
    case 9:
        ui->lineEdit->setText(curText + "9");
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
