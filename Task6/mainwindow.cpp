#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

#include<QVector>
#include <QtWidgets>
#include <iostream>
#include <QObject>


void MainWindow::Calculate() {
    double A = coeffA->text().toDouble();
    double B = coeffB->text().toDouble();
    double C = coeffC->text().toDouble();
    auto data = FunctionMaker(A, B, C);
    auto y = data.function_points;
    auto x = data.nodes;

    QVector<double> x_nodes = QVector<double>::fromStdVector(x);
    QVector<double> y_nodes = QVector<double>::fromStdVector(y);
    QPen* pen = new QPen;
    pen->setWidth(5);
    pen->setColor(QColor(127, 242, 143));
    chart->clearGraphs();
    chart->addGraph();
    chart->graph()->setPen(*pen);
    chart->graph(0)->setData(x_nodes,y_nodes);

    chart->xAxis->setLabel("x");
    chart->yAxis->setLabel("y");

    chart->xAxis->rescale(true);
    chart->yAxis->rescale(true);
    chart->graph(0)->setAdaptiveSampling(true);
    chart->setBackgroundScaled(true);
    chart->replot();
    horizontal->addWidget(chart,80);


    QPixmap myPixmap;
    myPixmap.load(":/magistr_Ioda.jpg");
    myPixmap.setDevicePixelRatio(5);

    QLabel *picture = new QLabel();
    picture->setPixmap(myPixmap);
    layout->addWidget(picture);


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    chart = new QCustomPlot();

    coeffA->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    coeffB->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    coeffC->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");

    QWidget *widget = new QWidget();


    QPushButton *calcBtn = new QPushButton("Calculate");

    QObject::connect(calcBtn, SIGNAL(released()), this, SLOT(Calculate()));

    QLabel *lblA = new QLabel("Coeff A");
    QLabel *lblB = new QLabel("Coeff B");
    QLabel *lblC = new QLabel("Coeff C");



    layout->addWidget(lblA);
    layout->addWidget(coeffA);

    layout->addWidget(lblB);
    layout->addWidget(coeffB);

    layout->addWidget(lblC);
    layout->addWidget(coeffC);

    layout->addStretch();

    layout->addWidget(calcBtn);
    setCentralWidget(widget);

    horizontal->addLayout(layout,20);
    widget->setLayout(horizontal);
}


MainWindow::~MainWindow() {
    delete ui;

}



