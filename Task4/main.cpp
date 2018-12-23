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
#include "Haffman_algorithm.h"
#include "TreeforBytes.h"
#include "Encoder.h"

int main() {
    std::string path = "input.txt";
    auto v = ReadingBytes(path);
    for (const auto &i: v)
        std::cout << i->byte << ":" << i->quantity << " ";
    std::cout << std::endl;

    TreeforBytes Tree = TreeforBytes(v);


    Tree.printTree();
    auto table = Tree.Coding();
    printMap(table);
//    Tree.PrintTreeToFile("output.txt");
    auto x = Encoder("input.txt", "outtt.txt");
    return 0;
}

