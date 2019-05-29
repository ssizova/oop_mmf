#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "gas_dynamics.h"

#include<QVector>
#include <QtWidgets>
#include <iostream>
#include <QObject>
#include<vector>

void MainWindow::correctPlot(QCustomPlot* chart, QVector<double> x,
                             QVector<double> y, QString x_axis,QString y_axis){
    chart->clearGraphs();
    chart->addGraph();
    chart->graph(0)->setData(x,y);
    chart->xAxis->setLabel(x_axis);
    chart->yAxis->setLabel(y_axis);
    chart->xAxis->rescale(true);
    chart->yAxis->rescale(true);
    chart->graph(0)->setAdaptiveSampling(true);
    chart->setBackgroundScaled(true);
}

void MainWindow::Calculate() {
    //    double A = coeffA->text().toDouble();
    //    double B = coeffB->text().toDouble();
    //    double C = coeffC->text().toDouble();
    std::size_t N = 10;
    std::vector<double> x = {0,1,2,3};

    std::vector<double> y = {0,1,4,9};

    QVector<double> x_nodes = QVector<double>::fromStdVector(x);
    QVector<double> y_nodes = QVector<double>::fromStdVector(y);

    auto module = gas_dynamics(100,-5,5,1.4,2.5);
    auto density_exact = module.Exact(3,2.5);
    auto x1 = module.nodes;
//    std::cout<< density_exact.size();

    QVector<double> x_d = QVector<double>::fromStdVector(x1);
    QVector<double> dens = QVector<double>::fromStdVector(density_exact);

    correctPlot(density,x_d,dens,"t","density");
    correctPlot(pressure,x_nodes,y_nodes,"t","pressure");
    correctPlot(velocity,x_nodes,y_nodes,"t","velocity");
    correctPlot(temperature,x_nodes,y_nodes,"t","temperature");
    correctPlot(entropy,x_nodes,y_nodes,"t","entropy");

    vertical->addWidget(density,40);
    vertical->addWidget(pressure,40);
    charts_right->addWidget(velocity,33);
    charts_right->addWidget(temperature,33);
    charts_right->addWidget(entropy,33);
    //    global->addLayout(charts_right);
    global->addLayout(charts_right,50);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    from->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    to->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    adiabata->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    N->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    final_time->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");

    left.setFileName("left_side.dat");
    right.setFileName("right_side.dat");

    QWidget *widget = new QWidget();
    density = new QCustomPlot();
    pressure = new QCustomPlot();
    velocity = new QCustomPlot();
    temperature = new QCustomPlot();
    entropy = new QCustomPlot();



    QLabel *fromx = new QLabel("From x = ");
    QLabel *tox = new QLabel("To x = ");
    QLabel *ad_coeff = new QLabel("Adiabatic coefficient: ");
    QLabel *number_of_nodes = new QLabel("N: ");
    QLabel *time = new QLabel ("T: ");
    QLabel *welcome = new QLabel("Enter your parameters");



    forx->addWidget(fromx);
    forx->addWidget(from);
    forx->addWidget(tox);
    forx->addWidget(to);

    forN->addWidget(number_of_nodes);
    forN->addWidget(N);

    fort->addWidget(time);
    fort->addWidget(final_time);

    forAdiabat->addWidget(ad_coeff);
    forAdiabat->addWidget(adiabata);

    auxillary->addWidget(welcome);
    auxillary->addStretch();
    auxillary->addLayout(forx);
    auxillary->addLayout(forN);
    auxillary->addLayout(fort);
    auxillary->addLayout(forAdiabat);
    vertical->addLayout(auxillary,15);

    QPushButton *calcBtn = new QPushButton("Calculate");
    QObject::connect(calcBtn, SIGNAL(released()), this, SLOT(Calculate()));
    vertical->addWidget(calcBtn,5);
    //    vertical->addStretch();
    global->addLayout(vertical,50);
    setCentralWidget(widget);

    widget->setLayout(global);
}



MainWindow::~MainWindow() {
    delete ui;

}
