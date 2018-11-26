//
// Created by sofia on 19.11.18.
//
#include <memory>
#include <iostream>
#include <bits/unique_ptr.h>
#include <strings.h>

//template<int32_t N, class Function, std::size_t... Indices>
//constexpr auto make_array_helper(Function f)
////-> std::array<typename std::result_of<Function(std::size_t)>::type, sizeof...(Indices)>
//{
//    int32_t leftNode = -5;
//    int32_t rightNode = 5;
//    auto h = double(rightNode - leftNode) / (N);
//    auto sum = 0.0;
//    //auto func = f(leftNode + h*Indices)...
//    for (auto i = 1; i < N ; ++i) {
//        sum += (h * f(leftNode + h * i));
//        std::cout << (leftNode + h * i) << " " << f(leftNode + h * i)
//                  << std::endl;//<< " "<< f(leftNode + h*i)< " " << std::endl;
//    }
//    sum += h * 0.5 * (f(leftNode) + f(rightNode));
//    return sum;
//}
template<int32_t N, class Function, std::size_t... Indices>
constexpr auto make_array_helper(Function f, std::index_sequence<Indices...>)
-> std::array<typename std::result_of<Function(std::size_t)>::type, sizeof...(Indices)> {
    int32_t leftNode = -5;
    int32_t rightNode = 5;
    auto h = double(rightNode - leftNode) / (N - 1);
    return {{f(leftNode + h * Indices)...}};
}

template<int32_t N, class Function>
constexpr auto make_array(Function f)
-> std::array<typename std::result_of<Function(std::size_t)>::type, N> {
    return make_array_helper<N>(f, std::make_index_sequence<N>{});
}





//constexpr auto Summa(std::array<double, N> a) {


//template<int32_t N, class Function>


template<int32_t N>
struct Sum {

    static constexpr double value = Sum<N-1>::value;
            //f[leftNode + N * h] + Sum < N - 1 > ::value;
};

template<>
struct Sum<0> {
    static constexpr double value = 0;//f[leftNode];
};



template<int32_t N, class Function>
constexpr auto IntegrateSimpson(Function f) {
    int32_t leftNode = -5;
    int32_t rightNode = 5;
    auto a = make_array<N>(f);
    auto sum = Sum<N>::value;
    //    auto h = double(rightNode - leftNode) / (2 * N);
//    auto sum = 0.0;
//    for (auto i = 1; i < 2 * N; ++i) {
//        if (i % 2 == 0) {
//            sum += (2 * h / 3 * f(leftNode + h * i));
//        } else {
//            sum += (4 * h / 3 * f(leftNode + h * i));
//        }
//        std::cout << (leftNode + h * i) << " " << f(leftNode + h * i)
//                  << std::endl;
//    }
//    sum += h / 3 * (f(leftNode) + f(rightNode));
    return sum;
}


//template<int32_t N, class Function>
//constexpr auto make_array(Function f)
////-> std::array<typename std::result_of<Function(std::size_t)>::type, N>
//{
//    return make_array_helper<N>(f, std::make_index_sequence<N>{});
//}


//
//working code
