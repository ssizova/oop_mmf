#include "gas_dynamics.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <sstream>

std::vector<double> gas_dynamics::make_nodes() {
    double step = (x_right - x_left) / N;
    std::vector<double> nodes(N + 1, x_left);
    for (auto i = 1; i <= N; ++i)
        nodes[i] += i * step;
    return nodes;
}

gas_dynamics::gas_dynamics(uint32_t number_of_nodes, double xleft, double xright,
                           double gamma, double Tmax, initial_parameters params) {

    density_left = params.density_left;
    density_right = params.density_right;
    velocity_left = params.velocity_left;
    velocity_right = params.velocity_right;
    pressure_left = params.pressure_left;
    pressure_right = params.pressure_right;

    N = number_of_nodes;
    T_max = Tmax;
    x_left = xleft;
    x_right = xright;
    adiabata = gamma;
    nodes = make_nodes();

    pressure = Exact(3);
    density = Exact(1);
    velocity = Exact(2);
    entropy = Entropy();
    temperature = Temperature();
}

double gas_dynamics::derivative(const double &p3) {

    double a = adiabata - 1;
    double b = adiabata + 1;

    double left_part = -a / adiabata * (2 / a * sqrt(adiabata * pow(pressure_left, 1 / adiabata) / density_left) *
                                        (pow(pressure_left, a * 0.5 / adiabata) - pow(p3, a / 2 / adiabata)) -
                                        velocity_right) * pow(p3, -b * 0.5 / adiabata);
    double right_part = (a - b) * (pressure_right - p3) * (2 * a * pressure_right + b * (pressure_right + p3)) /
                        (a * pressure_right + b * p3) / (a * pressure_right + b * p3) / density_right;
    return left_part - right_part;
}

double gas_dynamics::ExpressionForP3(const double &p3) {
    double a = adiabata - 1;
    double b = adiabata + 1;
    double left_part = 2 / a * sqrt(adiabata * pow(pressure_left, 1.0 / adiabata) / density_left) *
                       (pow(pressure_left, a / 2 / adiabata) - pow(p3, a * 0.5 / adiabata)) - velocity_right;
    double bulky_frac = ((adiabata - 1) * p3 + (adiabata + 1) * pressure_right) /
                        ((adiabata + 1) * p3 + (adiabata - 1) * pressure_right);
    double right_part = (p3 - pressure_right) * (1 - bulky_frac) / density_right;


    return left_part * left_part - right_part;
}


double gas_dynamics::Newton()//perhaps, I will add initial approximation as a parameter
{
    double e = 0.000001;
    double test_pressure = pressure_left;
    double solution_pressure = test_pressure;
    do {
        solution_pressure = test_pressure - ExpressionForP3(test_pressure) / derivative(test_pressure);
        test_pressure = solution_pressure;
    } while (fabs(ExpressionForP3(solution_pressure)) >= e);
    return solution_pressure;
}
std::vector<double> gas_dynamics::InitialCondition(const int &parametr) //1 - rho, 2 - u, 3 - p.
{
    std::vector<double> initial_data(N + 1, 0);
    if (parametr == 1) {
        int j = 0;
        while (j <= int(N / 2)) {
            initial_data[j] = density_left;
            j++;
        }
        for (j = N / 2+1; j <= N; j++)
            initial_data[j] = density_right;
    } else if (parametr == 2) {
        for (int j = 0; j <= int(N / 2); j++)
            initial_data[j] = velocity_left;
        for (int j = int(N / 2)+1; j <= N; ++j) {
            initial_data[j] = velocity_right;
        }
    } else {
        int j = 0;
        while (j <= int(N / 2)) {
            initial_data[j] = pressure_left;
            j++;
        }
        for (j = N / 2+1; j <= N; j++)
            initial_data[j] = pressure_right;
    }
    return initial_data;
}


int gas_dynamics::find_index(const double &value) {
    int j = 0;
    while (nodes[j] < value) {
        j++;
    }
    if (nodes[j] == value) return j;
    else return j - 1;
}

std::vector<double> gas_dynamics::Entropy() {
    std::vector<double> entropy(N + 1, 0);
    for (auto i = 0; i <= N; ++i) {
        entropy[i] = std::log(pressure[i]) - adiabata * std::log(density[i]);
    }

    return entropy;
}

std::vector<double> gas_dynamics::Temperature() {
    std::vector<double> temperature(N + 1, 0);
    for (auto i = 0; i <= N; ++i) {
        temperature[i] = pressure[i] / density[i];
    }

    return temperature;
}

std::vector<double> gas_dynamics::Exact(const int &parameter) //1 - Density, 2 - velocity, 3 - pressure
{
    double a = adiabata - 1;
    double b = adiabata + 1; //just for convinience

    double inverse = 1.0 / adiabata;
    double pressure3 = Newton();
    double velocity3 = 2 / a * sqrt(adiabata * pow(pressure_left, inverse) / density_left) *
                       (pow(pressure_left, a * 0.5 / adiabata) - pow(pressure3, a * 0.5 / adiabata));
    double density3 = density_right * (b * pressure3 + a * pressure_right) / (a * pressure3 + b * pressure_right);

    double Shock_wave_velocity = velocity3 * density3 / (density3 - density_right);

    double c1 = sqrt(adiabata * pressure_left / density_left);
    double density_3a = density_left * pow(pressure3 / pressure_left, inverse);
    double c3_a = sqrt(adiabata * pressure3 / density_3a);

    double x1 = -c1 * T_max;
    double x2 = (velocity3 - c3_a) * T_max;
    double x3 = velocity3 * T_max;
    double x4 = Shock_wave_velocity * T_max;

    if (x1 < x_left || x4 > x_right) {
        std::string exception = "Invalid interval for x! Please, expand it.";
        throw std::runtime_error(exception);
    }

    std::vector<double> ExactDensity = InitialCondition(1);
    std::vector<double> ExcactVelocity = InitialCondition(2);
    std::vector<double> ExcactPressure = InitialCondition(3);


    int j1 = find_index(x1);
    int j2 = find_index(x2);


    double c = 0;
    for (auto i = j1 + 1; i <= j2; i++) {
        c = 2 / b * (c1 - 0.5 * a * nodes[i] / T_max);
        ExactDensity[i] = pow(c * c / adiabata * pow(density_left, adiabata) / pressure_left, 1 / a);
        ExcactVelocity[i] = (2.0 / b) * (c1 + nodes[i] / T_max);
        ExcactPressure[i] = c * c * ExactDensity[i] / adiabata;
    }
    j1 = find_index(x3);
    for (auto i = j2 + 1; i <= j1; i++) {
        ExactDensity[i] = density_3a;
        ExcactVelocity[i] = velocity3;
        ExcactPressure[i] = pressure3;
    }
    j2 = find_index(x4);
    for (auto i = j1 + 1; i <= j2; i++) {
        ExactDensity[i] = density3;
        ExcactVelocity[i] = velocity3;
        ExcactPressure[i] = pressure3;
    }
    if (parameter == 1) return ExactDensity;
    else if (parameter == 2) return ExcactVelocity;
    else return ExcactPressure;
}
