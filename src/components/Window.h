//
// Created by dimasik on 07.04.24.
//

#ifndef SPACESHOOTAN_WINDOW_H
#define SPACESHOOTAN_WINDOW_H

#include "SFML/Graphics.hpp"
#include "utils/impl.h"

class WindowC : public Component{
public:
    sf::RenderWindow& window;
    explicit WindowC(sf::RenderWindow& _window) : window(_window) {}
};

#endif //SPACESHOOTAN_WINDOW_H
