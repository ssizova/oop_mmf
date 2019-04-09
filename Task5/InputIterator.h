#ifndef INPUTOPERATOR_H
#define INPUTOPERATOR_H
//

#include <xutility>
#include <vector>
#include <memory>
#include <istream>
#include <fstream>
//
// Created by Sizova on 18.03.2019.
//

#include <iostream>


using iterator_category = std::input_iterator_tag;

template<typename ... Args>
class InputIterator {
    bool isEnd = false;
    std::ifstream *file;
public:
    std::tuple<Args...> lines;
    int32_t index = 0;


    InputIterator(std::ifstream *input, bool isEnd) {
        file = input;
        this->isEnd = isEnd;
//        lines = std::make_tuple<Args...>;
    }


    InputIterator &operator=(const InputIterator &rhs) {
        return (*this);
    }

    bool operator==(InputIterator rhs) {
        std::cout << "==";
        return (rhs.isEnd == this->isEnd);
    }

    InputIterator operator++() {
//    getline(*file,line);
//    lines = std::make_tuple(line);
        lines = parse<Args...>(file);

        index++;
        std::cout << "++ ";
        isEnd = file->eof();
        return (*this);
//        return (*std::next(this));

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
