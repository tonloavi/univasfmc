#include "fmc_navmode.h"
#include "ui_fmc_navmode.h"

fmc_navmode::fmc_navmode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fmc_navmode)
{
    ui->setupUi(this);
}

fmc_navmode::~fmc_navmode()
{
    delete ui;
}
