#include "Renderer.h"

Renderer::Renderer():
window(sf::VideoMode(200, 200), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    log->debug("Rendering system initialization");
    window.setVerticalSyncEnabled(true);
}

void Renderer::update(float dt) {
    window.clear(sf::Color::White);
    window.display();
}
