#include "mainModel.h"


MainModel::MainModel()
{
    initMdl();
}

MainModel::~MainModel()
{
    delete this;
}

void MainModel::initMdl(){
    qStrListNumbers.append(""); // First Number Space Add
}

