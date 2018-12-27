//
// Created by sofia on 24.12.18.
//

#ifndef TASK4_DECODER_H
#define TASK4_DECODER_H


#include <cstdint>
#include "TreeforBytes.h"

class Decoder {
    int32_t extraBites = 0;
    TreeforBytes tree;
    std::vector<unsigned char> codedData;
    std::string realData;
public:
    Decoder(std::string archive, std::string decodedFile);

    TreeforBytes RestoreTree(std::vector<unsigned char> line);

    int IsInMap(std::map<char, std::vector<bool>>, std::vector<bool> key, char *out);

    std::string Decode(std::string codedData, const std::map<char, std::vector<bool>> &table);
};


#endif //TASK4_DECODER_H
