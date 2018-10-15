#include <iostream>
#include "GameLife.h"
#include "Field.h"
int main() {
    std::string input_name = "input.txt";
    GameLife gl(input_name);
    gl.printScene();
    return 0;
}