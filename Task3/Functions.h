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
constexpr argument MyFunction(argument x) {
    return x* x * x * x;
}


template<int N, int L, class T>
constexpr auto Sum(std::array<T, N> a) {
    if constexpr (L == N) {
        return 0;
    } else {
        return std::get<L>(a) + Sum<N, L + 1>(a);
    }
}


template<int32_t N, int L, class T>
constexpr auto MakeCoeffs(std::array<T, N> a) {
    if constexpr (L == N) {
        return a;
    } else {
        constexpr double h = double(rightNode - leftNode) / (N-1);
        if constexpr (L != 0 && L != N - 1) {
            if constexpr (L % 2 == 0) {
                std::get<L>(a) *= (2 * h/3);

            } else {
                std::get<L>(a) *=( 4 * h/3);

            }
        } else {
            std::get<L>(a) *=( h/3);

        }
        return MakeCoeffs<N, L + 1>(a);

    }
}


constexpr auto f = MyFunction<double>;

template<int32_t N>
constexpr auto IntegrateSimpson() {
    constexpr auto a = MakeArray<N>(f);
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
    constexpr auto coeffs = MakeCoeffs<N, 0>(a);
    std::copy(std::begin(coeffs), std::end(coeffs), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;
    return Sum<N, 0>(coeffs);
}


#endif //TASK3_FUNCTIONS_H
