#include "mycolor.h"

myColor::myColor(int mode,int t)
{
    styleNumber = mode;
    total = t;
    changeStyle(styleNumber);
}
myColor::myColor(myColor& c){
    styleNumber = c.styleNumber;
    total = c.total;
    changeStyle(styleNumber);
}
myColor::myColor(){
    styleNumber = 0;
    total = 2;
    changeStyle(styleNumber);
}
void myColor::changeStyle(int f)
{
    if(f<0 || f>=total)f=styleNumber;
    else{styleNumber = f;}
    switch(f){
    case 0:
        bgTextEdit = gray;
        bgWindow = cyan;
        bgButFree = cyan;
        bgButOver = white;
        bgButDown = gray;
        ptButFree = white;
        ptButOver = cyan;
        ptButDown = gray2;
        textColor = cyan;
        break;
    case 1:
        bgTextEdit = cyan;
        bgWindow = gray;
        bgButFree = gray;
        bgButOver = gray2;
        bgButDown = cyan;
        ptButFree = white;
        ptButOver = cyan;
        ptButDown = white;
        textColor = white;
        break;
    default:
        break;
    }
}

void myColor::nextStyle(){
    styleNumber = (styleNumber+1)%total;
    changeStyle(-1);
}
int myColor::retStyleNumber(){
    return styleNumber;
}
QColor myColor::cyan = QColor(0,120,200);
QColor myColor::white= QColor(255,255,255);
QColor myColor::black= QColor(0,0,0);
QColor myColor::gray = QColor(234,234,234);
QColor myColor::gray2= QColor(180,180,180);
