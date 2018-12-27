#include "Encoder.h"
#include "Haffman_algorithm.h"
#include "TreeforBytes.h"
#include "BitWriter.h"


Encoder::Encoder(std::string input, std::string output) {
    auto outfile = std::ofstream(output, std::ios::binary);
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
    auto line = Tree.PrintTreeToFile();
    outfile << static_cast<unsigned char>(bw.extraBits);
    unsigned long treeSize = line.size();
    outfile.write(reinterpret_cast<const char *>(&treeSize), sizeof(treeSize));
    for (const auto &i: line) {
        outfile << static_cast<unsigned char>(i);
    }

    for (auto s: codedBytes) {
        outfile << s;

    }
    outfile.close();
}

