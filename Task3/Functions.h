//
// Created by sofia on 24.11.18.
//

#ifndef TASK3_FUNCTIONS_H
#define TASK3_FUNCTIONS_H

#include <iostream>
#include <cstdint>
#include <memory>
#include <strings.h>
#include <numeric>
#include "Array.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <valarray>

int32_t leftNode = -5;
int32_t rightNode = 5;

template<typename argument>
constexpr argument my_function(argument x) {
    return x * x + 3 * (1 + x * x / 2 + x * x * x * x / 24);
}



template<typename Function>
constexpr double Integrate(Function my_function) {
    return (rightNode - leftNode) / 6.0 * (my_function(leftNode) + 4 * my_function((leftNode + rightNode) / 2.0) +
                                           my_function(rightNode));
}

#endif //TASK3_FUNCTIONS_H
