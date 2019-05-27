#include "functionmaker.h"
#include <iostream>

std::vector<double> MakeNodes(int N, double left, double right) {
    std::vector<double> x(N + 1, left);
    double h = (right - left) / N;
    for (auto i = 1; i <= N; ++i) {
        x[i] += i * h;
    }
    return x;
}

std::vector<double> CalcFunction(std::vector<double> x, std::vector<double> coeffs) {
    std::vector<double> y(x.size());
    for (auto i = 0; i < x.size(); ++i) {
        y[i] = coeffs[0] * x[i] * x[i] + coeffs[1] * x[i] + coeffs[2];

    }
    return y;
}

FunctionMaker::FunctionMaker(double A, double B, double C) {
    nodes = MakeNodes(number_of_points, -1, 1);
    coefficients = {A, B, C};
    function_points = CalcFunction(nodes, coefficients);
}
