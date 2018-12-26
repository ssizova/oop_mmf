//
// Created by sofia on 23.12.18.
//

#include <gtest/gtest.h>
#include "../TreeforBytes.h"
#include "../Haffman_algorithm.h"
#include "../Encoder.h"
#include "../BitWriter.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdint-gcc.h>
#include <vector>
#include <map>
#include <algorithm>
#include <gmock/gmock.h>

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

TreeforBytes *MakeTestTree() {
    std::shared_ptr<Element> root(new Element);
    root->quantity = 6;
    root->isLeaf = false;

    std::shared_ptr<Element> leftSon(new Element);
    leftSon->quantity = 3;
    leftSon->isLeaf = false;
    root->left = leftSon;

    std::shared_ptr<Element> rightSon(new Element);
    rightSon->quantity = 3;
    rightSon->byte = 'c';
    root->right = rightSon;

    std::shared_ptr<Element> leftLeftSon(new Element);
    leftLeftSon->quantity = 1;
    leftLeftSon->byte = 'a';
    leftSon->left = leftLeftSon;

    std::shared_ptr<Element> leftRightSon(new Element);
    leftRightSon->quantity = 2;
    leftRightSon->byte = 'b';
    leftSon->right = leftRightSon;
    TreeforBytes *TestingTree = new TreeforBytes(root);
    return TestingTree;
}


TEST (Huffman_algorithm, ReadingBytes) {
//    std::string path = "input.txt";
    auto bytes = ReadingBytes("example.txt");
    std::vector<char> symbols;
    std::vector<int32_t> quantites;


    for (const auto &i:bytes) {
        symbols.push_back(i->byte);
        quantites.push_back(i->quantity);
    }
    EXPECT_THAT(symbols, ::testing::ElementsAre('a', 'b', 'c'));
    EXPECT_THAT(quantites, ::testing::ElementsAre(2, 1, 3));

}


TEST (Huffman_algorithm, MakeNode) {
    std::shared_ptr<Element> first(new Element);
    std::shared_ptr<Element> second(new Element);
    first->quantity = 1;
    second->quantity = 10;
    auto e = MakeNode(first, second);
    EXPECT_EQ(e->quantity, 11);
    EXPECT_EQ(e->isLeaf, false);
}

TEST (Huffman_algorithm, MakeQueue) {
    auto v = MakeTestVector();
    auto queue = MakeQueue(v);
    for (auto i = 0; i < 3; ++i) {
        auto j = queue.top();
        EXPECT_THAT(j->quantity, i + 1);
        queue.pop();
    }
}

TEST (Huffman_algorithm, MakeTree) {
    auto v = MakeTestVector();
    auto tree = MakeTree(v);
    EXPECT_THAT(tree->isLeaf, false);
    EXPECT_THAT(tree->quantity, 6);
    auto leftSon = tree->left;
    auto rightSon = tree->right;
    EXPECT_THAT(rightSon->isLeaf, false);
    EXPECT_THAT(rightSon->quantity, 3);

    EXPECT_THAT(leftSon->isLeaf, true);
    EXPECT_THAT(leftSon->byte, 'c');
    EXPECT_THAT(leftSon->quantity, 3);

}


TEST (main, CompareFiles) {
    auto input = "example.txt";
    auto decoded = "new_example.txt";
    std::ifstream f1(input, std::ios::binary);
    std::ifstream f2(decoded, std::ios::binary);


    f1.seekg(0, std::ios::end);
    auto size1 = f1.tellg();
    f1.seekg(0, std::ios::beg);

    std::vector<unsigned char> bytes1;
    for (int i = 0; i < size1; i++) {
        unsigned char symbol;
        f1.read((char *) &symbol, sizeof(symbol));
        bytes1.push_back(symbol);
    }
    f1.close();

    f2.seekg(0, std::ios::end);
    auto size2 = f2.tellg();
    f2.seekg(0, std::ios::beg);

    std::vector<unsigned char> bytes2;
    for (int i = 0; i < size2; i++) {
        unsigned char symbol2;
        f2.read((char *) &symbol2, sizeof(symbol2));
        bytes2.push_back(symbol2);
    }

    auto difference = std::equal(bytes1.begin(), bytes1.end(),
                                 bytes2.begin(), bytes2.end());
    EXPECT_THAT(size1, size2);
    EXPECT_THAT(difference, true);
}

TEST(main, Compression) {
    auto initial = "input.txt";
    auto compressed = "out3.txt";

    auto x = Encoder(initial, compressed);

    std::ifstream f1(initial, std::ios::binary);
    std::ifstream f2(compressed, std::ios::binary);


    f1.seekg(0, std::ios::end);
    f2.seekg(0, std::ios::end);
    auto size1 = f1.tellg();
    auto size2 = f2.tellg();


    EXPECT_TRUE(size1 >= size2);


}


TEST(TreeforBytes, Coding) {

    auto t = MakeTestTree();
    auto codes = t->Coding();
    std::vector<bool> code;
    std::vector<char> ExpecetdChars = {'a', 'b', 'c'};
    std::vector<std::vector<bool>> ExpectedCodes(3);
    ExpectedCodes[0] = {false, false};
    ExpectedCodes[1] = {false, true};
    ExpectedCodes[2] = {true};

    auto index = 0;
    for (auto i:codes) {
        auto code = i.second;
        auto symbol = i.first;
        auto difference = std::equal(code.begin(), code.end(),
                                     ExpectedCodes[index].begin(), ExpectedCodes[index].end());
        EXPECT_THAT(difference, true);
        EXPECT_THAT(symbol, ExpecetdChars[index]);
        ++index;
    }
}

TEST(TreeforBytes, DeepBypass) {
    auto t = MakeTestTree();
    auto treeLine = t->PrintTreeToFile();
    std::vector<char> expected = {'1', 'a', '1', 'b', '0', '1', 'c', '0'};

    auto difference1 = std::equal(treeLine.begin(), treeLine.end(),
                                  expected.begin(), expected.end());
    EXPECT_THAT(difference1, true);
}

TEST(BitWriter, Write_GetBit) {
    std::vector<bool> bits = {true, false, false,
                              false, false, false, true, false, true};
    BitWriter bw;
    for (auto i = 0; i < std::size(bits); ++i) {
        bw.WriteBit(bits[i]);
    }
    auto codedBytes = bw.getBytes();

    EXPECT_THAT(bw.extraBits, 7);
    EXPECT_THAT(codedBytes[0], 130);
    EXPECT_THAT(codedBytes[1], 128);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
