//
// Created by Sizova on 10.03.2019.
//

//отношение - агрегация (либо френд либо вложенный класс)
#ifndef CSVPARSER_H
#define CSVPARSER_H


#include <string>
#include <vector>
#include "InputIterator.h"


template<typename... Arguments>
class CSVParser {
public:
    std::ifstream *file;
    int32_t skipped_lines = 0;
    char separator = ',';
    std::string screening = "quotes";

    InputIterator<Arguments...> begin() {
        auto i = InputIterator<Arguments...>(file, false,separator,screening);
        for (int32_t j = 0; j <= skipped_lines; ++j) {
            std::cout << j;
            if (i.isEnd) {
//                std::cout << ("eecefefcf");
                return InputIterator<Arguments...>(file, true,separator,screening);
            }
            ++i;

        }
        return i;
    }

    InputIterator<Arguments...> end() {
//        return iterator(file, true);
        return InputIterator<Arguments...>(file, true, separator, screening);

    }


    CSVParser(std::ifstream *input_file, int skipped_line, char separator, std::string screening) {
        file = input_file;
        skipped_lines = skipped_line;
        separator = separator;
        screening = screening;
//        std::cout<<(skipped_lines);

    }
};
//    template<typename... Arguments>
//    CSVParser<Arguments...>::CSVParser() {
//
//    }

#endif CSVPARSER_H
