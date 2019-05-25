#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //  // HOW TO ADD BUTTON or INPUT
    //  QPushButton* train_button = new QPushButton(widget); //method .isChecked();
    //  train_button->setText(tr("my button title"));
    //  setCentralWidget(widget);

    //    QWidget* widget = new QWidget(this);
    //    pcmdNormal->setCheckable(true);
    //    pcmdNormal->setText("Calculate");
    //    pcmdNormal->setGeometry(100, 600, 100, 40);
    QWidget* widget = new QWidget(this);

    QPushButton* calcBtn = new QPushButton("Calculate");
    QLineEdit* coeffA = new QLineEdit;
    QLineEdit* coeffB = new QLineEdit;
    QLineEdit* coeffC = new QLineEdit;

    QLabel* lblA = new QLabel("Coeff A");
    QLabel* lblB = new QLabel("Coeff B");
    QLabel* lblC = new QLabel("Coeff C");

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout* horizontal = new QBoxLayout(QBoxLayout::LeftToRight);
    QPushButton* future = new QPushButton("Here will be a graph");

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

void MainWindow::paintEvent(QPaintEvent* event) {
//    QPainter painter(this);

    // DRAW SOMETHING
//    painter.drawPoint(100, 100);
//    painter.drawRect(QRect(80, 120, 200, 100));
}
