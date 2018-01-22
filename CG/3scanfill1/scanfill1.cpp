#include "scanfill1.h"
#include "ui_scanfill1.h"
#include <QPainter>
#include <iostream>

scanfill1::scanfill1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scanfill1)
{
    ui->setupUi(this);
}

scanfill1::~scanfill1()
{
    delete ui;
}

void scanfill1 ::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter ap(this);
    myFunc(&ap);
}

void scanfill1::myFunc(QPainter *gp) {
    QPen pen (Qt::black,5,Qt::SolidLine);
    gp->setPen(pen);

    scanfill1 ed[10];
    float inter_x[10];
    int yy;
    float x_int[10];

    //anticlock i/p coordinates

    int y[]={300,400,200};
    int x[]={400,200,300};
    int i=0;
    int n=3;
    int temp;
    int ymin =480,ymax=0;

    int j;
    float m[50],dx,dy;
    x[i]=x[0];
    y[i]=y[0];
    for(i=0;i<n-1;i++) {
        gp->drawLine(x[i],y[i],x[i+1],y[i+1]);
    }

    gp->drawLine(x[0],y[0],x[n-1],y[n-1]);
    gp->setPen(QPen(Qt::white));

    for(i=0;i<n;i++) {
        if(y[i]>ymax)
            ymax=y[i];
        if(y[i]<ymin)
            ymin=y[i];
        ed[i].x1=x[i];
        ed[i].y1=y[i];

    }
    for(i=0;i<n-1;i++) {
        ed[i].x2=ed[i+1].x1;
        ed[i].y2=ed[i+1].y1;
        ed[i].flag=0;
    }
    ed[i].x2=ed[0].x1;
    ed[i].y2=ed[0].y1;
    ed[i].flag=0;
    for(i=0;i<n;i++) {  //sorting the vertices
        if(ed[i].y1<ed[i].y2) {
            temp=ed[i].x1;
            ed[i].x1=ed[i].x2;
            ed[i].x2=temp;

            temp=ed[i].y1;
            ed[i].y1=ed[i].y2;
            ed[i].y2=temp;
        }
    }
    for(i=0;i<n;i++) {

        dx=ed[i].x2-ed[i].x1;
        dy=ed[i].y2-ed[i].y1;
        if(dy==0) {
            m[i]=0;
        }
        else {
            m[i]=dx/dy;
        }
        inter_x[i]=ed[i].x1;

    }
    yy=ymax;
    while(yy>ymin) {
        for(i=0;i<n;i++) {
            if((yy > ed[i].y2) && (yy <= ed[i].y1)) {
                ed[i].flag=1;
            }
            else
                ed[i].flag=0;
        }
        j=0;
        for(i=0;i<n;i++) {
            if(ed[i].flag==1) {
                if(yy==ed[i].y1) {
                    x_int[j]=ed[i].x1;
                    j++;
                }
                else {
                    x_int[j]=inter_x[i]+(-m[i]);
                    inter_x[i]=x_int[j];
                    j++;
                }
            }
        }
        for(i=0;i<j;i++) {
            for(int k=0;k<j-1;k++) {
                if(x_int[k]>x_int[k+1]) {

                    temp=x_int[k];
                    x_int[k]=x_int[k+1];
                    x_int[k+1]=temp;
                }
            }
        }
        for(i=0;i<j;i+=2) {
            gp->drawLine(x_int[i],yy,x_int[i+1],yy);
        }
        yy--;
    }
}
