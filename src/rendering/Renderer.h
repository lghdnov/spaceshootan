
#ifndef SPACESHOOTAN_RENDERER_H
#define SPACESHOOTAN_RENDERER_H

#include "fstream"
#include "SFML/Graphics.hpp"
#include "utils/impl.h"
#include "GraphicObject.h"
#include "Window.h"
#include "RenderMethod.h"
#include "WindowEvent.h"
#include "GarbageMark.h"
#include "imgui-SFML.h"
#include "imgui.h"

#include "Gui/ConnectionMenu.h"

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
