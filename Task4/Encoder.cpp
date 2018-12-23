//
// Created by sofia on 23.12.18.
//

#include "Encoder.h"
#include "Haffman_algorithm.h"
#include "TreeforBytes.h"
#include "BitWriter.h"


Encoder::Encoder(std::string input, std::string output) {
    auto outfile = std::ofstream(output);
    auto bytes = ReadingBytes(input);
    TreeforBytes Tree = TreeforBytes(bytes);
    table = Tree.Coding();

    BitWriter bw;

    std::ifstream f(input, std::ios::binary);

    f.seekg(0, std::ios::end);
    auto size = f.tellg();
    f.seekg(0, std::ios::beg);

    for (int i = 0; i < size; i++) {
        unsigned char symbol;
        f.read((char *) &symbol, sizeof(symbol));
        auto code = table[symbol];
        for (auto bit: code) {
            bw.WriteBit(bit);
        }
    }
    auto codedBytes = bw.getBytes();

    std::cout << codedBytes.size();
    auto line = Tree.PrintTreeToFile();
    std::cout<< "Extra = "<<bw.extraBits<<std::endl;

    outfile << static_cast<unsigned char>(bw.extraBits) <<std::endl;
    for (const auto &i: line) {
        outfile << i;
    }
outfile<<std::endl;
    for (auto s: codedBytes) {
          outfile << s;

    }
    outfile.close();
}
