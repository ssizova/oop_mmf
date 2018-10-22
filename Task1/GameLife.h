#ifndef TASK1_GAMELIFE_H
#define TASK1_GAMELIFE_H


#include <cstdint>
#include <string>
#include "Field.h"

class GameLife {
    Field scene;
public:
    explicit GameLife(const std::string& input);
    Field getNextState();
    void playGame(int32_t iterations);
    void printScene();

};


#endif //TASK1_GAMELIFE_H
