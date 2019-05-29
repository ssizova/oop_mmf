#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include<QtWidgets>
#include <QObject>
#include <QFile>
#include<iostream>
#include "qcustomplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    QCustomPlot *density;
    QCustomPlot *velocity;
    QCustomPlot *temperature;
    QCustomPlot *entropy;
    QCustomPlot *pressure;

    QFile left;
    QFile right;
public:
    void correctPlot(QCustomPlot* chart, QVector<double> x,
                     QVector<double> y, QString x_axis,QString y_axis);
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    QLineEdit* from = new QLineEdit;
    QLineEdit* to = new QLineEdit;
    QLineEdit* adiabata = new QLineEdit;
    QLineEdit* N = new QLineEdit;
    QLineEdit* final_time = new QLineEdit;


    QBoxLayout *vertical = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout *global = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *forx = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *forN = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *fort = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *forAdiabat = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout *auxillary = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * charts_right = new QBoxLayout(QBoxLayout::TopToBottom);


public slots:
    void Calculate ();

private:
    Ui::MainWindow* ui;
};

#endif  // MAINWINDOW_H
