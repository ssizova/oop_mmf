//
// Created by sofia on 21.12.18.
//

#ifndef TASK4_TREEFORBYTES_H
#define TASK4_TREEFORBYTES_H


#include "Haffman_algorithm.h"

class TreeforBytes {

public:

    std::shared_ptr<Element> root;

    TreeforBytes() = default;;

    explicit TreeforBytes(std::shared_ptr<Element> element);
    void printElement(std::shared_ptr<Element>  e);

    explicit TreeforBytes (const std::vector<std::shared_ptr<Element> > &array);
    void printTree();
    std::map<char,std::vector<bool>> Coding();
    void MakeCode(std::shared_ptr<Element> root, std::vector<bool> &code,
                  std::map<char, std::vector<bool>> &table);
    std::vector<char> PrintTreeToFile();
    void DeepBypass(std::shared_ptr<Element> root);//, std::ofstream output);




    };


#endif //TASK4_TREEFORBYTES_H
