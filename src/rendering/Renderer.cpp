#include "Renderer.h"

Renderer::Renderer():
window(sf::VideoMode(200, 200), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    cout << "Rendering system initialization" << endl;
}

void Renderer::update(float dt) {
    window.clear(sf::Color::White);
    window.display();
}
