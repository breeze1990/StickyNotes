#ifndef RECTSTYLEBUTTON_H
#define RECTSTYLEBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QSizePolicy>
#include "mycolor.h"

#define mouseOver 1
#define mouseFree 2


class RectStyleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit RectStyleButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *);
    void setClrStyle(myColor c);


protected:
    int buttonState;
    myColor clr;
    QBrush bfree,bover,bdown;
    QPen pfree,pover,pdown;

    virtual void setButStyle(QPainter &painter);
    virtual void paintButton(QPainter& paint)=0;
};

#endif // RECTSTYLEBUTTON_H
