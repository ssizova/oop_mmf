//
// Created by Sizova on 17.12.2018.
//

#include <iostream>
#include <ostream>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <map>
#include <algorithm>

struct Element {
    int32_t byte;
    int32_t quantity;
    Element() {
        byte = 0;
        quantity = 0;
    }
};


std::vector<Element> Sorting(std::vector<Element> bytes) {
    std::vector<Element> sorted_vector;
    Element object;
    int32_t i = 0;

    for (auto &kv : bytes) {
        object.byte = kv.byte;
        object.quantity = kv.quantity;
        ++i;
        sorted_vector.push_back(object);
    }
    std::sort(sorted_vector.begin(), sorted_vector.end(),
              [](Element d1, Element d2) { return d1.quantity < d2.quantity;});
    return sorted_vector;
}

std::vector<Element> ReadingBytes(const std::string &path) {
    std::ifstream f(path);

    std::vector<int32_t> weights(256, 0);
    while (!f.eof()) {
        unsigned char symbol;
        f.read((char *) &symbol, sizeof(symbol));
        std::cout << symbol << " ";
        ++weights[symbol];

    }
    std::cout << "efeeef"<<std::endl;

    std::vector<Element> nonzero_weights;
    for (auto i = 0; i < 256; ++i) {
        if (weights[i] != 0) {
            Element buffer;
            buffer.byte = i;
            buffer.quantity = weights[i];
            nonzero_weights.push_back(buffer);
        }
    }

    return Sorting(nonzero_weights);
}

int main() {
    std::string path = "input.txt";
    auto v = ReadingBytes(path);
    for (auto i: v)
        std::cout << i.quantity << " ";

}