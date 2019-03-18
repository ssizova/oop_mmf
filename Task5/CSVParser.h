//
// Created by Sizova on 10.03.2019.
//

#ifndef CSVPARSER_H
#define CSVPARSER_H


#include <string>
#include <vector>
#include "InputIterator.h"

template<typename T>
std::tuple<T> readLine(std::istream &is) {
    T t;
    is >> t;
    return std::tuple<T>(std::move(t));
}

template<typename T, typename Arg1, typename ... Args>
std::tuple<Args...> readLine(std::istream &is) {
    T t;
    is >> t;
    return std::tuple_cat(std::tuple<T>(std::move(t)),
                          parse<Arg1, Args...>(is));
}

template<typename... Arguments>
class CSVParser {


    CSVParser();
    InputIterator begin(){

    }
    InputIterator end(){

    }
    CSVParser parser(std::string filename, int skippedSymbols);
};

template<typename... Arguments>
CSVParser<Arguments...>::CSVParser() {

}


#endif //VARIADIC_TEMPLATES_CSVPARSER_H
