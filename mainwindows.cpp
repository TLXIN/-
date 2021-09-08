#include "mainwindows.h"
#include "ui_mainwindows.h"

Mainwindows::Mainwindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainwindows)
{
    ui->setupUi(this);
}

Mainwindows::~Mainwindows()
{
    delete ui;
}
