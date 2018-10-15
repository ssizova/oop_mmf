#include <iostream>
#include <cmath>
#include <windef.h>
#include "Field.h"

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
        std::cout << std::endl;
    }
}

void Field::setStatus(int32_t i, int32_t j, bool alive) {
    field[i][j].status = alive;
}

/*std::vector<Cell> Field::getNeighbours(Cell cell,) {
    int32_t x = cell.coordX;
    int32_t y = cell.coordY;
    int32_t n = field.size();
    int32_t m = field[0].size();
    int32_t leftX = std::max(x-1,0);
    int32_t rightX = std::min(x+1,n-1);
    int32_t leftY = std::max(y-1,0);
    int32_t rightY = std::min(y+1,m-1);/*


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

