#ifndef GAS_DYNAMICS_H
#define GAS_DYNAMICS_H
#include <stdint.h>
//#include "linear_algebra.h"
#include <vector>
#include <fstream>
#include <QString>

class gas_dynamics
{
    uint32_t N;
    double x_left = -5;
    double x_right = 5;
    double T_max = 2.5;
    double adiabata = 1.4;
    double density_left = 0;//= 1.0;
    double density_right;// = 0.125;
    double velocity_left ;//= 0;
    double velocity_right ;//= 0;
    double pressure_left ;//= 1.0;
    double pressure_right ;//= 0.1;
    QString left = ":/left_side.dat";
    QString right = ":/right_side.dat";
public:
    std::vector<double> nodes;

    std::vector <double> temperature;
    std::vector<double> density;
    std::vector <double> velocity;
    std::vector<double> pressure;
    std::vector<double> entropy;


    std::vector<double> make_nodes();
    gas_dynamics(uint32_t number_of_nodes, double x_left, double x_right, double adiabata, double Tmax);
    double derivative(const double &p3);
    double ExpressionForP3(const double &p3);
    double Newton();
    std::vector<double> Exact(const int &parameter);
    std::vector<double> InitialCondition(const int &parametr);
//    std::vector<double> InitialCondition2(const int &parametr);
    int find_index(const double &value);
    std::vector<double> Entropy();
    std::vector<double> Temperature ();

};

#endif // GAS_DYNAMICS_H
