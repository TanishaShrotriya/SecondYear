// Line Clipping Algorithm using QPainter class

#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<iostream>
using namespace std;

static int LEFT=0x8,RIGHT=0x4,BOTTOM=0x2,TOP=0x1,xl=200,yl=200,xh=500,yh=400;
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

// Paintevent Function
void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    myfunct(&qp);		// Calling the function
    myfunct_1(&qp);		// Calling the function
    myfunct_2(&qp);		// Calling the function
}


//calculating outcodes of the line

int Widget::getcode(int x,int y)
{
int code = 0;
                    //Peform Bitwise OR to get outcode
if(y>yh) code |=TOP;
else if(y<yl) code |=BOTTOM;
else if(x<xl) code |=LEFT;
else if(x>xh) code |=RIGHT;
return code;
}




//FOR PARTIALLY VISIBLE
void Widget::myfunct(QPainter *qp)
{
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    int x1=200,y1=500,x2=400,y2=100;


                    //anti clockwise input coordinates
    int x[]={200,200,500,500};
    int y[]={200,400,400,200};
    int i=0;
    int n=4;

    x[i]=x[0];
    y[i]=y[0];

    for(i=0;i<n-1;i++)
    {
        qp->drawLine(x[i],y[i],x[i+1],y[i+1]);
    }
    qp->drawLine(x[0],y[0],x[n-1],y[n-1]);
                                            //window is drawwn


     qp->drawLine(x1,y1,x2,y2);
                                            //required line is drawn


    int outcode1=getcode(x1,y1);
    int outcode2=getcode(x2,y2);

    int accept = 0;
    int done=0;           //decides if line is to be drawn
    do
    {
        //completely inside line
       if((outcode1 | outcode2)==0)
       {                                    //Both points inside.Accept line
            accept = 1;
               done=1;
       }

       //completely outside line
       else if((outcode1 & outcode2)!=0)
       {
                                            //Logical AND of both codes != 0.Line is outside. Reject line
        done=1;
       }

       //partially inside line
        else
        {
       int x,y;
       int temp;
       if(outcode1==0) temp = outcode2;     //Decide if point1 is inside. if not calculate intersection
        else temp = outcode1;
       if((temp & TOP)!=0)
       {                                   //Line clips top edge
           x = x1+ (x2-x1)*(yh-y1)/(y2-y1);
          y = yh;
            }
       else if((temp & BOTTOM)!=0)
       {              					//Line clips bottom edge
           x = x1+ (x2-x1)*(yl-y1)/(y2-y1);
           y = yl;
         }
       else if((temp & LEFT)!=0)
       {                    				//Line clips left edge
        y = y1+ (y2-y1)*(xl-x1)/(x2-x1);
        x = xl;
        }
       else if((temp & RIGHT)!=0)
       {                					//Line clips right edge
       y = y1+ (y2-y1)*(xh-x1)/(x2-x1);
        x = xh;
        }
     if(temp == outcode1)
      {
                                            //Check which point we had selected earlier as temp, and replace its co-ordinates
      x1 = x;
       y1 = y;
        outcode1 = getcode(x1,y1);
       }
      else
      {
       x2 = x;
       y2 = y;
        outcode2 = getcode(x2,y2);
       }
    }
    }while(done==0);
                // After clipping draw the line
   qp->setPen(QPen(Qt::green));
    if(accept==1)
        qp->drawLine(x1,y1,x2,y2);
}



//FOR COMPLETELY VISIBLE


