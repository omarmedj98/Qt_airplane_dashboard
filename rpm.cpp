#include "rpm.h"
#include "ui_rpm.h"

rpm::rpm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rpm)
{
    ui->setupUi(this);
}

rpm::~rpm()
{
    delete ui;
}
