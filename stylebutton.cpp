#include "stylebutton.h"

styleButton::styleButton(QWidget *parent):RectStyleButton(parent)
{
}

void styleButton::paintButton(QPainter &paint)
{
    paint.drawRect(QRect(0,0,10,10));
}
void styleButton::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    setButStyle(painter);
    paintButton(painter);
}
