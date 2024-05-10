#include "Renderer.h"

Renderer::Renderer():
window(sf::VideoMode(1000, 1000), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    log->debug("Rendering system initialization");
    window.setVerticalSyncEnabled(true);
    world = pWorld;

    auto window_ent = world->createEntity();

    window_ent->addComponent(make_shared<WindowC>(window));
}

void Renderer::update(float dt) {
    if (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)){
            switch (event.type) {

                case sf::Event::Closed:
                    exit(EXIT_SUCCESS);
                    break;
                case sf::Event::Resized:
                    break;
            }
        }

        window.clear(sf::Color::White);

        for (const auto &item: world->getEntities()){
            auto render_object = item->getComponent<GraphicObject>();
            if (!render_object) continue;

            window.draw(*render_object->object);
        }

        window.display();
    }
}
