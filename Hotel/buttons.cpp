#include "buttons.h"
#include "ui_buttons.h"

buttons::buttons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buttons)
{
    ui->setupUi(this);
}

buttons::~buttons()
{
    delete ui;
}
