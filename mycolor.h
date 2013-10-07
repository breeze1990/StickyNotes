#ifndef MYCOLOR_H
#define MYCOLOR_H

#include <QColor>

class myColor
{
public:
    myColor(int mode,int t);
    myColor(myColor& c);
    myColor();
    void changeStyle(int f);
    void nextStyle();
    int retStyleNumber();

    static QColor cyan;
    static QColor white;
    static QColor black;
    static QColor gray;
    static QColor gray2;

    QColor textColor;
    QColor bgTextEdit;
    QColor bgWindow;
    QColor bgButFree;
    QColor bgButOver;
    QColor bgButDown;
    QColor ptButFree;
    QColor ptButOver;
    QColor ptButDown;
//private:
    int styleNumber;
    int total;
};

#endif // MYCOLOR_H
