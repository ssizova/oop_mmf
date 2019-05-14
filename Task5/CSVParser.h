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
    char separator = ':';
    char screening = '"';


    CSVParser(std::ifstream *input_file, int skipped_line, char separator, char screening) {
        file = input_file;
        skipped_lines = skipped_line;
        this->separator = separator;
        this->screening = screening;

    }

    InputIterator<Arguments...> begin() {
        auto i = InputIterator<Arguments...>(file, false, separator, screening);
        for (int32_t j = 0; j <= skipped_lines; ++j) {
            if (i.isEnd) {
                return InputIterator<Arguments...>(file, true, separator, screening);
            }
            ++i;

        }
        return i;
    }

    InputIterator<Arguments...> end() {
        return InputIterator<Arguments...>(file, true, separator, screening);

    }


};


#endif //CSVPARSER_H
