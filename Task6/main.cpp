
#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  QDesktopWidget dw;
  MainWindow w;
//  int x=dw.width()*0.7;
//  int y=dw.height()*0.7;
//  w.setFixedSize(x,y);
  w.show();

  return a.exec();
}


//Somewhere in your QMainWindow constructor, do this:


