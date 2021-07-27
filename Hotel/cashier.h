#ifndef CASHIER_H
#define CASHIER_H

#include <QMainWindow>
#include<QStringList>
#include<QString>
#include<QDate>

namespace Ui {
class Cashier;
}

class Cashier : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cashier(QWidget *parent = nullptr);
    ~Cashier();


private:
    Ui::Cashier *ui;

};

#endif // CASHIER_H
