#include <iostream>
#include <cmath>
//#include <windef.h>
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

//std::vector<Cell> Field::getNeighbours(int32_t i, int32_t j) {
//    int32_t n = field.size();
//    int32_t m = field[0].size();
//
//    std::vector<Cell> neighbours;
//    for (int32_t ii = -1; ii <= 1; ++ii) {
//        for (int32_t jj = -1; jj <= 1; ++jj) {
//            if (ii == 0 && jj == 0) {
//                continue;
//            }
//            neighbours.push_back(field[(i + ii + n) % n][(j + jj + m) % m]);
//
//        }
//
//    }
//
//    return neighbours;
//}
int32_t Field::getNeighbours(int32_t i, int32_t j) {
    int32_t n = field.size();
    int32_t m = field[0].size();
    int32_t result = 0;
//    std::vector<Cell> neighbours;
    for (int32_t ii = -1; ii <= 1; ++ii) {
        for (int32_t jj = -1; jj <= 1; ++jj) {
            if (ii == 0 && jj == 0) {
                continue;
            }
            result += field[(i + ii + n) % n][(j + jj + m) % m].status;
//            neighbours.push_back(field[(i + ii + n) % n][(j + jj + m) % m]);
        }

    }

    return result;
}

bool Field::getStatus(int32_t i, int32_t j) {
    return field[i][j].status;
}

void Field::printField() {
    for (auto line : field) {
        for (auto cell : line) {
            std::cout << (cell.status ? "* " : "_ ");
        }
        std::cout << std::endl;
    }
}

//int32_t Field::countAliveNeighbours(int32_t i, int32_t j) {
//    std::vector<Cell> neighbours = getNeighbours(i, j);
//    int32_t counter = 0;
//    for (auto &neighbour : neighbours) {
//        counter += neighbour.status;
//    }
//    return counter;
//}

int32_t Field::getFieldWidth() {
    return field.size();
}

int32_t Field::getFieldHeight() {
    return field[0].size();
}


