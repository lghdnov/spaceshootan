//
// Created by dimasik on 07.04.24.
//

#ifndef SPACESHOOTAN_WINDOW_H
#define SPACESHOOTAN_WINDOW_H

#include "SFML/Graphics.hpp"
#include "utils/impl.h"

class WindowC : public Component{
public:
    sf::Window& window;
    explicit WindowC(sf::Window& _window) : window(_window) {}
};

#endif //SPACESHOOTAN_WINDOW_H
