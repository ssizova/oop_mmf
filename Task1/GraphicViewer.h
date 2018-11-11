
#ifndef TASK1_GRAPHICVIEWER_H
#define TASK1_GRAPHICVIEWER_H

#include <SFML/Graphics.hpp>
#include <random>
#include "GameLife.h"


class Viewer {
    sf::RenderWindow *my_window;
    std::vector<sf::Vertex> grid;
    int32_t windowWidth;
    int32_t windowHeight;
    std::vector<std::vector<sf::RectangleShape>> cells;


public:

    ~Viewer();

    explicit Viewer(GameLife scene);
    void display_grid();
    std::vector<sf::Vertex> make_grid(GameLife scene);
    void display_field(GameLife scene);
    void display_game(GameLife initial, int32_t iterationNumber);
    void interactive_regime(GameLife initial);
};


#endif //TASK1_GRAPHICVIEWER_H
