//
// Created by sofia on 21.12.18.
//

#ifndef TASK4_TREEFORBYTES_H
#define TASK4_TREEFORBYTES_H


#include "Haffman_algorithm.h"

class TreeforBytes {
    std::shared_ptr<Element> root;
    void printElement(std::shared_ptr<Element>  e);

public:
    explicit TreeforBytes (const std::vector<std::shared_ptr<Element> > &array);
    void printTree();
    std::map<char,std::vector<bool>> Coding();
    void MakeCode(std::shared_ptr<Element> root);
    void PrintTreeToFile(std::string output);
    void DeepBypass(std::shared_ptr<Element> root);//, std::ofstream output);




    };


#endif //TASK4_TREEFORBYTES_H
