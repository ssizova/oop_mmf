#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "gas_dynamics.h"
#include <iostream>
#include<QVector>
#include <QtWidgets>
#include <iostream>
#include <QObject>
#include<vector>
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <sstream>

auto g = 100;
void MainWindow::correctPlot(QCustomPlot* chart, QVector<double> x,
                             QVector<double> y, QString x_axis,QString y_axis){
    QPen* pen = new QPen;
    pen->setWidth(5);
    pen->setColor(QColor(127, g, 143));
    chart->clearGraphs();
    chart->addGraph();
    chart->graph(0)->setData(x,y);
    chart->xAxis->setLabel(x_axis);
    chart->yAxis->setLabel(y_axis);
    chart->xAxis->rescale(true);
    chart->yAxis->rescale(true);
    chart->graph(0)->setAdaptiveSampling(true);
    chart->graph()->setPen(*pen);
    chart->setBackgroundScaled(true);
    g+=30;
}

void MainWindow::Calculate() {
    double x_left = from->text().toDouble();
    double x_right = to->text().toDouble();
    uint32_t number_of_nodes = static_cast<uint32_t>(N->text().toDouble());
    double tmax = final_time->text().toDouble();
    double gamma = adiabata->text().toDouble();
    initial_parameters conditions;

    try {
        auto solver = gas_dynamics(number_of_nodes,x_left,x_right,gamma,tmax, conditions);
        auto nodes = solver.nodes;

        auto density_exact = solver.density;
        auto pressure_exact = solver.pressure;
        auto velocity_exact = solver.velocity;
        auto entropy_exact = solver.entropy;
        auto temperature_exact = solver.temperature;


        QVector<double> x = QVector<double>::fromStdVector(nodes);
        QVector<double> dens = QVector<double>::fromStdVector(density_exact);
        QVector<double> pres = QVector<double>::fromStdVector(pressure_exact);
        QVector<double> vel = QVector<double>::fromStdVector(velocity_exact);
        QVector<double> ent = QVector<double>::fromStdVector(entropy_exact);
        QVector<double> temp = QVector<double>::fromStdVector(temperature_exact);

        correctPlot(density,x,dens,"x","density");
        correctPlot(pressure,x,pres,"x","pressure");
        correctPlot(velocity,x,vel,"x","velocity");
        correctPlot(temperature,x,ent,"x","temperature");
        correctPlot(entropy,x,temp,"x","entropy");

        vertical->addWidget(density,40);
        vertical->addWidget(pressure,40);
        charts_right->addWidget(velocity,33);
        charts_right->addWidget(temperature,33);
        charts_right->addWidget(entropy,33);
        global->addLayout(charts_right,50);
    } catch(std::exception &error){
        QMessageBox::warning(this,"Validation error", error.what());
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    from->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    to->setStyleSheet(
                "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    N->setStyleSheet(
                "QLineEdit { background: rgb(254, 209, 153); selection-background-color: rgb(255,255, 255); }");
    final_time->setStyleSheet(
                "QLineEdit { background: rgb(158, 227, 173); selection-background-color: rgb(255,255, 255); }");
    adiabata->setStyleSheet(
                "QLineEdit { background: rgb(158, 227, 243); selection-background-color: rgb(255,255, 255); }");



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


