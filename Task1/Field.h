#ifndef TASK1_FIELD_H
#define TASK1_FIELD_H


#include <cstdint>
#include <vector>

struct Cell {
    int32_t coordX;
    int32_t coordY;
    //char value;
    bool status;
};

class Field {
    //std::vector<std::vector<Cell>> field;
    std::vector<std::vector<Cell>> field;
public:
    Field(){}
    Field(const std::vector<std::vector<char>>& values);
    void setStatus(int32_t i, int32_t j, bool alive);
    std::vector<Cell> getNeighbours(Cell cell);
    bool getStatus(int32_t i, int32_t j);
    void printField();
};



#endif //TASK1_FIELD_H
