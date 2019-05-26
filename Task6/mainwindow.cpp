#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <iostream>
#include <QObject>
//#include <QtChart>

void MainWindow::Calculate() {
    double A = coeffA->text().toDouble();
    double B = coeffB->text().toDouble();
    double C = coeffC->text().toDouble();
    auto k = FunctionMaker(A, B, C).function_points;
    std::cout << A << " " << B << " " << C << std::endl;

    for (auto i = 0; i < k.size(); ++i)
        std::cout << k[i] << std::endl;
}

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    coeffA->setStyleSheet(
            "QLineEdit { background: rgb(250, 199, 216); selection-background-color: rgb(255,255, 255); }");
    coeffB->setStyleSheet(
            "QLineEdit { background: rgb(252, 242, 147); selection-background-color: rgb(255,255, 255); }");
    coeffC->setStyleSheet(
            "QLineEdit { background: rgb(127, 242, 143); selection-background-color: rgb(255,255, 255); }");

    QWidget *widget = new QWidget(this);

    QPushButton *calcBtn = new QPushButton("Calculate");

    QObject::connect(calcBtn, SIGNAL(released()), this, SLOT(Calculate()));

    QLabel *lblA = new QLabel("Coeff A");
    QLabel *lblB = new QLabel("Coeff B");
    QLabel *lblC = new QLabel("Coeff C");

    //    lblA->setBuddy(coeffA);
    //    QObject::connect(coeffA,SIGNAL(textChanged(const QString&)),lblA,SLOT(setText(const QString&)));

    QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout *horizontal = new QBoxLayout(QBoxLayout::LeftToRight);
    QPushButton *future = new QPushButton("Here will be a graph");

    layout->addWidget(lblA);
    layout->addWidget(coeffA);

    layout->addWidget(lblB);
    layout->addWidget(coeffB);

    layout->addWidget(lblC);
    layout->addWidget(coeffC);

    layout->addStretch();

    layout->addWidget(calcBtn);
    setCentralWidget(widget);

    horizontal->addLayout(layout);
    horizontal->addWidget(future);
    widget->setLayout(layout);
    widget->setLayout(horizontal);

    widget->show();

}


MainWindow::~MainWindow() {
    delete ui;

}


void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    //     DRAW SOMETHING
    //    painter.drawPoint(100, 100);
    //    painter.drawRect(QRect(80, 120, 200, 100));
    //    painter.setBrush(
    //    QPalette clr = painter.palette();
    //   painter.setBrush(Qt::yellow);
}
