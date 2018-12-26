#include "Decoder.h"
#include <bitset>
#include <stack>


std::string Decoder::Decode(std::string codedData, const std::map<char, std::vector<bool>> &table) {
    std::string decoded;
    std::vector<bool> current;
    while (!codedData.empty()) {
        current.push_back(codedData.front() == '1');

        codedData.erase(codedData.begin());
        char answer;
        auto err = IsInMap(table, current, &answer);
        while (err == -1 && !codedData.empty()) {
            current.push_back(codedData.front() == '1');

            codedData.erase(codedData.begin());
            err = IsInMap(table, current, &answer);

        }
        decoded += answer;
        current.clear();
    }
    return decoded;
}

int Decoder::IsInMap(std::map<char, std::vector<bool>> table, std::vector<bool> key, char *out) {
    for (auto i:table) {
        if (key == i.second) {
            *out = i.first;
            return 0;
        }
    }
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

    int runner = 0;
    f.seekg(0, std::ios::end);
    auto size = f.tellg();
    f.seekg(0, std::ios::beg);

    unsigned char symbol;
    f >> symbol;
    runner += sizeof(symbol);
    extraBites = symbol;

    unsigned long TreeLength = 0;
    f.read(reinterpret_cast<char *>(&TreeLength), sizeof(TreeLength));
    runner += sizeof(TreeLength);


    std::vector<unsigned char> treeLine;
    for (int i = 0; i < TreeLength; i++) {
        f.read((char *) &symbol, sizeof(symbol));
        runner += sizeof(symbol);
        treeLine.push_back(symbol);
    }


    std::string codedData;
    for (auto i = runner; i < size; ++i) {

        unsigned char symbol2;
        f.read((char *) &symbol2, sizeof(symbol2));
        auto x = std::bitset<8>(symbol2);
        codedData += x.to_string();
    }

    codedData.erase(codedData.end() - extraBites, codedData.end());

    tree = RestoreTree(treeLine);

    auto t = tree.Coding();

    std::string sss = Decode(codedData, t);

    auto outfile = std::ofstream(decodedFile);
    outfile << sss;
}






