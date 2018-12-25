//
// Created by sofia on 24.12.18.
//

#include "Decoder.h"
#include <bitset>
#include <stack>


std::string Decoder::Decode(std::string codedData, const std::map<char, std::vector<bool>> &table) {

    std::string decoded;
    std::vector<bool> current;
    unsigned long long index = 0;
    while (!codedData.empty()) {
        current.push_back(codedData.front() == '1');

        codedData.erase(codedData.begin());
        char answer;
        auto err = IsInMap(table, current, &answer);
        while (err == -1 && !codedData.empty()) {
            current.push_back(codedData.front() == '1');

            codedData.erase(codedData.begin());
//            if (codedData.size() < 10) {
//                std::cout << "coded data: " << codedData << std::endl;
//            }
            err = IsInMap(table, current, &answer);
//            answer = IsInMap(table, current);
        }
        decoded += answer;
//        std::cout << static_cast<int>(answer) << ":" << index++ << std::endl;
        current.clear();
    }
    return decoded;
}

int Decoder::IsInMap(std::map<char, std::vector<bool>> table, std::vector<bool> key, char *out) {
//    std::string answer;
    for (auto i:table) {
        if (key == i.second) {
//            answer.push_back(i.first);
            *out = i.first;
            return 0;
        }
    }
//    answer = "No";
//    return answer;
    return -1;
}

TreeforBytes Decoder::RestoreTree(std::vector<unsigned char> line) {

    std::stack<std::shared_ptr<Element>> futureNodes;
    int32_t index = 0;
    while (index < std::size(line)) {
        if (line[index] == '1') {
            std::shared_ptr<Element> node(new Element);
            node->byte = line[index + 1];
            ++index;
            futureNodes.push(node);
        } else {
            if (std::size(futureNodes) != 1) {
                auto second = futureNodes.top();
                futureNodes.pop();
                auto first = futureNodes.top();
                futureNodes.pop();
                auto newNode = MakeNode(first, second);
                futureNodes.push(newNode);
            }
        }
        ++index;
    }
    auto root = futureNodes.top();

    auto tree = TreeforBytes(root);

    return tree;
}


Decoder::Decoder(std::string archive, std::string decodedFile) {
    std::ifstream f(archive, std::ios::binary);

    f.seekg(0, std::ios::end);
    auto size = f.tellg();
    f.seekg(0, std::ios::beg);

    unsigned char symbol;
//    f.read((char *) &symbol, sizeof(symbol));
//    extraBites = symbol;
    f >> symbol;
    std::cout << "extra bits read: " << static_cast<int>(symbol) << std::endl;

    unsigned long TreeLength = 0;
    f.read(reinterpret_cast<char *>(&TreeLength), sizeof(TreeLength));

//    std::cout << "tree length: " << TreeLength << std::endl;

    std::vector<unsigned char> treeLine;
    for (int i = 0; i < TreeLength ; i++) {
        f.read((char *) &symbol, sizeof(symbol));
        treeLine.push_back(symbol);
    }
    for (auto i = 0; i < std::size(treeLine); ++i) {
        std::cout << (treeLine[i]) << " ";
    }
    std::cout << std::endl;
    std::string codedData;
    for (int i = TreeLength + 2; i < size; ++i) {
        f.read((char *) &symbol, sizeof(symbol));
        auto x = std::bitset<8>(symbol);
        codedData += x.to_string();

    }
    codedData.erase(codedData.end() - extraBites, codedData.end());
//    codedData.erase(codedData.end() - extraBites, codedData.end());
    std::cout << codedData;


    tree = RestoreTree(treeLine);
    std::cout << "Left =" << tree.root->right->left->byte << std::endl;

    std::cout << "Restored map is" << std::endl;
    auto t = tree.Coding();
//    for (const auto &i: t) {
//        std::cout << i.first << ": ";
//        for (auto s:i.second) {
//            std::cout << s;
//        }
//    }
    std::cout << std::endl << "lkk" << std::endl;
    std::string sss = Decode(codedData, t);
//    std::cout << "String is" << std::endl << sss;
    auto outfile = std::ofstream(decodedFile);
    outfile << sss;


}

//    std::cout << std::endl;




