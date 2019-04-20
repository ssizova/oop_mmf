//
// Created by Sizov on 09.04.2019.
//

#ifndef TASK5_TUPLELIBRARY_H
#define TASK5_TUPLELIBRARY_H

#include <tuple>

template<class TupleType, int current, int size>
struct tuple_printer {
    static void print(const TupleType &tuple) {
        std::cout << std::get<current>(tuple) << ' ';
        tuple_printer<TupleType, current + 1, size>::print(tuple);
    }
};

template<class TupleType, int size>
struct tuple_printer<TupleType, size, size> {
    static void print(const TupleType &tuple) {
        std::cout << std::get<size>(tuple) << std::endl;
    }
};

template<class... Args>
void print_tuple(const std::tuple<Args...> &tuple) {
    tuple_printer<std::tuple<Args...>, 0, sizeof...(Args) - 1>::print(tuple);
}

template<typename T>
std::tuple<T> parse(std::istream *is) {
    T t;
    (*is) >> t;
//    try {
    if (is->fail()) {
        throw std::exception("Invalid format of input data!");
    }
    return std::tuple<T>(std::move(t));
}

template<typename T, typename Arg,  typename... Args>
std::tuple<T, Arg,  Args...> parse(std::istream *is) {
    T t;
    (*is) >> t;
//    if
    return std::tuple_cat(std::tuple<T>(std::move(t)),
//                          parse<Arg, Sep, Args...>(is));
    parse<Arg,  Args...>(is));

}

#endif //TASK5_TUPLELIBRARY_H
