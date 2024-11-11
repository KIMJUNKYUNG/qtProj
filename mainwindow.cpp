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
               <<"pushButton_plus"<<"pushButton_subtraction"<<"pushButton_multiply"<<"pushButton_divide"
               <<"pushButton_equal";

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

    connect(ui->pushButton_equal, &QPushButton::released, this, &MainWindow::slotPushedButton);

    qStrListNumbers.append(""); // First Number Space Add
}

void MainWindow::disableCalculateBtn(){

}

double MainWindow::calculate(double first, double second, QString cal){
    if (cal == "+"){
        return first + second;
    }else if(cal == "-"){
        return first - second;
    }else if(cal == "*"){
        return first * second;
    }else if(cal == "/"){
        return first / second;
    }
}

void MainWindow::slotPushedButton()
{
    QString senderName = QObject::sender()->objectName();
    int senderIndex = btnOptions.indexOf(senderName);

    if(senderIndex >= 0 && senderIndex <= 9){
        switch (senderIndex) {      // Numbers
        case 0:
            qStrListNumbers[qStrListNumbers.count() - 1].append("0");
            break;
        case 1:
            qStrListNumbers[qStrListNumbers.count() - 1].append("1");
            break;
        case 2:
            qStrListNumbers[qStrListNumbers.count() - 1].append("2");
            break;
        case 3:
            qStrListNumbers[qStrListNumbers.count() - 1].append("3");
            break;
        case 4:
            qStrListNumbers[qStrListNumbers.count() - 1].append("4");
            break;
        case 5:
            qStrListNumbers[qStrListNumbers.count() - 1].append("5");
            break;
        case 6:
            qStrListNumbers[qStrListNumbers.count() - 1].append("6");
            break;
        case 7:
            qStrListNumbers[qStrListNumbers.count() - 1].append("7");
            break;
        case 8:
            qStrListNumbers[qStrListNumbers.count() - 1].append("8");
            break;
        case 9:
            qStrListNumbers[qStrListNumbers.count() - 1].append("9");
            break;
        }
    }else{      // Operator
        if(senderIndex == 14){
            double result = 0;
            for(int i = 0; i < qStrListCalculator.length(); i++){
                result = qStrListNumbers[i].toDouble();
                double secondNum = qStrListNumbers[i+1].toDouble();

                QString curOperator = qStrListCalculator[i];

                result = calculate(result, secondNum,curOperator);
            }
            qStrListCalculator.append(("="));
            qStrListNumbers.append(QString::number(result));
        }else{
            qStrListNumbers.append("");

            if  (senderIndex == 10){
                qStrListCalculator.append(("+"));
            }else if(senderIndex == 11){
                qStrListCalculator.append(("-"));
            }else if(senderIndex == 12){
                qStrListCalculator.append(("*"));
            }else if(senderIndex == 13){
                qStrListCalculator.append(("/"));
            }
        }
    }

    ui->listWidgetNumbers->clear();
    ui->listWidgetCalculator->clear();

    ui->listWidgetNumbers->addItems(qStrListNumbers);

    ui->listWidgetCalculator->addItem("");
    ui->listWidgetCalculator->addItems(qStrListCalculator);

    for(int i = 0; i < qStrListCalculator.length() + 1; i++){
        ui->listWidgetCalculator->item(i)->setForeground(Qt::green);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
