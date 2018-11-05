#ifndef TASK1_GAMELIFE_H
#define TASK1_GAMELIFE_H


#include <cstdint>
#include <string>
#include "Field.h"

class GameLife {
    Field scene;
public:
    explicit GameLife(const std::string& input);
    explicit GameLife (Field field);
    Field getNextState();
    void playGame(int32_t iterations);
    void printScene();
    Field getField();

};


#endif //TASK1_GAMELIFE_H
