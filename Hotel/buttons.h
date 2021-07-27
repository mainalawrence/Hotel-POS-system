#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>

namespace Ui {
class buttons;
}

class buttons : public QWidget
{
    Q_OBJECT

public:
    explicit buttons(QWidget *parent = nullptr);
    ~buttons();

private:
    Ui::buttons *ui;
};

#endif // BUTTONS_H
