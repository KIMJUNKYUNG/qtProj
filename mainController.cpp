#include "mainController.h"

#define width 281
#define height 430

MainController::MainController(MainWindow &view, MainModel &model)
{
    mainWindow = &view;
    mainModel = &model;

    mainWindow->setFixedSize(width,height);
    mainWindow->show();

    connect(mainWindow, &MainWindow::signalBtnPushedToCtrl, this, &MainController::slotPushedButton);
    connect(mainWindow, &MainWindow::signalClear, this, &MainController::slotClear);
    connect(mainWindow, &MainWindow::signalEscape, this, &MainController::slotEscape);
}

MainController::~MainController()
{
    delete this;
}


double MainController::calculate(double first, double second, QString cal)
{
    if (cal == "+"){
        return first + second;
    }else if(cal == "-"){
        return first - second;
    }else if(cal == "*"){
        return first * second;
    }else if(cal == "/"){
        return first / second;
    }

    return 0;
}


void MainController::slotPushedButton(QString pushedStr)
{
    int curTextIndex = mainModel->qStrListNumbers.count() - 1;
    int sigIndex = pushedStr.toInt();


    if(sigIndex >= 0 && sigIndex <= 9){
        switch (sigIndex) {      // Numbers
        case 0:
            mainModel->qStrListNumbers[curTextIndex].append("0");
            break;
        case 1:
            mainModel->qStrListNumbers[curTextIndex].append("1");
            break;
        case 2:
            mainModel->qStrListNumbers[curTextIndex].append("2");
            break;
        case 3:
            mainModel->qStrListNumbers[curTextIndex].append("3");
            break;
        case 4:
            mainModel->qStrListNumbers[curTextIndex].append("4");
            break;
        case 5:
            mainModel->qStrListNumbers[curTextIndex].append("5");
            break;
        case 6:
            mainModel->qStrListNumbers[curTextIndex].append("6");
            break;
        case 7:
            mainModel->qStrListNumbers[curTextIndex].append("7");
            break;
        case 8:
            mainModel->qStrListNumbers[curTextIndex].append("8");
            break;
        case 9:
            mainModel->qStrListNumbers[curTextIndex].append("9");
            break;
        }
    }else if(sigIndex == 15){   // '.'
        QString curStr = mainModel->qStrListNumbers[curTextIndex];
        if(curStr == ""){
            return;
        }
        mainModel->qStrListNumbers[curTextIndex].append(".");
    }else if(sigIndex == 16){   //  "+-"
        QString curStr = mainModel->qStrListNumbers[curTextIndex];
        if(curStr == ""){
            mainModel->qStrListNumbers[curTextIndex].append("-");
        }else{
            if(curStr[0] == "-"){
                mainModel->qStrListNumbers[curTextIndex].replace("-", "");
            }else{
                mainModel->qStrListNumbers[curTextIndex] = "-" + curStr;
            }
        }
    }else{      // Operator
        if(sigIndex == 14){      // =
            double result = mainModel->qStrListNumbers[0].toDouble();
            for(int i = 0; i < mainModel->qStrListCalculator.length(); i++){
                double secondNum = mainModel->qStrListNumbers[i+1].toDouble();

                QString curOperator = mainModel->qStrListCalculator[i];

                if(curOperator == "="){
                    result = secondNum;
                    continue;
                }

                result = calculate(result, secondNum, curOperator);
            }
            mainModel->qStrListCalculator.append(("="));
            mainModel->qStrListNumbers.append(QString::number(result));

            mainWindow->setEnabledCalBtn();
         }else{      // + - * /
            mainModel->qStrListNumbers.append("");

            if  (sigIndex == 10){
                mainModel->qStrListCalculator.append(("+"));
            }else if(sigIndex == 11){
                mainModel->qStrListCalculator.append(("-"));
            }else if(sigIndex == 12){
                mainModel->qStrListCalculator.append(("*"));
            }else if(sigIndex == 13){
                mainModel->qStrListCalculator.append(("/"));
            }

            mainWindow->setDisabledCalBtn();
        }
    }

    updateUiData();
}

void MainController::updateUiData(){
    QStringList mdlCalculator = mainModel->qStrListCalculator;
    QStringList mdlNumbers = mainModel->qStrListNumbers;

    mainWindow->updateUiData(mdlNumbers, mdlCalculator);

    int mdlCount = mdlCalculator.length();
    mainWindow->resetUiPolicy(mdlCount);
}


void MainController::slotClear()
{
    mainWindow->setEnabledCalBtn();

    mainModel->qStrListNumbers.clear();
    mainModel->qStrListCalculator.clear();
    mainModel->initMdl();

   updateUiData();
}


void MainController::slotEscape(){
    int len = mainModel->qStrListNumbers.length();
    int curStrLen = mainModel->qStrListNumbers[len - 1].length();
    if(len == 0){
        return;
    }else if(curStrLen == 0){
        return;
    }

    mainModel->qStrListNumbers[len -1].remove(curStrLen - 1, 1);

    updateUiData();
}
