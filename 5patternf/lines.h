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
    void pattern_();
    void pattern();
    void display(int x2, int y2, int x1, int y1,QImage *q, QRgb value);                     //DDA -thinline
    void clear();
};

#endif // LINE_H
