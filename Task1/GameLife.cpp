#include "GameLife.h"
#include <fstream>
#include <iostream>

/*GameLife::GameLife(int32_t n, int32_t m) {
scene = Field(n,m);
}*/

Field GameLife::getNextState() {
   // return Field(0, 0);
}

GameLife::GameLife(const std::string& input){
    int32_t n = 0;
    int32_t m = 0;
    std::ifstream input_file(input);
    input_file >> n >> m;
    std::vector<std::vector<char>> values;
    std::vector<char> line;
    char point;
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            input_file >> point;
            std::cout << point << " ";
            line.push_back(point);
        }
        values.push_back(line);
        line.clear();
        std::cout << std::endl;
    }
    scene = Field(values);
}

void GameLife::printScene() {
    scene.printField();
}

