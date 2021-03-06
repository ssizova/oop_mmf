#include <utility>
#include "GameLife.h"
#include <fstream>
#include <iostream>

Field GameLife::getNextState() {
    int32_t n = scene.getFieldWidth();
    int32_t m = scene.getFieldHeight();
    Field newScene(n, m);
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            auto neighbours = scene.getNeighbours(i, j);
            if (scene.getStatus(i, j) == 0) {
                newScene.setStatus(i, j, neighbours == 3);
            } else {
                newScene.setStatus(i, j, (neighbours == 3) || (neighbours == 2));
            }
        }
    }
    scene = newScene;
    return newScene;
}

GameLife::GameLife(const std::string &input) {
    int32_t n = 0;
    int32_t m = 0;
    std::ifstream input_file(input);
    input_file >> n >> m;
    std::cout << n << " " << m << std::endl;
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
    scene.printField();
}

void GameLife::printScene() {
    scene.printField();
}

void GameLife::playGame(int32_t iterations) {
    for (int32_t i = 0; i < iterations; ++i) {
        std::cout << "Next step" << std::endl;
        printScene();
        scene = getNextState();
    }
}

Field GameLife::getField() {
    return scene;
}

GameLife::GameLife(Field field) {
    scene = std::move(field);
}