#ifndef INPUTOPERATOR_H
#define INPUTOPERATOR_H
//

//#include <xutility>
#include <vector>
#include <memory>
#include <istream>
#include <fstream>
#include "TupleLibrary.h"
//
// Created by Sizova on 18.03.2019.
//

#include <iostream>


using iterator_category = std::input_iterator_tag;

template<typename ... Args>
class InputIterator {
    std::ifstream *file;
public:
    bool isEnd = false;
    bool lastElement = false;
    std::tuple<Args...> lines;
    int32_t index = 0;
    char separator = ',';
    char screnning = '"';


    InputIterator(std::ifstream *input, bool isEnd, char separator, char scr) {
        file = input;
        this->isEnd = isEnd;
        this->separator = separator;
        this->screnning = scr;
    }


    InputIterator &operator=(const InputIterator &rhs) {
        return (*this);
    }

    bool operator==(InputIterator rhs) {
//        std::cout << "==";
        return (rhs.isEnd == this->isEnd);
    }

    InputIterator operator++() {
        if (!lastElement) {
            lines = parse<Args...>(file,separator);
            index++;
//            std::cout << index;
//            std::cout << "++ ";
            lastElement = file->eof();
        } else {
            isEnd = file->eof();
        }

        return (*this);
    }


    bool operator!=(InputIterator rhs) {
        return rhs.isEnd != this->isEnd;
//    !rhs.isEnd;
    }

    auto operator*() {
        return lines;
    }
};

#endif //INPUTOPERATOR_H
