//
// Created by Sizov on 09.04.2019.
//

#ifndef TASK5_TUPLELIBRARY_H
#define TASK5_TUPLELIBRARY_H

#include <tuple>
#include <sstream>
#include <iostream>
//#include "InputIterator.h"

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
std::tuple<T> parse(std::istream *is, char separator, int line_number) {
    T t;

    (*is) >> t;
    if (is->fail()) {
        std::string exception = "Invalid format of input data! The error is at string number "
                                + std::to_string(line_number + 1);
        throw std::runtime_error(exception);
    }
    return std::tuple<T>(std::move(t));
}

template<typename T, typename Arg, typename... Args>
std::tuple<T, Arg, Args...> parse(std::istream *is, char separator, int line_number) {
    T t;
    std::string s;
    std::getline(*is, s, separator);
    std::istringstream temp(s);
    std::cout<<"S:  "<<s<<"Send  "<<std::endl;
    temp >> t;

    if (temp.fail()) {
        std::string exception = "Invalid format of input data! The error is at string number second"
                                + std::to_string(line_number + 1);
        throw std::runtime_error(exception);
    }


    return std::tuple_cat(std::tuple<T>(std::move(t)),
                          parse<Arg, Args...>(is, separator, line_number));

}

#endif //TASK5_TUPLELIBRARY_H
