#include "nwindow.h"
using namespace std;

nWindow::nWindow(QWidget *parent, int pnum) : QWidget(parent)
{
    strContent="Hello world.";
    winNumber = pnum;
    rcfile = fpre + QString::number(pnum);
    loadSettings();
    initWindow();

    paintWindow();

    QObject::connect(qtBut,SIGNAL(clicked()),this,SLOT(handleClose()));
    QObject::connect(this,SIGNAL(closeWindow()),this,SLOT(close()));
    QObject::connect(sButton,SIGNAL(clicked()),this,SLOT(updateStyle()));
    QObject::connect(this,SIGNAL(myPaint()),addButton,SLOT(update()));
    QObject::connect(this,SIGNAL(myPaint()),qtBut,SLOT(update()));
    QObject::connect(this,SIGNAL(myPaint()),sButton,SLOT(update()));
    QObject::connect(addButton,SIGNAL(clicked()),this,SLOT(createWindow()));
    QObject::connect(mTextEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),
                     this,SLOT(paintTextEdit(QTextCharFormat)));
    QObject::connect(mTextEdit,SIGNAL(textChanged()),this,SLOT(updateContent()));
}

void nWindow::initWindow(){

    sButton = new styleButton(this);
    addButton = new myAddButton(this);
    mainLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    botLayout = new QHBoxLayout();
    mTextEdit = new QTextEdit(this);
    qtBut = new myQuitButton(this);
    mTextEdit->setFrameStyle(QFrame::NoFrame);
    mTextEdit->setAutoFillBackground(true);

    botLayout ->addWidget(mTextEdit);

    topLayout->addWidget(addButton,Qt::AlignLeft);
    topLayout->addWidget(sButton);
    topLayout->addStretch(0);
    topLayout->addWidget(qtBut,Qt::AlignRight);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(botLayout);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);


    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(200,200);
}
void nWindow::mousePressEvent(QMouseEvent *event){
  this->windowPos = this->pos();
  this->mousePos = event->globalPos();
  this->dPos = mousePos - windowPos;
}
void nWindow::mouseMoveEvent(QMouseEvent *event){
  this->move(event->globalPos() - this->dPos);
}
void nWindow::paintTextEdit(QTextCharFormat)
{
    mTextEdit->setFontPointSize(15);
    mTextEdit->setTextColor(clr.textColor);
    mTextEdit->setFontFamily("consolas");
}
void nWindow::paintWindow()
{
    QPalette bgTextPlt,bgWindowPlt;
    bgTextPlt.setColor(QPalette::Base, clr.bgTextEdit);
    bgWindowPlt.setColor(QPalette::Window, clr.bgWindow);

    mTextEdit->setPalette(bgTextPlt);
    paintTextEdit(QTextCharFormat());
    mTextEdit->setText(strContent);

    addButton->setClrStyle(clr);
    sButton->setClrStyle(clr);
    qtBut->setClrStyle(clr);
    this->setPalette(bgWindowPlt);
}

void nWindow::updateStyle(){
    clr.nextStyle();

    paintWindow();
    emit myPaint();
}

void nWindow::saveSettings()
{
    QFile outf(rcfile);
    if(strContent.isEmpty()) {
        outf.remove();
        return;
    }
    if(outf.open(QIODevice::WriteOnly)){
        QJsonObject rcobj;
        rcobj["posx"] = this->pos().x();
        rcobj["posy"] = this->pos().y();
        rcobj["style"] = clr.retStyleNumber();
        rcobj["content"] = strContent;
        QJsonDocument saveDoc(rcobj);
        outf.write(saveDoc.toJson());
        outf.close();
    } else {
        qWarning("save failed.");
        return;
    }
}

void nWindow::loadSettings()
{
    clr = myColor(0,2);
    QFile loadFile(rcfile);
    if(loadFile.open(QIODevice::ReadOnly)){
        QPoint p;
        int s;
        QByteArray data = loadFile.readAll();
        QJsonDocument ldDoc(QJsonDocument::fromJson(data));
        QJsonObject ldObj = ldDoc.object();
        p.setX((int) ldObj["posx"].toDouble());
        p.setY((int) ldObj["posy"].toDouble());
        s = (int) ldObj["style"].toDouble();
        clr.changeStyle(s);
        this->move(p);
        strContent.clear();
        strContent+= ldObj["content"].toString();
    } else return;
    loadFile.close();
}
void nWindow::handleClose(){
    saveSettings();
    emit closeWindow();
}
void nWindow::createWindow()
{
    int i;
    nWindow *win;
    fstream f;
    for(i=0;i<100;i++)
    {
        QString tmpn = fpre + QString::number(i);
        f.open(tmpn.toStdString());
        if(!f.good())break;
        else f.close();
    }
    win = new nWindow(0,i);
    win -> show();
    win ->move(this->pos()+QPoint(50,50));
}
void nWindow::updateContent()
{
    strContent = mTextEdit->toPlainText();
    saveSettings();
}
