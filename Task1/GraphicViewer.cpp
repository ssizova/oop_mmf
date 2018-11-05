#include <SFML/Graphics.hpp>
#include "GameLife.h"
#include "GraphicViewer.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Viewer::Viewer(uint32_t width, uint32_t height) {
   // auto window1 = new sf::RenderWindow(sf::VideoMode(width, height), "Game Life");
    my_window = new sf::RenderWindow(sf::VideoMode(width, height), "Game Life") ;

    //auto &window = sf::RenderWindow(sf::VideoMode(width, height), "Game Life"));
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window->isOpen()) {
//        sf::Event event;
//        while (window->pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window->close();
//        }
//
//        window->clear();
//        window->draw(shape);
//        window->display();
//    }
}

void Viewer::display_grid(sf::RenderWindow &rw, std::vector<sf::Vertex> vrtx) {
    rw.draw(&vrtx[0], vrtx.size(), sf::Lines);
}

std::vector<sf::Vertex> Viewer::make_grid(Field scene)  {
    int32_t n = scene.getFieldWidth();
    int32_t m = scene.getFieldHeight();
    int32_t  window_width = 800;//my_window->getSize().x;
    int32_t  window_height = 800;//window->getSize().y;

    int32_t coeff_x = window_width/(n);
    int32_t coeff_y = window_height/(m);



    std::vector<sf::Vertex> vertexes;
    for (int i = 0; i < n + 1; ++i) {
        vertexes.emplace_back(sf::Vector2f(i * coeff_x, 0));
        vertexes.emplace_back(sf::Vector2f(i * coeff_x, (n) * coeff_x));
    }
    for (int j = 0; j < m + 1; ++j) {
        vertexes.emplace_back(sf::Vector2f(0, j * coeff_y));
        vertexes.emplace_back(sf::Vector2f((m) * coeff_y, j * coeff_y));
    }
    return vertexes;

}


//void Viewer::draw_next(GameLife scene) {
//
//
//}

