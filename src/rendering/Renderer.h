
#ifndef SPACESHOOTAN_RENDERER_H
#define SPACESHOOTAN_RENDERER_H

#include "fstream"
#include "SFML/Graphics.hpp"
#include "utils/impl.h"
#include "GraphicObject.h"

class Renderer : public System{
private:
    sf::RenderWindow window;
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("RENDERER")
            ->getLogger();
public:
    Renderer();

    void init(World* pWorld) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_RENDERER_H
