
#ifndef SPACESHOOTAN_RENDERER_H
#define SPACESHOOTAN_RENDERER_H

#include "ecs.h"
#include "fstream"
#include "SFML/Graphics.hpp"
#include "logger.h"

class Renderer : public System{
private:
    sf::RenderWindow window;
public:
    Renderer();

    void init(World* pWorld) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_RENDERER_H
