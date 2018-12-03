#include <memory>
#include <iostream>
#include <bits/unique_ptr.h>
#include <strings.h>

constexpr int32_t leftNode = -1;
constexpr int32_t rightNode = 1;

template<int32_t N, class Function, std::size_t... Indices>
constexpr auto make_array_helper(Function f, std::index_sequence<Indices...>)
-> std::array<typename std::result_of<Function(std::size_t)>::type, sizeof...(Indices)> {

    constexpr double h = double(rightNode - leftNode) / (2*N );
    return {{ f(leftNode + h * Indices)...}};

}


template<int32_t N, class Function>
constexpr auto make_array(Function f)
-> std::array<typename std::result_of<Function(std::size_t)>::type, N> {
    return make_array_helper<N>(f, std::make_index_sequence<N>{});
}
