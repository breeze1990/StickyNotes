#include "quitbutton.h"
using namespace std;

myQuitButton::myQuitButton(QWidget *parent):RectStyleButton(parent)
{
}

void myQuitButton::paintButton(QPainter &paint){
    paint.drawLine(7,7,13,13);
    paint.drawLine(13,7,7,13);
}
void myQuitButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    setButStyle(painter);
    paintButton(painter);
}
