#ifndef CIRCLE_H
#define CIRCLE_H

#include <QMainWindow>

namespace Ui {
class circle;
}

class circle : public QMainWindow
{
    Q_OBJECT

public:
    explicit circle(QWidget *parent = 0);
    ~circle();

private:
    Ui::circle *ui;

private slots:
    void draw();
};

#endif // CIRCLE_H
