#include "linestyles.h"
#include "ui_linestyles.h"
#include<math.h>
#include<QtGui>
linestyles::linestyles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::linestyles)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(display1()));
 connect(this->ui->pushButton_6,SIGNAL(clicked()),this,SLOT(clear()));

 connect(this->ui->pushButton_3,SIGNAL(clicked()),this,SLOT(display2()));
 connect(this->ui->pushButton_2,SIGNAL(clicked()),this,SLOT(thick()));

 connect(this->ui->pushButton_4,SIGNAL(clicked()),this,SLOT(dashed()));
 connect(this->ui->pushButton_5,SIGNAL(clicked()),this,SLOT(dashdot()));
}

linestyles::~linestyles()
{
    delete ui;
}

void linestyles::display1()
{
    x1=ui->lineEdit->text().toInt();
    y1=ui->lineEdit_2->text().toInt();
    x2=ui->lineEdit_3->text().toInt();
    y2=ui->lineEdit_4->text().toInt();
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    display(dx,dy);

}
void linestyles::display(int dx,int dy)                          //for thin line
{
    QImage *q;
    q=new QImage (300,280,QImage::Format_ARGB32);
    QRgb value= qRgb(255,255,255);
    int steps,x,y;
    if(dx>=dy)
        steps=dx;
    else
        steps=dy;
    x_1=(float)dx/steps;
    y_1=(float)dy/steps;
    x=x1;
    y=y1;
    for(int i=0;i<steps;i++)
    {
        q->setPixel(x,y,value);
        ui->label_5->setPixmap(QBitmap::fromImage(*q));
        x=x+x_1;
        y=y+y_1;
    }
}



void linestyles::display2()
{
    x1=ui->lineEdit->text().toInt();
    y1=ui->lineEdit_2->text().toInt();
    x2=ui->lineEdit_3->text().toInt();
    y2=ui->lineEdit_4->text().toInt();
    dx=abs(x2-x1);
    dy=abs(y2-y1);
dotted(dx,dy);
}
void linestyles::dotted(int dx,int dy)                                      //for dotted line
{
    x1=this->ui->lineEdit->text().toInt();
    y1=this->ui->lineEdit_2->text().toInt();
    x2=this->ui->lineEdit_3->text().toInt();
    y2=this->ui->lineEdit_4->text().toInt();

    QImage img(291,231,QImage::Format_ARGB32);
    QRgb rgb=qRgb(255,255,255);
    img.fill(QColor(Qt::black).rgb());
    int n;
    float x_1,y_1;
    float x,y;
    if(dx>dy)
        n=dx;
    else
        n=dy;

    x_1=(float)dx/n;
    y_1=(float)dy/n;
    img.setPixel(x1,y1,rgb);
x=x1;
y=y1;
ui->label_5->setPixmap(QPixmap::fromImage(img));
for(int i=0;i<n;i++)
{
    if(i%10==0)                     //condition for dotted, only at %10=0, a dot will appear
    {
           img.setPixel(x,y,rgb);
    ui->label_5->setPixmap(QPixmap::fromImage(img));
    }
    x=x+x_1;
    y=y+y_1;
}

}


void linestyles::dashed()                              //DASHED LINE
{

    x1=this->ui->lineEdit->text().toInt();
    y1=this->ui->lineEdit_2->text().toInt();
    x2=this->ui->lineEdit_3->text().toInt();
    y2=this->ui->lineEdit_4->text().toInt();



    int dx=abs(x1-x2);
    int dy=abs(y1-y2);
    QImage img(291,231,QImage::Format_ARGB32);
    QRgb rgb=qRgb(255,255,255);
    img.fill(QColor(Qt::black).rgb());
    int n;
    float x_1,y_1;
    float x,y;
    if(dx>dy)
        n=dx;
    else
        n=dy;

    x_1=(float)dx/n;
    y_1=(float)dy/n;
    img.setPixel(x1,y1,rgb);
x=x1;
y=y1;

x=x1;
y=y1;
for(int i=0;i<n;i++)
{
    if(i%4!=0)          //condition for dashed
    {
           img.setPixel(x,y,rgb);
    ui->label_5->setPixmap(QPixmap::fromImage(img));
    }
    x=x+x_1;
           y=y+y_1;
}
}


void linestyles::dashdot()
{

    x1=this->ui->lineEdit->text().toInt();
    y1=this->ui->lineEdit_2->text().toInt();
    x2=this->ui->lineEdit_3->text().toInt();
    y2=this->ui->lineEdit_4->text().toInt();

    int dx=abs(x1-x2);
    int dy=abs(y1-y2);
    //display(dx,dy);
    //int g=0;
   // display(dx,dy,g);
    QImage img(291,231,QImage::Format_ARGB32);
    QRgb rgb=qRgb(255,255,255);
    img.fill(QColor(Qt::black).rgb());
    int n;
    float x_1,y_1;
    float x,y;
    if(dx>dy)
        n=dx;
    else
        n=dy;

    x_1=(float)dx/n;
    y_1=(float)dy/n;
    img.setPixel(x1,y1,rgb);


x=x1;
y=y1;
for(int i=0;i<n;i++)
{
    if(i%6!=0&&i%8!=0)                                               //condn for dashed dotted
    {

           img.setPixel(x,y,rgb);
    ui->label_5->setPixmap(QPixmap::fromImage(img));
    }
    x=x+x_1;
           y=y+y_1;
}

}



void linestyles::thick()
{

    int steps,i,x,y,wy,w,m;
    int xinc,yinc;

    QImage *q;
    q=new QImage(300,280,QImage::Format_ARGB32 );
    QRgb value=qRgb(255,255,255);


    x1=this->ui->lineEdit->text().toInt();
    y1=this->ui->lineEdit_2->text().toInt();
    x2=this->ui->lineEdit_3->text().toInt();
    y2=this->ui->lineEdit_4->text().toInt();

    w=this->ui->lineEdit_5->text().toInt();


    if(abs(x2-x1)>=(y2-y1))
        steps=abs(x2-x1);
    else
        steps=abs(y2-y1);

    xinc=float(x2-x1)/steps;
    yinc=float(y2-y1)/steps;

    x=x1;
    y=y1;


    m=(y2-y1)/(x2-x1);

if(m<1)
{

    wy=((w-1)/2)*sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/abs(x2-x1);
    for(i=0;i<steps;i++)
    {
    for(int j=0;j<wy;j++)
    {
    q->setPixel(x,y,value);
    q->setPixel(x,y+j,value);
    q->setPixel(x,y-j,value);
    }
    x=x+xinc;
    y=y+yinc;

    ui->label_5->setPixmap(QBitmap::fromImage(*q));

    }
}
    else
    {

    wy=((w-1)/2)*sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/abs(y2-y1);

    for(i=0;i<steps;i++)
    {
    for(int j=0;j<wy;j++)
    {
    q->setPixel(x,y,value);
    q->setPixel(x+j,y,value);
    q->setPixel(x-j,y,value);
    }
    x=x+xinc;
    y=y+yinc;

    ui->label_5->setPixmap(QBitmap::fromImage(*q));

    }
    }

}

void linestyles::clear()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->label_5->clear();
}



int linestyles::sign(int p)
{
    if(p<0)
        return -1;
    else if(p==0)
        return 0;
    else
        return 1;
}

