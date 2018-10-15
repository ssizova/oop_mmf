#ifndef TASK1_GAMELIFE_H
#define TASK1_GAMELIFE_H


#include <cstdint>
#include <string>
#include "Field.h"

class GameLife {
    Field scene;
public:
    GameLife(const std::string& input);
    Field getNextState();
    //GameLife GameLife::setInitState(std::string input);
    void printScene();

};


#endif //TASK1_GAMELIFE_H
