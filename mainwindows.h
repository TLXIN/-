#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>

namespace Ui {
class Mainwindows;
}

class Mainwindows : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindows(QWidget *parent = 0);
    ~Mainwindows();

private:
    Ui::Mainwindows *ui;
};

#endif // MAINWINDOWS_H
