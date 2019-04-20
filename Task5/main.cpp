//
// Created by Sizova on 10.03.2019.
//

#include <iostream>
#include <fstream>
#include "CSVParser.h"
#include "TupleLibrary.h"


int main() {
    std::ifstream file("new1.csv");
    std::string input = "new1.csv";
    std::string line;
    auto sep = ',';
    std::string scr = "quotes";
    CSVParser<int, std::string> parser(&file, 0, sep, scr);
    try {
        for (auto i = parser.begin(); i != parser.end(); ++i) {
            print_tuple(*i);
        }
    }

    catch (std::exception &error) {
        std::cout << error.what();
    }

}


