#include "widget.h"
#include "ui_widget.h"
#include "skinmanager.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->horizontalSliderR, SIGNAL(valueChanged(int)), this, SLOT(changeRGB(int)));
    QObject::connect(ui->horizontalSliderG, SIGNAL(valueChanged(int)), this, SLOT(changeRGB(int)));
    QObject::connect(ui->horizontalSliderB, SIGNAL(valueChanged(int)), this, SLOT(changeRGB(int)));
    QObject::connect(ui->horizontalSliderA, SIGNAL(valueChanged(int)), this, SLOT(changeRGB(int)));
    QObject::connect(ui->checkBox, SIGNAL(toggled(bool)), this, SLOT(setPicture(bool)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeRGB(int value)
{
    QSlider* slider = qobject_cast<QSlider*>(this->sender());
    if(slider == ui->horizontalSliderR)
    {
        GlobalSkinManager().setColorR(value);
    }
    else if(slider == ui->horizontalSliderG)
    {
        GlobalSkinManager().setColorG(value);
    }
    else if(slider == ui->horizontalSliderB)
    {
        GlobalSkinManager().setColorB(value);
    }
    else if(slider == ui->horizontalSliderA)
    {
        GlobalSkinManager().setColorA(value);
    }
}

void Widget::setPicture(bool enable)
{
    if(enable)
    {
        GlobalSkinManager().setPictureEnable(true);
        GlobalSkinManager().setPicture(":/image/flying_bird_sparkles.png");
    }
    else
    {
        GlobalSkinManager().setPictureEnable(false);
    }
}
