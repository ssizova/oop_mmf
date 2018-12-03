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

constexpr int32_t leftNode = -5;
constexpr int32_t rightNode = 5;


template<typename argument>
constexpr argument my_function(argument x) {
    return x * x + 3 * (1 + x * x / 2 + x * x * x * x / 24);
}


template<typename Function>
constexpr double Integrate(Function my_function) {
    return (rightNode - leftNode) / 6.0 * (my_function(leftNode) + 4 * my_function((leftNode + rightNode) / 2.0) +
                                           my_function(rightNode));
}

template<int N, int L, class T>
constexpr auto sum(std::array<T, N> a) {
    constexpr double_t h = double(rightNode-leftNode)/(2*N);
    if constexpr (L == N - 1) {
        return 0;
    } else {
        return std::get<L>(a) + sum<N, L + 1>(a);
    }
}

constexpr auto f = my_function<double>;

template<int32_t N>
constexpr auto IntegrateSimpson() {
    constexpr auto a = make_array<N>(f);
    constexpr auto s = sum<N, 0>(a);
    return s;
}


#endif //TASK3_FUNCTIONS_H
