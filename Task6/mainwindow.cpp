#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

#include<QVector>
#include <QtWidgets>
#include <iostream>
#include <QObject>
//#include <QtChart>

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
//    chart->graph(0)->setPen(QColor(127, 242, 143));
    chart->graph()->setPen(*pen);
    chart->graph(0)->setData(x_nodes,y_nodes);

    chart->xAxis->rescale(true);
    chart->yAxis->rescale(true);
    chart->graph(0)->setAdaptiveSampling(true);
    chart->setBackgroundScaled(true);
    chart->replot();
    horizontal->addWidget(chart,66);


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


    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);

    layout->addWidget(lblA);
    layout->addWidget(coeffA);

    layout->addWidget(lblB);
    layout->addWidget(coeffB);

    layout->addWidget(lblC);
    layout->addWidget(coeffC);

    layout->addStretch();

    layout->addWidget(calcBtn);
    setCentralWidget(widget);

    horizontal->addLayout(layout,33);
    widget->setLayout(horizontal);
}


MainWindow::~MainWindow() {
    delete ui;

}



