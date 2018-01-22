#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<iostream>
#include<QtGui>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    myfunct(&qp);
}

void Widget::myfunct(QPainter *qp)
{

    int n=3;
    Widget verts[5];
    //int tx=60;int ty=30;
    //int k;
    int i;
    int x1[]={300,400,200};
    int y1[]={400,200,300};
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(x1[i],y1[i],x1[i+1],y1[i+1]);
    }
    qp->drawLine(x1[0],y1[0],x1[n-1],y1[n-1]);
    for(i=0;i<n;i++)
    {

            verts[i].x=x1[i];
            verts[i].y=y1[i];
}


    translatepolygon(verts,3,30,30,qp);
    scalepolygon(verts,3,0.5,0.5,qp);
    shearpolygon(verts,4,3,qp);
    shearpolygon2(verts,4,3,qp);
    rotatepolygon(verts,3,qp);

}
void Widget::translatepolygon(Widget verts[10],int n,int tx,int ty,QPainter *qp)
{
    int k;int i;
    for(k=0;k<n;k++)
    {
        verts[k].x=verts[k].x+ tx;
        verts[k].y=verts[k].y+ ty;

    }
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(verts[i].x,verts[i].y,verts[i+1].x,verts[i+1].y);
    }
    qp->drawLine(verts[0].x,verts[0].y,verts[n-1].x,verts[n-1].y);
}
void Widget::scalepolygon(Widget verts[10],int n,float sx,float sy,QPainter *qp)
{
    int k;int i;
    for(k=0;k<n;k++)
    {
        verts[k].x=verts[k].x* sx;
        verts[k].y=verts[k].y* sy;

    }
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(verts[i].x,verts[i].y,verts[i+1].x,verts[i+1].y);
    }
    qp->drawLine(verts[0].x,verts[0].y,verts[n-1].x,verts[n-1].y);
}

void Widget::shearpolygon(Widget verts[10],int n,float a,QPainter *qp)
{
    int k;int i;
    for(k=0;k<n;k++)
    {
        verts[k].x=verts[k].x + verts[k].y*a;
        verts[k].y=verts[k].y;

    }
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(verts[i].x,verts[i].y,verts[i+1].x,verts[i+1].y);
    }
    qp->drawLine(verts[0].x,verts[0].y,verts[n-1].x,verts[n-1].y);
}

void Widget::shearpolygon2(Widget verts[10],int n,float b,QPainter *qp)
{
    int k;int i;
    for(k=0;k<n;k++)
    {
        verts[k].y=verts[k].y + verts[k].x*b;
        verts[k].x=verts[k].x;

    }
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(verts[i].x,verts[i].y,verts[i+1].x,verts[i+1].y);
    }
    qp->drawLine(verts[0].x,verts[0].y,verts[n-1].x,verts[n-1].y);
}

void Widget::rotatepolygon(Widget verts[10],int n,QPainter *qp)
{
    int k;int i;
    for(k=0;k<n;k++)
    {
        verts[k].x=verts[k].x*0.5 - verts[k].y*0.866;
        verts[k].y=verts[k].x*0.5 + verts[k].y*0.866;

    }
    for(i=0;i<n-1;i++)
    {
        qp->drawLine(verts[i].x,verts[i].y,verts[i+1].x,verts[i+1].y);
    }
    qp->drawLine(verts[0].x,verts[0].y,verts[n-1].x,verts[n-1].y);
}




