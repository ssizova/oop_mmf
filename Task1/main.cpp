#include <iostream>
#include "GameLife.h"
#include "Field.h"
#include <SFML/Graphics.hpp>
#include "GraphicViewer.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "No input file or no iterarions. Please, enter them, or the program won't work!";
        return -1;
    }
    std::string input_name = argv[1];
    long iteration_number = strtol(argv[2], &argv[2], 10);

    GameLife gl(input_name);
    sf::RenderWindow rw(sf::VideoMode(width, height), "Game Life");
    Viewer::display_grid(rw, gl);
    if (iteration_number != 0) {
        Viewer::display_game(gl, static_cast<int32_t>(iteration_number), rw);
    } else {
        Viewer::interactive_regime(gl, rw);
    }

    return 0;

}