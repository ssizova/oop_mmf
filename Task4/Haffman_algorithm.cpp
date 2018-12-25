#include <queue>
#include "Haffman_algorithm.h"


std::vector<std::shared_ptr<Element> > ReadingBytes(const std::string &path) {
    std::ifstream f(path, std::ios::binary);

    f.seekg(0, std::ios::end);
    auto size = f.tellg();
    f.seekg(0, std::ios::beg);

    std::vector<int32_t> weights(256, 0);
    for (int i = 0; i < size; i++) {
        unsigned char symbol;
        f.read((char *) &symbol, sizeof(symbol));
        ++weights[symbol];
    }

    std::vector<std::shared_ptr<Element> > nonzero_weights;
    for (auto i = 0; i < 256; ++i) {
        if (weights[i] != 0) {
            std::shared_ptr<Element> buffer (new Element);
            buffer->byte = static_cast<unsigned char>(i);
            buffer->quantity = weights[i];
            buffer->isLeaf = true;
            nonzero_weights.push_back(buffer);
        }
    }
//    f.close();
    return nonzero_weights;
}

std::shared_ptr<Element> MakeNode(std::shared_ptr<Element> first, std::shared_ptr<Element> second) {
    std::shared_ptr<Element> node(new Element);
    node->quantity = first->quantity + second->quantity;
    node->isLeaf = false;
    node->left = first;
    node->right = second;
    node->byte = 0;

    return node;
}


std::priority_queue<std::shared_ptr<Element> , std::vector<std::shared_ptr<Element> >, ElementComparator>
MakeQueue(const std::vector<std::shared_ptr<Element> > &vector) {
    std::priority_queue<std::shared_ptr<Element> , std::vector<std::shared_ptr<Element> >, ElementComparator> queue;
    std::cout << "MakeQueue - std::size(vector) - " << std::size(vector) << std::endl;
    for (auto i = 0; i < std::size(vector); ++i) {

        queue.push(vector[i]);
    }
    return queue;
}

std::shared_ptr<Element> MakeTree(const std::vector<std::shared_ptr<Element> > &array) {
    auto Tree = MakeQueue(array);
    std::cout << "MakeTree - std::size(vector) - " << std::size(Tree) << std::endl;

    while (std::size(Tree) > 1) {
        auto first = Tree.top();
//        std::cout << first->byte << ":" << first->quantity << std::endl;
        Tree.pop();
        auto second = Tree.top();
//        std::cout << second->byte << ":" << second->quantity << std::endl;
        Tree.pop();
        auto next = MakeNode(first, second);

        Tree.push(next);

    }
    return Tree.top();

}


void printMap(std::map<char, std::vector<bool>> table) {

    for (auto kv:table){
        std::cout<<kv.first << " ";
        for (auto i: kv.second) {
            std::cout<<i;
        }
        std::cout<<std::endl;
    }
}