void Widget::myfunct_1(QPainter *qp)
{
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    int x1=300,y1=300,x2=400,y2=300;


                    //anti clockwise input coordinates
    int x[]={200,200,500,500};
    int y[]={200,400,400,200};
    int i=0;
    int n=4;

    x[i]=x[0];
    y[i]=y[0];

    for(i=0;i<n-1;i++)
    {
        qp->drawLine(x[i],y[i],x[i+1],y[i+1]);
    }
    qp->drawLine(x[0],y[0],x[n-1],y[n-1]);
                                            //window is drawwn


     qp->drawLine(x1,y1,x2,y2);
                                            //required line is drawn


    int outcode1=getcode(x1,y1);
    int outcode2=getcode(x2,y2);
    cout<<outcode1<<outcode2;
    int accept = 0;
    int done=0;           //decides if line is to be drawn
    do
    {
        //completely inside line
       if((outcode1 | outcode2)==0)
       {                                    //Both points inside.Accept line
            accept = 1;
               done=1;
       }

       //completely outside line
       else if((outcode1 & outcode2)!=0)
       {
                                            //Logical AND of both codes != 0.Line is outside. Reject line
        done=1;
       }

       //partially inside line
        else
        {
       int x,y;
       int temp;
       if(outcode1==0) temp = outcode2;     //Decide if point1 is inside. if not calculate intersection
        else temp = outcode1;
       if((temp & TOP)!=0)
       {                                   //Line clips top edge
           x = x1+ (x2-x1)*(yh-y1)/(y2-y1);
          y = yh;
            }
       else if((temp & BOTTOM)!=0)
       {              					//Line clips bottom edge
           x = x1+ (x2-x1)*(yl-y1)/(y2-y1);
           y = yl;
         }
       else if((temp & LEFT)!=0)
       {                    				//Line clips left edge
        y = y1+ (y2-y1)*(xl-x1)/(x2-x1);
        x = xl;
        }
       else if((temp & RIGHT)!=0)
       {                					//Line clips right edge
       y = y1+ (y2-y1)*(xh-x1)/(x2-x1);
        x = xh;
        }
     if(temp == outcode1)
      {
                                            //Check which point we had selected earlier as temp, and replace its co-ordinates
      x1 = x;
       y1 = y;
        outcode1 = getcode(x1,y1);
       }
      else
      {
       x2 = x;
       y2 = y;
        outcode2 = getcode(x2,y2);
       }
    }
    }while(done==0);
                // After clipping draw the line
   qp->setPen(QPen(Qt::green));
    if(accept==1)
        qp->drawLine(x1,y1,x2,y2);


}






//FOR COMPLETELY INVISIBLE


void Widget::myfunct_2(QPainter *qp)
{
    QPen pen(Qt::black,2,Qt::SolidLine);
    qp->setPen(pen);
    int x1=150,y1=200,x2=150,y2=400;


                    //anti clockwise input coordinates
    int x[]={200,200,500,500};
    int y[]={200,400,400,200};
    int i=0;
    int n=4;

    x[i]=x[0];
    y[i]=y[0];

    for(i=0;i<n-1;i++)
    {
        qp->drawLine(x[i],y[i],x[i+1],y[i+1]);
    }
    qp->drawLine(x[0],y[0],x[n-1],y[n-1]);
                                            //window is drawwn


     qp->drawLine(x1,y1,x2,y2);
                                            //required line is drawn


    int outcode1=getcode(x1,y1);
    int outcode2=getcode(x2,y2);
    cout<<outcode1<<outcode2;
    int accept = 0;
    int done=0;           //decides if line is to be drawn
    do
    {
        //completely inside line
       if((outcode1 | outcode2)==0)
       {                                    //Both points inside.Accept line
            accept = 1;
               done=1;
       }

       //completely outside line
       else if((outcode1 & outcode2)!=0)
       {
                                            //Logical AND of both codes != 0.Line is outside. Reject line
        done=1;
       }

       //partially inside line
        else
        {
       int x,y;
       int temp;
       if(outcode1==0) temp = outcode2;     //Decide if point1 is inside. if not calculate intersection
        else temp = outcode1;
       if((temp & TOP)!=0)
       {                                   //Line clips top edge
           x = x1+ (x2-x1)*(yh-y1)/(y2-y1);
          y = yh;
            }
       else if((temp & BOTTOM)!=0)
       {              					//Line clips bottom edge
           x = x1+ (x2-x1)*(yl-y1)/(y2-y1);
           y = yl;
         }
       else if((temp & LEFT)!=0)
       {                    				//Line clips left edge
        y = y1+ (y2-y1)*(xl-x1)/(x2-x1);
        x = xl;
        }
       else if((temp & RIGHT)!=0)
       {                					//Line clips right edge
       y = y1+ (y2-y1)*(xh-x1)/(x2-x1);
        x = xh;
        }
     if(temp == outcode1)
      {
                                            //Check which point we had selected earlier as temp, and replace its co-ordinates
      x1 = x;
       y1 = y;
        outcode1 = getcode(x1,y1);
       }
      else
      {
       x2 = x;
       y2 = y;
        outcode2 = getcode(x2,y2);
       }
    }
    }while(done==0);
                // After clipping draw the line
   qp->setPen(QPen(Qt::green));
    if(accept==1)
        qp->drawLine(x1,y1,x2,y2);
}
