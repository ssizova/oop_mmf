#include <iostream>
#include "GameLife.h"
#include "Field.h"
#include <SFML/Graphics.hpp>
#include "GraphicViewer.h"

int main() {

    std::cout << "1";
    //Viewer d;
    //Viewer window(800, 800);
    Field field(10, 10);
    sf::RenderWindow rw(sf::VideoMode(width, height), "Game Life");

    while (rw.isOpen()) {
        sf::Event event{};
        while (rw.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                rw.close();
            std::vector<sf::Vertex> mesh = Viewer::make_grid(field);
            Viewer::display_grid(rw, mesh);
            rw.display();
        }
    }


    return 0;
}