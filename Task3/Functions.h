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


template<typename argument>
constexpr argument my_function(argument x) {
    return x * x * x * x; // + 3 * (1 + x * x / 2 + x * x * x * x / 24);
}


template<int N, int L, class T>
constexpr auto sum(std::array<T, N> a) {
    if constexpr (L == N) {
        return 0;
    } else {
        return std::get<L>(a) + sum<N, L + 1>(a);
    }
}


template<int32_t N, int L, class T>
constexpr auto Make_coeffs(std::array<T, N> a) {
    if constexpr (L == N) {
        return a;
    } else {
        if constexpr (L != 0 && L != N - 1) {
            if constexpr (L % 2 == 0) {
                std::get<L>(a) *= 2 * (double(rightNode - leftNode) / (3 * N));

            } else {
                std::get<L>(a) *= 4 * (double(rightNode - leftNode) / (3 * N));

            }
        } else {
            std::get<L>(a) = std::get<L>(a) * (double(rightNode - leftNode) / (3 * N));

        }
        return Make_coeffs<N, L + 1>(a);

    }
}


constexpr auto f = my_function<double>;

template<int32_t N>
constexpr auto IntegrateSimpson() {
    constexpr auto a = make_array<N>(f);
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
    constexpr auto coeffs = Make_coeffs<N, 0>(a);
    std::copy(std::begin(coeffs), std::end(coeffs), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
    return sum<N, 0>(coeffs);
}


#endif //TASK3_FUNCTIONS_H
