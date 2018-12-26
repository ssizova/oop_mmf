//
// Created by sofia on 23.12.18.
//

#include <iostream>
#include <bitset>
#include "BitWriter.h"

void BitWriter::WriteBit(bool b) {
    ++index;
    currentByte <<= 1;
    currentByte = currentByte | b;

    if (index % 8 == 0) {
        bytes.push_back(currentByte);
        currentByte = 0;
    }
}

std::vector<char> BitWriter::getBytes() {
    if (index % 8 != 0) {
        int32_t difference = 8 - index % 8;
        currentByte = currentByte << unsigned(difference);
        extraBits = difference;
        bytes.push_back(currentByte);
    }

    return bytes;
}
