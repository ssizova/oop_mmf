#include <utility>

#include <SFML/Graphics.hpp>
#include "GameLife.h"
#include "GraphicViewer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <zconf.h>
#include <SFML/Audio.hpp>
#include <search.h>


void Viewer::display_grid(sf::RenderWindow &rw, GameLife game) {
    auto vertexes = make_grid(rw, std::move(game));
    rw.draw(&vertexes[0], vertexes.size(), sf::Lines);
}

std::vector<sf::Vertex> Viewer::make_grid(sf::RenderWindow &rw, GameLife game) {
    Field scene = game.getField();
    int32_t n = scene.getFieldWidth();
    int32_t m = scene.getFieldHeight();
    int32_t window_width = rw.getSize().x;
    int32_t window_height = rw.getSize().y;

    double_t coeff_x = double(window_width) / n;
    double_t coeff_y = double(window_height) / m;


    std::vector<sf::Vertex> vertexes;
    for (int i = 0; i < n + 1; ++i) {
        vertexes.emplace_back(sf::Vector2f(static_cast<float>(i * coeff_x), 0));
        vertexes.emplace_back(sf::Vector2f(static_cast<float>(i * coeff_x), static_cast<float>((n) * coeff_x)));
    }
    for (int j = 0; j < m + 1; ++j) {
        vertexes.emplace_back(sf::Vector2f(0, static_cast<float>(j * coeff_y)));
        vertexes.emplace_back(sf::Vector2f(static_cast<float>((m) * coeff_y), static_cast<float>(j * coeff_y)));
    }
    return vertexes;

}

void Viewer::display_field(GameLife scene, sf::RenderWindow &rw) {

    Field field = scene.getField();
    int32_t n = field.getFieldWidth();
    int32_t m = field.getFieldHeight();
    int32_t window_width = rw.getSize().x;
    int32_t window_height = rw.getSize().y;
    double_t coeff_x = double(window_width) / n;
    double_t coeff_y = double(window_height) / m;

    sf::Color color;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sf::RectangleShape rectangle(sf::Vector2f(static_cast<float>(coeff_x), static_cast<float>(coeff_y)));
            if (field.getStatus(i, j) == 1) {
                color = sf::Color::Green;
            } else {
                color = sf::Color::Black;
            }
            rectangle.setFillColor(color);
            rectangle.setOutlineThickness(1);
            rectangle.setPosition(static_cast<float>(i * coeff_x), static_cast<float>(j * coeff_y));
            rw.draw(rectangle);
        }
    }
}

void Viewer::display_game(GameLife initial, int32_t iterationNumber, sf::RenderWindow &rw) {

    for (int i = 0; i < iterationNumber; ++i) {
        display_field(initial, rw);
        initial.getNextState();
        rw.display();
       // sleep(1);
    }
    rw.close();

}

Viewer::~Viewer() {
    my_window->close();
    delete my_window;
}

void Viewer::interactive_regime(GameLife initial, sf::RenderWindow &rw) {
    Field start = initial.getField();
    while (rw.isOpen()) {
        sf::Event event{};
        while (rw.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                rw.close();
            display_field(initial, rw);
            rw.display();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
                display_field(initial, rw);
                rw.display();
                initial.getNextState();
            }
        }
    }
}




