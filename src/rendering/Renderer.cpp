#include "Renderer.h"


static auto file = ofstream("logs.txt");

static auto log = logz::LoggerBuilder::newLogger("RENDERER")
        ->addOut(&std::cout)
        ->addOut(&file)
        ->addStandardModifiers()
        ->getLogger();

Renderer::Renderer():
window(sf::VideoMode(200, 200), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    log->debug("Rendering system initialization");
}

void Renderer::update(float dt) {
    window.clear(sf::Color::White);
    window.display();
}
