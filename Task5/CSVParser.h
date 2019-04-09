//
// Created by Sizova on 10.03.2019.
//

//отношение - агрегация (либо френд либо вложенный класс)
#ifndef CSVPARSER_H
#define CSVPARSER_H


#include <string>
#include <vector>
#include "InputIterator.h"

//template<typename T>
//std::tuple<T> readLine(std::ifstream &is) {
//    T t;
//    is >> t;
//    return std::tuple<T>(std::move(t));
//}
//
//template<typename T, typename ... Args>
//std::tuple<Args...> readLine(std::ifstream &is) {
//    T t;
//    is >> t;
//    return std::tuple_cat(std::tuple<T>(std::move(t)),
//                           parse<Args...>(is));
//}

template<typename... Arguments>
class CSVParser {
public:
    std::ifstream *file;
    int32_t skipped_lines = 0;

    InputIterator<Arguments...> begin() {
        return InputIterator<Arguments...>(file, false);
    }

    InputIterator<Arguments...> end() {
//        return iterator(file, true);
        return InputIterator<Arguments...>(file, true);

    }


    CSVParser(std::ifstream *input_file, int skipped_line) {
        file = input_file;
        skipped_lines = skipped_line;
//        std::cout<<(skipped_lines);

    }
};
//    template<typename... Arguments>
//    CSVParser<Arguments...>::CSVParser() {
//
//    }

#endif CSVPARSER_H
