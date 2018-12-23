//
// Created by sofia on 23.12.18.
//

#include <iostream>
#include "BitWriter.h"

void BitWriter::WriteBit(bool b) {
//    int32_t i = 0;
    ++index;
    currentByte << 1u;
    currentByte = currentByte| b;
    std::cout<<currentByte<<" ";

    if (index % 8 == 0) {
        bytes.push_back(currentByte);
        currentByte = 0;
    }
//    return 0;
}

std::vector<char> BitWriter::getBytes() {
    if (index % 8 != 0) {
        int32_t difference = 8 - index % 8;
        currentByte = currentByte << unsigned(difference);
        extraBits = difference;
        std::cout<<"Difference= "<<difference;
        bytes.push_back(currentByte);
    }
    std::cout<<"Byte= "<<currentByte;

    return bytes;
}
