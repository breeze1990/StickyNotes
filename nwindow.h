#ifndef NWINDOW_H
#define NWINDOW_H

#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include "quitbutton.h"
#include "mycolor.h"
#include "myaddbutton.h"
#include "stylebutton.h"
#include <fstream>
#include <cstdlib>

class nWindow : public QWidget
{
    Q_OBJECT
public:
    explicit nWindow(QWidget *parent = 0, int pnum = 1);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintWindow();

    myAddButton *addButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout,*botLayout;
    QPushButton *quitButton;
    myQuitButton *qtBut;
    QTextEdit *mTextEdit;
    QPoint windowPos,mousePos,dPos;
    styleButton *sButton;
protected:
    void initWindow();
private:
    myColor clr;
    int winNumber;
    QString strContent;

    void loadSettings();
    void saveSettings();


signals:
    void myPaint();
    void closeWindow();
private slots:
    void updateStyle();
    void handleClose();
    void createWindow();
    void paintTextEdit(QTextCharFormat);
    void updateContent();
};

#endif // NWINDOW_H
