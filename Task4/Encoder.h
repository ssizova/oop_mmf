//
// Created by sofia on 23.12.18.
//

#ifndef TASK4_ENCODER_H
#define TASK4_ENCODER_H


#include <string>
#include <vector>
#include <map>

class Encoder {
//    bool flag = 0; //0 for coding
std::map<char,std::vector<bool >> table;

public:
    explicit Encoder(std::string input, std::string output);


};


#endif //TASK4_ENCODER_H
