
#ifndef TASK1_GRAPHICVIEWER_H
#define TASK1_GRAPHICVIEWER_H

#include <SFML/Graphics.hpp>
#include <random>
#include "GameLife.h"

const int32_t width = 1000;
const int32_t height = 1000;


class Viewer {
    sf::RenderWindow *my_window;
public:

    ~Viewer();

    static void display_grid(sf::RenderWindow &rw, GameLife game);
    static std::vector<sf::Vertex> make_grid(sf::RenderWindow &rw,GameLife scene) ;
    static void display_field(GameLife scene,sf::RenderWindow &rw);
    static void display_game (GameLife initial,int32_t iterationNumber, sf::RenderWindow &rw);
    static void interactive_regime(GameLife initial, sf::RenderWindow &rw);
};


#endif //TASK1_GRAPHICVIEWER_H
