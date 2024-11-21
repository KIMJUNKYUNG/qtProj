#include "mainController.h"

#define width 281
#define height 430

MainController::MainController(MainWindow &view, MainModel &model)
{
    view.setFixedSize(width,height);
    view.show();
}

MainController::~MainController()
{
    delete this;
}
