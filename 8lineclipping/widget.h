#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<iostream>

namespace Ui {
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT
    //int x1,x2,y1,y2,flag;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
protected:

void paintEvent(QPaintEvent *event);
void myfunct(QPainter *qp);
int getcode(int,int);
void myfunct_1(QPainter *qp);
void myfunct_2(QPainter *qp);
};
#endif // WIDGET_H
