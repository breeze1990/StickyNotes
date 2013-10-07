#ifndef STYLEBUTTON_H
#define STYLEBUTTON_H

#include "rectstylebutton.h"

class styleButton : public RectStyleButton
{
public:
    styleButton(QWidget *parent = 0);
    void paintButton(QPainter& paint);
    void paintEvent(QPaintEvent *e);
};

#endif // STYLEBUTTON_H
