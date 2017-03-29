#ifndef LINE_H
#define LINE_H

#include <QMainWindow>

namespace Ui {

class line;

}

class line : public QMainWindow
{
    Q_OBJECT
    float x1,x2,y1,y2;

public:
    explicit line(QWidget *parent = 0);
    ~line();

private:
    Ui::line *ui;
private slots:
    void display();                     //DDA
    void display(int dx,int dy,int e); //Bresenhems
    void input();
    int sign(int val);
};

#endif // LINE_H
