#include "widget.h"
#include "uicommonframe.h"
#include "example_1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UICommonFrame frame(new Widget);
    frame.show();


    UICommonFrame example1(new Example_1);
    example1.setTitleBarIcon(":/image/cat.ico");
    example1.show();

//    QFrame w;
//    w.setWindowFlags(Qt::FramelessWindowHint);
//    w.setAttribute(Qt::WA_TranslucentBackground);
//    w.show();
    
    return a.exec();
}
