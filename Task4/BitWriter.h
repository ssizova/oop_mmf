//
// Created by sofia on 23.12.18.
//

#ifndef TASK4_BITWRITER_H
#define TASK4_BITWRITER_H


#include <cstdint>
#include <vector>

class BitWriter {
    std::vector<char> bytes;
    unsigned char currentByte = 0;
    int32_t index = 0;
    int32_t extraBits = 0;
public:
    void WriteBit(bool b);
    std::vector<char> getBytes();




};



#endif //TASK4_BITWRITER_H
