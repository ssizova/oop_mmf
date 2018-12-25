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
#include "Decoder.h"

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
    auto x = Encoder("input.txt", "out.txt");
    Decoder("out.txt","new.txt");
//    auto y = Encoder("barash.bmp","out2.bmp");
//    Decoder("out2.bmp", "newbarash.bmp");

//    auto z = Encoder("wilde_picture_of_dorian_gray_txt.txt", "out3.txt");
//    Decoder("out3.txt", "new_wilde.txt");


    return 0;
}

