#ifndef LINES_H
#define LINES_H

#include <QMainWindow>

namespace Ui {

class lines;

}

class lines : public QMainWindow
{
    Q_OBJECT
    float x1,x2,y1,y2;

public:
    explicit lines(QWidget *parent = 0);
    ~lines();

private:
    Ui::lines *ui;
private slots:
    void display(int x2, int y2, int x1, int y1);                     //DDA -thinline
    void display1(int x2, int y2, int x1, int y1);                     //DDA -thinline
    void input();
    void thick();
    void dotted();
    //void dashed();
    //void dash_dot();
    int sign(int val);

};

#endif // LINE_H
