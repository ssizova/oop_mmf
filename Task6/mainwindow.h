#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<QtWidgets>
#include <QObject>
#include<iostream>
#include "functionmaker.h"

//#include <QtChart/QLineSeries>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QLineEdit* coeffA = new QLineEdit;
    QLineEdit* coeffB = new QLineEdit;
    QLineEdit* coeffC = new QLineEdit;
    QLabel* lblB;


    virtual void paintEvent(QPaintEvent* event);

public slots:
    void Calculate ();

private:
    Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
