
#ifndef TASK4_HAFFMAN_ALGORITHM_H
#define TASK4_HAFFMAN_ALGORITHM_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <memory>
struct Element {
    unsigned char byte;
    int32_t quantity;
    std::shared_ptr<Element> left;
    std::shared_ptr<Element> right;
    bool isLeaf;

    Element() {
        byte = 0;
        quantity = 0;
        left = nullptr;
        right = nullptr;
        isLeaf = true;
    }

    bool operator<(const Element &rhs) const {
        return quantity < rhs.quantity;
    }

};

class ElementComparator {
public:
    bool operator()(const std::shared_ptr<Element> &first, const std::shared_ptr<Element> &second) {
        return first->quantity > second->quantity;
    }
};

std::priority_queue<std::shared_ptr<Element> , std::vector<std::shared_ptr<Element> >, ElementComparator>
MakeQueue(const std::vector<std::shared_ptr<Element> > &vector);


std::vector<std::shared_ptr<Element> > ReadingBytes(const std::string &path);


std::shared_ptr<Element> MakeNode(std::shared_ptr<Element> first, std::shared_ptr<Element> second);


std::shared_ptr<Element>  MakeTree(const std::vector<std::shared_ptr<Element> > &array);
void printMap(std::map<char, std::vector<bool>> table);


#endif //TASK4_HAFFMAN_ALGORITHM_H
