//
// Created by Sizova on 18.03.2019.
//

#ifndef INPUTOPERATOR_H
#define INPUTOPERATOR_H


#include <xutility>
#include <vector>
#include <memory>

class InputIterator {

    using iterator_category = std::input_iterator_tag;
//    std::vector<int> inner_array = {3, 2, 1, 5, 4};
    int32_t index = 0;
    std::shared_ptr<char> pointer;

    explicit InputIterator(int32_t i);

    InputIterator operator=(const InputIterator &rhs);

    InputIterator &operator++();

    const InputIterator operator++(int);

    int &operator*();

    bool operator==(InputIterator rhs);

    bool operator!=(InputIterator rhs);
};


#endif //INPUTOPERATOR_H
