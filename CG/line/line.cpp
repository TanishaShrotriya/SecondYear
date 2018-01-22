#include "line.h"
#include "ui_line.h"
#include "math.h"
#include "QtGui"

line::line(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::line)
{
    ui->setupUi(this);
    connect(this->ui->p1,SIGNAL(clicked()),this,SLOT(input()));
     connect(this->ui->p2,SIGNAL(clicked()),this,SLOT(clear()));
}

line::~line()
{
    delete ui;
}

void line:: input() {

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();
    display();
    display(abs(x2-x1),abs(y2-y1),0);
}
void line::display() {

    float steps=0,xInc,yInc,x,y,i=0;
    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);
    q->fill(QColor(Qt::black).value());

    if(abs(x2-x1)>=abs(y2-y1)) {
      steps= abs(x2-x1);
    }
    else {
      steps=abs(y2-y1);
    }
    xInc=(x2-x1)/steps;
    yInc=(y2-y1)/steps;
    x=x1;
    y=y1;

    while(i<=steps) {

        ui->l1->setPixmap(QBitmap::fromImage(*q));
        q->setPixel(round(x),round(y),value);
        x=x+xInc;
        y=y+yInc;
        i++;
    }

}

void line::display(int dx ,int dy,int e) {

    int temp,x,y,interchange,s1,s2;
    x=x1;
    y=y1;
    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);

    s1=sign(x2-x1);
    s2=sign((y2-y1));

    if(dy>dx) {
        temp=dx;
        dx=dy;
        dy=temp;
        interchange=1;
    }
    else {
        interchange=0;
    }
    e=(2*dy)-dx;

    for(int i=1;i<=dx;i++) {

        ui->l5->setPixmap(QBitmap::fromImage(*q));
        q->setPixel(round(x),round(y),value);
        while(e>0) {
            if(interchange==1) {
                x=x+s1;
            }
            else {
                y=y+s2;
            }
            e=e-(2*dx);

        }
        if(interchange==1) {
            y=y+s2;
        }
        else {
            x=x+s1;
        }
        e=e+(2*dy);
    }

}

int line:: sign(int val) {
    if(val<0)
        return -1 ;
    else if(val==0)
        return 0 ;
    else
        return 1;
}


void line::clear()
{
    ui->l1->clear();
    ui->l5->clear();
    ui->te1->setText("");
    ui->te3->setText("");
    ui->te4->setText("");
    ui->te2->setText(" ");

}
