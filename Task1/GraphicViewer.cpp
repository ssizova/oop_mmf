#include <utility>

#include <utility>
#include "GameLife.h"
#include "GraphicViewer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <zconf.h>
#include <SFML/Audio.hpp>
#include <search.h>
#include <memory>


void Viewer::display_grid() {
    my_window->draw(&grid[0], grid.size(), sf::Lines);
}

std::vector<sf::Vertex> Viewer::make_grid(GameLife game) {

    Field scene = game.getField();
    int32_t n = scene.getFieldWidth();
    int32_t m = scene.getFieldHeight();

    double_t coeff_x = double(windowWidth) / m;
    double_t coeff_y = double(windowHeight) / n;


    std::vector<sf::Vertex> vertexes;

    for (int i = 0; i < m + 1; ++i) {
        vertexes.emplace_back(sf::Vector2f(static_cast<float>(i * coeff_x), 0));
        vertexes.emplace_back(sf::Vector2f(static_cast<float>(i * coeff_x), static_cast<float>((n) * coeff_y)));
    }
    for (int j = 0; j < n + 1; ++j) {
        vertexes.emplace_back(sf::Vector2f(0, static_cast<float>(j * coeff_y)));
        vertexes.emplace_back(sf::Vector2f(static_cast<float>((m) * coeff_x), static_cast<float>(j * coeff_y)));
    }

    return vertexes;

}

void Viewer::display_field(GameLife scene) {

    Field field = scene.getField();
    int32_t n = field.getFieldWidth();
    int32_t m = field.getFieldHeight();


    sf::Color color;
    sf::RectangleShape rectangle;


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field.getStatus(i, j) == 1) {
                color = sf::Color::Green;
            } else {
                color = sf::Color::Black;
            }

            cells[i][j].setFillColor(color);
            my_window->draw(cells[i][j]);
        }
    }


}

void Viewer::display_game(GameLife initial, int32_t iterationNumber) {

    auto iter = 0;
    while (iter < iterationNumber && my_window->isOpen()) {
        sf::Event event{};
        while (my_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                my_window->close();
            }
        }
        my_window->setActive();
        display_field(initial);
        initial.getNextState();
        display_grid();
        my_window->display();
        ++iter;
    }

}

Viewer::~Viewer() {
    my_window->close();
}

void Viewer::interactive_regime(GameLife initial) {
    Field start = initial.getField();
    while (my_window->isOpen()) {
        sf::Event event{};
        while (my_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                my_window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
                initial.getNextState();
            }
        }
        my_window->setActive();
        display_field(initial);
        display_grid();
        sf::sleep(sf::milliseconds(2));
        my_window->display();

    }
    my_window->close();

}

Viewer::Viewer(GameLife scene) :
    my_window(new sf::RenderWindow(sf::VideoMode(500, 500), "Game Life")) {

    Field field = scene.getField();
    windowWidth = my_window->getSize().x;
    windowHeight = my_window->getSize().y;
    grid = make_grid(scene);

    int32_t n = field.getFieldWidth();
    int32_t m = field.getFieldHeight();

    cells = std::vector<std::vector<sf::RectangleShape>>(static_cast<unsigned long>(n),
                                                         std::vector<sf::RectangleShape>(
                                                                 static_cast<unsigned long>(m)));
    double_t coeff_x = double(windowWidth) / m;
    double_t coeff_y = double(windowHeight) / n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cells[i][j] = sf::RectangleShape(sf::Vector2f(static_cast<float>(coeff_x), static_cast<float>(coeff_y)));
            cells[i][j].setPosition(static_cast<float>(j * coeff_x), static_cast<float>(i * coeff_y));

        }
    }
}






