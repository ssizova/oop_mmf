#ifndef FUNCTIONMAKER_H
#define FUNCTIONMAKER_H

#include <vector>

class FunctionMaker
{
    std::vector<double> coefficients;
    double left = -1;
    double right = 1;


public:
    FunctionMaker(double A, double B, double C, std::size_t number_of_points);
    std::vector<double> function_points;
    std::vector<double> nodes;
    std::vector<double> MakeNodes(std::size_t N);
    std::vector<double> CalcFunction(std::vector<double> x, std::vector<double> coeffs);

};

#endif // FUNCTIONMAKER_H
