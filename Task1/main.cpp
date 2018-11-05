#include <iostream>
#include "GameLife.h"
#include "Field.h"
#include <SFML/Graphics.hpp>
#include "GraphicViewer.h"

int main() {

    std::cout << "1";
    GameLife gl("input.txt");
    sf::RenderWindow rw(sf::VideoMode(width, height), "Game Life");
    std::vector<sf::Vertex> mesh = Viewer::make_grid(gl,rw);
    Viewer::display_grid(rw, mesh);
    Viewer::display_field(rw, gl);
    Viewer::display_game(gl, 5, rw);


    return 0;
}