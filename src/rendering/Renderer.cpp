#include "Renderer.h"

Renderer::Renderer():
window(sf::VideoMode(1000, 1000), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    log->debug("Rendering system initialization");
    window.setVerticalSyncEnabled(true);
    world = pWorld;
}

void Renderer::update(float dt) {
    if (window.isOpen()) {
        window.clear(sf::Color::White);

        for (const auto &item: world->getEntities()){
            auto render_object = item->getComponent<GraphicObject>();
            if (!render_object) continue;

            window.draw(*render_object->object);
        }

        window.display();
    }
}
