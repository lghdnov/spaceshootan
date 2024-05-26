#ifndef SPACESHOOTAN_WINDOWEVENT_H
#define SPACESHOOTAN_WINDOWEVENT_H

#include "utils/impl.h"
#include "SFML/Graphics.hpp"

class WindowEvent : public Component{
public:
    sf::Event event;
    explicit WindowEvent(sf::Event _event): event(_event){}
};

#endif //SPACESHOOTAN_WINDOWEVENT_H
