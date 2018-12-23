//
// Created by sofia on 23.12.18.
//

#include <gtest/gtest.h>
#include "../TreeforBytes.h"
#include "../Haffman_algorithm.h"
#include "../Encoder.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <map>
#include <algorithm>

#include <gmock/gmock.h>
//WillRepeatedly::testing::ElementsAre
using ::testing::_;
using ::testing::Invoke;

TEST (ReadingBytes, ReadingFromFile) {
//    std::string path = "input.txt";
    auto v = ReadingBytes("input.txt");
    std::vector<char> symbols;
    std::vector<int32_t> quantites;


    for (const auto &i:v) {
        symbols.push_back(i->byte);
        quantites.push_back(i->quantity);
    }
    EXPECT_THAT(symbols, ::testing::ElementsAre('a', 'b', 'c'));
    EXPECT_THAT(quantites, ::testing::ElementsAre(2, 1, 3));


}

//TEST(MyClassForTesting, opensExistingFile){
//obj1._fileName = "existingFile.csv";
//EXPECT_TRUE(obj1.readMyDataFromFile(obj1._fileName));
//}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
