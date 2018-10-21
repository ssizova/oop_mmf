#include <iostream>
#include <cmath>
#include <windef.h>
#include "Field.h"

Field::Field(int32_t n, int32_t m) {
    field = std::vector<std::vector<Cell>>(n, std::vector<Cell>(m));
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            Cell oneCell;
            oneCell.coordX = i;
            oneCell.coordY = j;
            oneCell.status = false;
            field[i][j] = oneCell;
        }
    }
}
Field::Field(const std::vector<std::vector<char>> &values) {
    int32_t n = values.size();
    int32_t m = values[0].size();
    field = std::vector<std::vector<Cell>>(n, std::vector<Cell>(m));
    for (int32_t i = 0; i < n; ++i) {
        for (int32_t j = 0; j < m; ++j) {
            Cell oneCell;
            oneCell.coordX = i;
            oneCell.coordY = j;
            if (values[i][j] == '*') {
                oneCell.status = true;
            } else if (values[i][j] == '_') {
                oneCell.status = false;
            }
            field[i][j] = oneCell;
        }
        //std::cout << std::endl;
    }
}

void Field::setStatus(int32_t i, int32_t j, bool alive) {
    field[i][j].status = alive;
}

std::vector<Cell> Field::getNeighbours(int32_t i, int32_t j) {
    Cell cell = field[i][j];
    int32_t x = cell.coordX;
    int32_t y = cell.coordY;
    int32_t n = field.size();
    int32_t m = field[0].size();
    int32_t leftX = std::max(x-1,0);
    int32_t rightX = std::min(x+1,n-1);
    int32_t leftY = std::max(y-1,0);
    int32_t rightY = std::min(y+1,m-1);
    std::vector<Cell> neighbours;

    for (int i = leftX; i<=rightX; ++i){
        for (int j =leftY; j<=rightY;  ++j ) {
            neighbours.push_back(field[i][j]);
        }
    }
    return  neighbours;
}

bool Field::getStatus(int32_t i, int32_t j) {
    return field[i][j].status;
}

void Field::printField() {
    for (auto line : field) {
        for (auto cell : line) {
            std::cout << cell.status << " ";
        }
        std::cout << std::endl;
    }
}

int32_t Field::countAliveNeighbours(int32_t i, int32_t j) {
    std::vector<Cell> neighbours = getNeighbours(i,j);
    int32_t counter = 0;
    for (auto &neighbour : neighbours) {
        counter+= neighbour.status;
    }
    return counter;
}

int32_t Field::getFieldWidth() {
    return field.size();
}

int32_t Field::getFieldHeight() {
    return field[0].size();
}


