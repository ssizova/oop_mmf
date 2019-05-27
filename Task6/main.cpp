#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

//#include "functionmaker.h"
int main(int argc, char *argv[]) {

    QFile("magistr_Ioda.jpg");
    QApplication a(argc, argv);
    QDesktopWidget dw;
    MainWindow w;
    w.show();

    return a.exec();
}


//Somewhere in your QMainWindow constructor, do this:


