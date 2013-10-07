#include "myaddbutton.h"
#include "iostream"
using namespace std;

myAddButton::myAddButton(QWidget *parent) :
    RectStyleButton(parent)
{
}

void myAddButton::paintButton(QPainter &paint){
    paint.drawLine(7,10,13,10);
    paint.drawLine(10,7,10,13);
}
void myAddButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    setButStyle(painter);
    paintButton(painter);
}
