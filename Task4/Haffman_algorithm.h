//
// Created by sofia on 17.12.18.
//

#ifndef TASK4_HAFFMAN_ALGORITHM_H
#define TASK4_HAFFMAN_ALGORITHM_H

struct TreeElement {
    int32_t byte;
    int32_t frequency;
    TreeElement left;
    TreeElement right;

};
void MakeTree(TreeElement root);
void Coding (std::string filename);
#endif //TASK4_HAFFMAN_ALGORITHM_H
