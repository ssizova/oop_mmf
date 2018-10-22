#include <iostream>
#include "GameLife.h"
#include "Field.h"
int main() {
    std::string input_name = "input.txt";
    GameLife gl(input_name);
    //gl.printScene();

    gl.playGame(5);
    return 0;
}