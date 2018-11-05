#include <SFML/Graphics.hpp>
#include "GameLife.h"
#include "GraphicViewer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <zconf.h>
#include <SFML/Audio.hpp>


Viewer::Viewer(uint32_t width, uint32_t height) {
    my_window = new sf::RenderWindow(sf::VideoMode(width, height), "Game Life");
}

void Viewer::display_grid(sf::RenderWindow &rw, std::vector<sf::Vertex> vrtx) {
    rw.draw(&vrtx[0], vrtx.size(), sf::Lines);
}

std::vector<sf::Vertex> Viewer::make_grid(GameLife game,sf::RenderWindow &rw) {
    Field scene = game.getField();
    int32_t n = scene.getFieldWidth();
    int32_t m = scene.getFieldHeight();
    int32_t window_width = rw.getSize().x;
    int32_t window_height = rw.getSize().y;

    int32_t coeff_x = window_width / (n);
    int32_t coeff_y = window_height / (m);


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

void Viewer::display_field(sf::RenderWindow &rw, GameLife scene) {

    Field field = scene.getField();
    int32_t n = field.getFieldWidth();
    int32_t m = field.getFieldHeight();
    int32_t window_width = rw.getSize().x;
    int32_t window_height = rw.getSize().y;
    int32_t coeff_x = window_width / n;
    int32_t coeff_y = window_height / (m);

    sf::Color color;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sf::RectangleShape rectangle(sf::Vector2f(coeff_x, coeff_y));
            if (field.getStatus(i, j) == 1) {
                color = sf::Color::Green;
            } else {
                color = sf::Color::Black;
            }
            rectangle.setFillColor(color);
            rectangle.setOutlineThickness(1);
            rectangle.setPosition(i * coeff_x, j * coeff_y);
            rw.draw(rectangle);
        }
    }
}

void Viewer::display_game(GameLife initial, int32_t iterationNumber, sf::RenderWindow &rw) {

    Field start = initial.getField();
    for (int i = 0; i < iterationNumber; ++i) {
        display_field(rw, initial);
        initial.getNextState();
        //start = initial.getField();
        rw.display();
        sleep(1);

    }
    rw.display();
    rw.close();

}

Viewer::~Viewer() {
    my_window->close();
    delete my_window;
}




