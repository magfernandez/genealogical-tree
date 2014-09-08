#include "Visualizator.hpp"
#include "ui_Visualizator.h"

Visualizator::Visualizator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualizator)
{
    ui->setupUi(this);
}

Visualizator::~Visualizator()
{
    delete ui;
}
