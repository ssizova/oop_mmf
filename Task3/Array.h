#ifndef TASK3_ARRAY_H
#define TASK3_ARRAY_H

#include <memory>
#include <iostream>
#include <bits/unique_ptr.h>
#include <strings.h>

constexpr int32_t leftNode = -1;
constexpr int32_t rightNode = 1;

template<int32_t N, class Function, std::size_t... Indices>
constexpr auto MakeArrayHelper(Function f, std::index_sequence<Indices...>)
-> std::array<typename std::result_of<Function(std::size_t)>::type, sizeof...(Indices)> {

    constexpr double h = double(rightNode - leftNode) / (N-1);
    return {{ f(leftNode + h * Indices)...}};

}


template<int32_t N, class Function>
constexpr auto MakeArray(Function f)
-> std::array<typename std::result_of<Function(std::size_t)>::type, N> {
    return MakeArrayHelper<N>(f, std::make_index_sequence<N>{});
}

#endif //TASK3_ARRAY_H
