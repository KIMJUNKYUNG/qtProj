#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btnOptions <<"pushButton_0"<<"pushButton_1" <<"pushButton_2" <<"pushButton_3" <<"pushButton_4"
               <<"pushButton_5" <<"pushButton_6" <<"pushButton_7" <<"pushButton_8" <<"pushButton_9"
               <<"pushButton_plus"<<"pushButton_subtraction"<<"pushButton_multiply"<<"pushButton_divide";

    calButtonList[0] = ui->pushButton_plus;
    calButtonList[1] = ui->pushButton_subtraction;
    calButtonList[2] = ui->pushButton_multiply;
    calButtonList[3] = ui->pushButton_divide;

    connect(ui->pushButton_0, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_1, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_3, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_4, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_5, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_6, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_7, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_8, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_9, &QPushButton::released, this, &MainWindow::slotPushedButton);

    connect(ui->pushButton_plus, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_subtraction, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_multiply, &QPushButton::released, this, &MainWindow::slotPushedButton);
    connect(ui->pushButton_divide, &QPushButton::released, this, &MainWindow::slotPushedButton);

}

void MainWindow::disableCalculateBtn(){

}

void MainWindow::slotPushedButton()
{
    QString senderName = QObject::sender()->objectName();
    // QString curText = ui->lbl_Number->text();
    switch (btnOptions.indexOf(senderName)) {
    case 0:
        qStrList.append("Hello");
        ui->listWidget->clear();
        ui->listWidget->addItems(qStrList);
    // case 1:
    //     ui->lbl_Number->setText(curText + "1");
    //     break;
    // case 2:
    //     ui->lbl_Number->setText(curText+ "2");
    //     break;
    // case 3:
    //     ui->lbl_Number->setText(curText + "3");
    //     break;
    // case 4:
    //     ui->lbl_Number->setText(curText + "4");
    //     break;
    // case 5:
    //     ui->lbl_Number->setText(curText + "5");
    //     break;
    // case 6:
    //     ui->lbl_Number->setText(curText + "6");
    //     break;
    // case 7:
    //     ui->lbl_Number->setText(curText + "7");
    //     break;
    // case 8:
    //     ui->lbl_Number->setText(curText + "8");
    //     break;
    // case 9:
    // //     ui->lbl_Number->setText(curText + "9");
    //    break;
    // case 10:
    // case 11:
    // case 12:
    // case 13:
    //     disableCalculateBtn();
    default:
        break;
    }

    switch (btnOptions.indexOf(senderName))
    {
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    default:
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
