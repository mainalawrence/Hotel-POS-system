#ifndef WAITER_H
#define WAITER_H

#include <QMainWindow>

namespace Ui {
class Waiter;
}

class Waiter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Waiter(QWidget *parent = nullptr);
    ~Waiter();

private:
    Ui::Waiter *ui;
};

#endif // WAITER_H
