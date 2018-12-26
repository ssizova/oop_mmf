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

int main(int argc, char *argv[]) {

    if (argc != 4) {
        std::cout << "No input and output files. Please, enter, or the program won't work!";
        return -1;
    }
    std::string flag = argv[1];
    std::string input = argv[2];
    std::string output = argv[3];

    if (flag == "-c") {
        auto x = Encoder(input, output);
    } else if (flag == "-d") {
        auto decoder = Decoder(output, input);
    } else {
        std::cout << "Your flag is not for compression or decompression";
    }


    return 0;
}

