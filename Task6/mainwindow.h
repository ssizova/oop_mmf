#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<QtWidgets>
#include <QObject>
#include<iostream>
#include "functionmaker.h"
#include "qcustomplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    QCustomPlot *chart;

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QLineEdit* coeffA = new QLineEdit;
    QLineEdit* coeffB = new QLineEdit;
    QLineEdit* coeffC = new QLineEdit;
    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout *horizontal = new QBoxLayout(QBoxLayout::LeftToRight);
    QLabel* lblB;


public slots:
    void Calculate ();

private:
    Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
