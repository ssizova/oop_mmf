#ifndef FUNCTIONMAKER_H
#define FUNCTIONMAKER_H

#include <vector>
class FunctionMaker
{
    std::vector<double> nodes;
    int number_of_points = 2;
    std::vector<double> coefficients;


public:
    FunctionMaker(double A, double B, double C);
    std::vector<double> function_points;
};

#endif // FUNCTIONMAKER_H
