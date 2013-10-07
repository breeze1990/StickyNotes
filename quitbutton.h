#ifndef QUITBUTTON_H
#define QUITBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <iostream>
#include <QSizePolicy>
#include "mycolor.h"
#include "rectstylebutton.h"

class myQuitButton : public RectStyleButton
{
    Q_OBJECT

public:
    explicit myQuitButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void paintButton(QPainter& paint);
};

#endif // QUITBUTTON_H
