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
//    char c = file.get();
//
//    while (file.good()) {
//        std::cout << c;
//        c = file.get();
//    }
    std::string line;
    CSVParser<int, std::string> parser(&file, 0);

    for (auto i = parser.begin(); i != parser.end(); ++i) {
//        getline(file, line);
        print_tuple(*i);
//        std::cout << i.lines[0] << std::endl;

    }
//    for (std::tuple<int, std::string> rs : parser) {
//        std::cout << rs << std::endl;
//    }
}

