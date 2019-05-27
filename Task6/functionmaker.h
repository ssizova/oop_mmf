#ifndef FUNCTIONMAKER_H
#define FUNCTIONMAKER_H

#include <vector>
class FunctionMaker
{

    int number_of_points = 100;
    std::vector<double> coefficients;


public:
    FunctionMaker(double A, double B, double C);
    std::vector<double> function_points;
    std::vector<double> nodes;
};

#endif // FUNCTIONMAKER_H
