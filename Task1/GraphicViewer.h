
#ifndef TASK1_GRAPHICVIEWER_H
#define TASK1_GRAPHICVIEWER_H

#include <SFML/Graphics.hpp>
#include <random>
#include "GameLife.h"

const int32_t width = 800;
const int32_t height = 800;
const int32_t bpp = 32;
//const sf::Color CELL_COLOR = sf::Color::Blue;

class Viewer {
    sf::RenderWindow *my_window;
public:
    Viewer(uint32_t width, uint32_t height);

    static void display_grid(sf::RenderWindow &rw, std::vector<sf::Vertex>);
    static std::vector<sf::Vertex> make_grid(Field scene) ;



private:

    //void draw_next(GameLife scene);

    std::vector<sf::Vertex> grid_visual;
    sf::Color visual_alive = sf::Color::Green;
    sf::Color visual_dead = sf::Color::Black;
};


#endif //TASK1_GRAPHICVIEWER_H
