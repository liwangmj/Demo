#include "example_1.h"
#include "ui_example_1.h"

Example_1::Example_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::example_1)
{
    ui->setupUi(this);
}

Example_1::~Example_1()
{
    delete ui;
}
