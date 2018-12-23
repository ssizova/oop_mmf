//
// Created by sofia on 23.12.18.
//

#include "Encoder.h"
#include "Haffman_algorithm.h"
#include "TreeforBytes.h"
#include "BitWriter.h"



Encoder::Encoder(std::string input,std::string output) {
    auto outfile = std::ofstream(output);
    auto bytes = ReadingBytes(input);
    TreeforBytes Tree = TreeforBytes(bytes);
    table = Tree.Coding();

    BitWriter bw;

    std::ifstream f (input, std::ios::binary);

    f.seekg(0, std::ios::end);
    auto size = f.tellg();
    f.seekg(0, std::ios::beg);

    for (int i = 0; i < size; i++) {
        unsigned char symbol;
        f.read((char *) &symbol, sizeof(symbol));
        auto code = table[symbol];
        for (auto bit: code){
            bw.WriteBit(bit);
        }
    }
    std::cout <<std::endl<< "******"<< std::endl;
    auto codedBytes = bw.getBytes();
    std::cout <<std::endl<< "******"<< std::endl;
    std::cout<<codedBytes.size();
    for (auto s: codedBytes){
        outfile<<s;
//        std::cout<<"5";

    }
    outfile.close();
}
