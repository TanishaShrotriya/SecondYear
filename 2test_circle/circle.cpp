#include "circle.h"
#include "ui_circle.h"
#include "math.h"
#include <QtGui>

circle::circle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::circle)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(draw()));
}

circle::~circle()
{
    delete ui;
}

void circle::draw()
{
    QImage *q;
    q=new QImage(500,500,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);

    int xc,yc,r;
    xc=this->ui->lineEdit->text().toInt();
    yc=this->ui->lineEdit_2->text().toInt();
    r=this->ui->lineEdit_3->text().toInt();

    int x=0;
    int y=r;
    int di=2*(1-r);
    int limit =0;
    int delta=0;

    while(y>=limit)
    {
       // q->setPixel(x,y,value);
        if(di<0)
        {
            delta=2*di+2*y+1;
            if(delta<=0)
            {
                x=x+1;
                di=di+2*x+1;
            }
            else
            {
                x=x+1;
                y=y-1;
                di=di+2*x-2*y+2;
            }
        }
        else if(di>0)
        {
            delta=2*di+2*y+1;
            if(delta<=0)
            {
                x=x+1;
                y=y-1;
                di=di+2*x+1;
            }
            else
            {
                y=y-1;
                di=di-2*y+1;
            }
        }
        else
        {
            x=x+1;
            y=y-1;
            di=di+2*x-2*y+2;
        }
        q->setPixel(xc+x,yc+y,value);
        q->setPixel(xc-x,yc+y,value);
        q->setPixel(xc+x,yc-y,value);
        q->setPixel(xc-x,yc-y,value);
        q->setPixel(xc+y,yc+x,value);
        q->setPixel(xc-y,yc+x,value);
        q->setPixel(xc+y,yc-x,value);
        q->setPixel(xc-y,yc-x,value);
        ui->label_4->setPixmap(QBitmap::fromImage(*q));

    }
}
