#include "cashier.h"
#include "ui_cashier.h"

Cashier::Cashier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cashier)
{
    ui->setupUi(this);


}

Cashier::~Cashier()
{
    delete ui;
}

