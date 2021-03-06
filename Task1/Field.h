#ifndef TASK1_FIELD_H
#define TASK1_FIELD_H

#include <cstdint>
#include <vector>

struct Cell {
    int32_t coordX = 0;
    int32_t coordY = 0;
    bool status = false;
};

class Field {
    std::vector<std::vector<Cell>> field;
public:
    Field() = default;
    Field(int32_t n, int32_t m);

    explicit Field(const std::vector<std::vector<char>>& values);
    void setStatus(int32_t i, int32_t j, bool alive);
    int32_t getNeighbours(int32_t i, int32_t j);
    bool getStatus(int32_t i, int32_t j);
    void printField();
    int32_t getFieldWidth();
    int32_t getFieldHeight();

};

#endif //TASK1_FIELD_H
