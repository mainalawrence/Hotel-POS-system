#ifndef STOCK_H
#define STOCK_H

#include <QMainWindow>

namespace Ui {
class Stock;
}

class Stock : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();

private:
    Ui::Stock *ui;
};

#endif // STOCK_H
