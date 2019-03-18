//
// Created by Sizova on 18.03.2019.
//

#include "InputIterator.h"


InputIterator::InputIterator(int32_t i) {
    index = i;
}

 InputIterator InputIterator::operator=(const InputIterator &rhs) {
    return (*this);
}

InputIterator &InputIterator::operator++() {
}


const InputIterator InputIterator::operator++(int) {

}

bool InputIterator::operator==(InputIterator rhs) {
    return this->index == rhs.index;
}

int &InputIterator::operator*() {

}

bool InputIterator::operator!=(InputIterator rhs) {
    return !(rhs == *this);
}
