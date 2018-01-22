#ifndef LINES_H
#define LINES_H

#include <QMainWindow>

namespace Ui {

class lines;

}

class lines : public QMainWindow
{
    Q_OBJECT


public:
    explicit lines(QWidget *parent = 0);
    ~lines();

private:
    Ui::lines *ui;
private slots:
    void thin(float x2, float y2, float x1,float y1);
    void input();
    void thick();
    void dashed();
    void dash_dot();
    void newdotted();

};

#endif // LINE_H
