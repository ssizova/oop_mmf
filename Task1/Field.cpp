#include <iostream>
#include <cmath>
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
    auto n = static_cast<int32_t>(values.size());
    auto m = static_cast<int32_t>(values[0].size());
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
    }
}

void Field::setStatus(int32_t i, int32_t j, bool alive) {
    field[i][j].status = alive;
}

int32_t Field::getNeighbours(int32_t i, int32_t j) {
    auto n = static_cast<int32_t>(field.size());
    auto m = static_cast<int32_t>(field[0].size());
    int32_t result = 0;

    for (int32_t ii = -1; ii <= 1; ++ii) {
        for (int32_t jj = -1; jj <= 1; ++jj) {
            if (ii == 0 && jj == 0) {
                continue;
            }
            result += field[(i + ii + n) % n][(j + jj + m) % m].status;
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


int32_t Field::getFieldWidth() {
    return static_cast<int32_t>(field.size());
}

int32_t Field::getFieldHeight() {
    return static_cast<int32_t>(field[0].size());
}


