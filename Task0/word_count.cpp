#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "Words_reader.h"
#include "Frequency_counter.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");

    if (argc != 3) {
        std::cout << "No input and output files. Please, enter, or the program won't work!";
        return -1;
    }
    std::string input = argv[1];
    std::string output = argv[2];
    Words_finder(input, output);
    return 0;
}