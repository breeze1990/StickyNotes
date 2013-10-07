#include "rectstylebutton.h"
#include <iostream>

RectStyleButton::RectStyleButton(QWidget *parent) :
    QPushButton(parent)
{
    QSizePolicy mySP;
    mySP.setVerticalPolicy(QSizePolicy::Ignored);
    mySP.setHorizontalPolicy(QSizePolicy::Ignored);
    this->setSizePolicy(mySP);
    this->setMaximumSize(20,20);
    this->setMinimumSize(20,20);
    this->setMouseTracking(true);
    buttonState = mouseFree;
    setCheckable(true);
    setChecked(false);
    clr=myColor();
}
void RectStyleButton::paintEvent(QPaintEvent *){
}
void RectStyleButton::enterEvent(QEvent *e)
{
    buttonState = mouseOver;
    this->QPushButton::enterEvent(e);
}
void RectStyleButton::leaveEvent(QEvent *e){
    buttonState = mouseFree;
    this->QPushButton::leaveEvent(e);
}
void RectStyleButton::mousePressEvent(QMouseEvent *e){
    this->QPushButton::mousePressEvent(e);
}
void RectStyleButton::mouseMoveEvent(QMouseEvent *){}
void RectStyleButton::mouseReleaseEvent(QMouseEvent *e)
{
    buttonState = mouseOver;
    this->QPushButton::mouseReleaseEvent(e);
}
void RectStyleButton::resizeEvent(QResizeEvent *){}

void RectStyleButton::setClrStyle(myColor c){
    clr = c;
}
void RectStyleButton::setButStyle(QPainter& painter){
    pover.setStyle(Qt::SolidLine);
    pover.setCapStyle(Qt::RoundCap);
    pover.setJoinStyle(Qt::RoundJoin);
    pover.setWidth(2);
    pover.setColor(clr.ptButOver);
    pdown.setWidth(2);
    pdown.setColor(clr.ptButDown);
    pdown.setStyle(Qt::SolidLine);
    pdown.setCapStyle(Qt::RoundCap);
    pdown.setJoinStyle(Qt::RoundJoin);
    pfree.setWidth(2);
    pfree.setStyle(Qt::SolidLine);
    pfree.setCapStyle(Qt::RoundCap);
    pfree.setJoinStyle(Qt::RoundJoin);
    pfree.setColor(clr.ptButFree);

    bover.setColor(clr.bgButOver);
    bover.setStyle(Qt::SolidPattern);
    bdown.setColor(clr.bgButDown);
    bdown.setStyle(Qt::SolidPattern);
    bfree.setColor(clr.bgButFree);
    bfree.setStyle(Qt::SolidPattern);
    switch(buttonState){
    case mouseOver:
        painter.fillRect(QRect(0,0,20,20),bover);
        painter.setPen(pover);
        break;
    case mouseFree:
    default:
        painter.fillRect(QRect(0,0,20,20),bfree);
        painter.setPen(pfree);
        break;
    }
    if(isDown()){
        painter.fillRect(QRect(0,0,20,20),bdown);
        painter.setPen(pdown);
    }
}
void RectStyleButton::paintButton(QPainter &paint)
{
}
