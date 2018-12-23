//
// Created by sofia on 21.12.18.
//

#include "TreeforBytes.h"


TreeforBytes::TreeforBytes(const std::vector<std::shared_ptr<Element> > &array) {
    root = MakeTree(array);
}

void TreeforBytes::printElement(std::shared_ptr<Element> e) {
    std::cout << "Element ";
    std::cout << e->isLeaf << " " << std::endl;


}

void TreeforBytes::printTree() {
    std::shared_ptr<Element> current = root;
    std::queue<std::shared_ptr<Element>> queue;
    queue.push(current);

    while (!queue.empty()) {
        std::cout << "size" << queue.size() << std::endl;
        auto node = queue.front();
        queue.pop();
        printElement(node);
        if (node->left != nullptr) {
            queue.push(node->left);

        }
        if (node->right != nullptr) {
            queue.push(node->right);
        }

    }
}

std::vector<bool> code;
std::map<char, std::vector<bool>> table;

void TreeforBytes::MakeCode(std::shared_ptr<Element> root) {

//    std::shared_ptr<Element> current = root;
    if (root->left != nullptr) {
        code.push_back(false);
        MakeCode(root->left);
    }

    if (root->right != nullptr) {
        code.push_back(true);
        MakeCode(root->right);
    }
    if (root->isLeaf) {
        table[root->byte] = code;
    }
    code.pop_back();
}


std::map<char, std::vector<bool>> TreeforBytes::Coding() {
    MakeCode(root);
    return table;
}

std::vector<char> bytes;

void TreeforBytes::DeepBypass(std::shared_ptr<Element> root) {//, std::ofstream output) {

    if (root->isLeaf) {
        bytes.push_back(root->byte);
        return;
    }

    if (root->left != nullptr) {
        bytes.push_back('0');
        DeepBypass(root->left);

    }

    if (root->right != nullptr) {
        bytes.push_back('1');
        DeepBypass(root->right);
    }
}


void TreeforBytes::PrintTreeToFile(std::string output) {
//    std::vector<char> bytes;
    auto outfile = std::ofstream(output);
    DeepBypass(root);
    for (auto i: bytes) {
        std::cout << i;
        outfile << i;
    }
}




