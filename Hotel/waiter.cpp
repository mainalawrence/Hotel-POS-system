#include "waiter.h"
#include "ui_waiter.h"

Waiter::Waiter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Waiter)
{
    ui->setupUi(this);
}

Waiter::~Waiter()
{
    delete ui;
}
