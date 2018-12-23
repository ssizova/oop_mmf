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

std::vector<std::shared_ptr<Element>> MakeTestVector() {
    std::vector<std::shared_ptr<Element> > v;
    std::shared_ptr<Element> first(new Element);
    std::shared_ptr<Element> second(new Element);
    std::shared_ptr<Element> third(new Element);
    first->quantity = 2;
    second->quantity = 3;
    third->quantity = 1;

    third->byte = 'a';
    second->byte = 'c';
    first->byte = 'b';

    v.push_back(first);
    v.push_back(second);
    v.push_back(third);
    return v;

}


TEST (ReadingBytes, ReadingFromFile) {
//    std::string path = "input.txt";
    auto bytes = ReadingBytes("input.txt");
    std::vector<char> symbols;
    std::vector<int32_t> quantites;


    for (const auto &i:bytes) {
        symbols.push_back(i->byte);
        quantites.push_back(i->quantity);
    }
    EXPECT_THAT(symbols, ::testing::ElementsAre('a', 'b', 'c'));
    EXPECT_THAT(quantites, ::testing::ElementsAre(2, 3, 1));

}


TEST (MakeNode, from2nodes) {
    std::shared_ptr<Element> first(new Element);
    std::shared_ptr<Element> second(new Element);
    first->quantity = 1;
    second->quantity = 10;
    auto e = MakeNode(first, second);
    EXPECT_EQ(e->quantity, 11);
    EXPECT_EQ(e->isLeaf, false);
}

TEST (MakeQueue, priorityQueue) {
    auto v = MakeTestVector();
    auto queue = MakeQueue(v);
    for (auto i = 0; i < 3; ++i) {
        auto j = queue.top();
        EXPECT_THAT(j->quantity, i + 1);
        queue.pop();
    }
}

TEST (MakeTree, BytesAndQuantities) {
    auto v = MakeTestVector();
    auto tree = MakeTree(v);
    EXPECT_THAT(tree->isLeaf,false);
    EXPECT_THAT(tree->quantity,6);
    auto leftSon = tree->left;
    auto rightSon = tree->right;
    EXPECT_THAT(rightSon->isLeaf,false);
    EXPECT_THAT(rightSon->quantity,3);

    EXPECT_THAT(leftSon->isLeaf,true);
    EXPECT_THAT(leftSon->byte,'c');
    EXPECT_THAT(leftSon->quantity,3);

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
