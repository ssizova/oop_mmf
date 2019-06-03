#ifndef INITIAL_PARAMETERS_H
#define INITIAL_PARAMETERS_H
#include <sstream>
#include <QFile>
#include <iostream>
#include <QObject>
#include <QTextStream>

struct initial_parameters{
    double density_left = 0;
    double pressure_left = 0;
    double velocity_left = 0;

    double density_right = 0;
    double pressure_right = 0;
    double velocity_right = 0;

    initial_parameters()
    {
        QFile lfile(":/left_side.dat");
        lfile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&lfile);
        std::string lstr;
        while (!in.atEnd()) {
            QString line = in.readLine() + "\n";
            lstr += line.toUtf8().constData();
        }

        QFile rfile(":/right_side.dat");
        rfile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream rin(&rfile);
        std::string rstr;
        while (!rin.atEnd()) {
            QString line = rin.readLine() + "\n";
            rstr += line.toUtf8().constData();
        }

        auto l = std::stringstream(lstr);
        auto r = std::stringstream(rstr);

        l >> density_left;
        l >>  pressure_left;
        l >>  velocity_left;

        r >> density_right;
        r >> pressure_right;
        r >> velocity_right;
    }
};

#endif // INITIAL_PARAMETERS_H
