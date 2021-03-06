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

    int x,y;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    Ui::Widget *ui;
protected:
void paintEvent(QPaintEvent *event);
void myfunct(QPainter *qp);

void translatepolygon(Widget verts[5],int,int,int,QPainter *qp);
void scalepolygon(Widget verts[5],int,float,float,QPainter *qp);
void shearpolygon(Widget verts[5],int,float,QPainter *qp);
void shearpolygon2(Widget verts[5],int,float,QPainter *qp);
void rotatepolygon(Widget verts[10],int n,QPainter *qp);

};
#endif // WIDGET_H

