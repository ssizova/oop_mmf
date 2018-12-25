//
// Created by sofia on 23.12.18.
//

#include <iostream>
#include <bitset>
#include "BitWriter.h"

void BitWriter::WriteBit(bool b) {
//    int32_t i = 0;
    ++index;
//    std::cout << "Bit=" << b << std::endl;
    currentByte <<= 1;
    currentByte = currentByte | b;
//    std::cout << std::bitset<8>(currentByte) << " currentByte" << std::endl;

    if (index % 8 == 0) {
        bytes.push_back(currentByte);
        std::cout <<"bByte = "<<std::bitset<8>(currentByte)<<std::endl;
        currentByte = 0;
    }
//    return 0;
}

std::vector<char> BitWriter::getBytes() {
//    std::cout << "index=" << index << std::endl;
    if (index % 8 != 0) {
        int32_t difference = 8 - index % 8;
        currentByte = currentByte << unsigned(difference);
        extraBits = difference;
        std::cout << "Difference= " << difference<<std::endl;
        std::cout <<"Bbyte = "<<std::bitset<8>(currentByte)<<std::endl;
        bytes.push_back(currentByte);
    }
//    std::cout << "Byte=" << std::bitset<8>(currentByte);

    return bytes;
}
