#include "nwindow.h"
#include <QDir>

using namespace std;

QString fpre = "notesrc";

int main(int argc,char **argv){
    QApplication app(argc,argv);
    nWindow *win;
    QDir::setCurrent(QApplication::applicationDirPath());
    int i,p=0;
    ifstream f;
    for(i=0;i<100;i++){
        QString fbuf(fpre+QString::number(i));
        f.open(fbuf.toStdString());
        if(f.good()){
            win = new nWindow(0,i);
            win->show();
            p=1;
            f.close();
        }
    }
    if(!p) {
        win = new nWindow(0,0);
        win -> show();
    }
    return app.exec();
}
