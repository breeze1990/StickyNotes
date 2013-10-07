#ifndef MYADDBUTTON_H
#define MYADDBUTTON_H

#include <QPushButton>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include "mycolor.h"
#include "rectstylebutton.h"

class myAddButton : public RectStyleButton
{
    Q_OBJECT
public:
    explicit myAddButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void paintButton(QPainter& paint);

signals:

public slots:

};

#endif // MYADDBUTTON_H
