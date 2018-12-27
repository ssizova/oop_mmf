//
// Created by sofia on 21.12.18.
//

#ifndef TASK4_TREEFORBYTES_H
#define TASK4_TREEFORBYTES_H


#include "Haffman_algorithm.h"


class TreeforBytes {//: ByteTree {
    std::shared_ptr<Element> root;
public:
    TreeforBytes() = default;;

    explicit TreeforBytes(std::shared_ptr<Element> element);

    explicit TreeforBytes(const std::vector<std::shared_ptr<Element> > &array);

    std::map<char, std::vector<bool>> Coding();

    void MakeCode(std::shared_ptr<Element> root, std::vector<bool> &code,
                  std::map<char, std::vector<bool>> &table);

    std::vector<char> PrintTreeToFile();

    void DeepBypass(std::shared_ptr<Element> root, std::vector<char> &bytes);

};


#endif //TASK4_TREEFORBYTES_H
