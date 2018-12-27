#include <utility>
#include <vector>
#include "TreeforBytes.h"


TreeforBytes::TreeforBytes(const std::vector<std::shared_ptr<Element> > &array) {
    root = MakeTree(array);
}


void TreeforBytes::MakeCode(std::shared_ptr<Element> root, std::vector<bool> &code,
                            std::map<char, std::vector<bool>> &table) {

    if (root->left != nullptr) {
        code.push_back(false);
        MakeCode(root->left, code, table);
    }

    if (root->right != nullptr) {
        code.push_back(true);
        MakeCode(root->right, code, table);
    }
    if (root->isLeaf) {
        table[root->byte] = code;
    }
    code.pop_back();
}


std::map<char, std::vector<bool>> TreeforBytes::Coding() {
    std::vector<bool> code;
    std::map<char, std::vector<bool>> table;
    MakeCode(root, code, table);
    return table;
}


void TreeforBytes::DeepBypass(std::shared_ptr<Element> root, std::vector<char> &bytes) {

    if (root->left != nullptr) {
        DeepBypass(root->left, bytes);
    }
    if (root->right != nullptr) {
        DeepBypass(root->right, bytes);
    }

    if (root->isLeaf) {
        bytes.push_back('1');
        bytes.push_back(root->byte);
    } else {
        bytes.push_back('0');
    }
}


std::vector<char> TreeforBytes::PrintTreeToFile() {
    std::vector<char> bytes;
    DeepBypass(root, bytes);

    return bytes;
}

TreeforBytes::TreeforBytes(std::shared_ptr<Element> element) {
    root = std::move(element);

}




