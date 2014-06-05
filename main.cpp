#include "nwindow.h"
#include "QDir"
#include <QDir>

using namespace std;

int main(int argc,char **argv){
    QApplication app(argc,argv);
    nWindow *win;
    QDir::setCurrent(QApplication::applicationDirPath());
    char buf[10]="notesrc";
    int i,p=0;
    ifstream f;
    for(i=0;i<100;i++){
        sprintf(buf+7,"%d",i);
        f.open(buf);
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
