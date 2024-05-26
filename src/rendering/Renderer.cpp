#include "Renderer.h"

Renderer::Renderer():
window(sf::VideoMode(1000, 1000), "SPACE SHOOTAN!")
{}

void Renderer::init(World *pWorld) {
    log->debug("Rendering system initialization");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    world = pWorld;

    auto window_ent = world->createEntity();

    window_ent->addComponent(make_shared<WindowC>(window));

    ImGui::SFML::Init(window);

    world->addSystem<ConnectionMenu>();
}

void Renderer::update(float dt) {
    sf::Clock time;
    if (window.isOpen()) {

        sf::Event event{};
        while (window.pollEvent(event)){
            ImGui::SFML::ProcessEvent(event);
            switch (event.type) {

                case sf::Event::Closed:
                    ImGui::SFML::Shutdown();
                    exit(EXIT_SUCCESS);
                    break;
                case sf::Event::Resized:
                    break;
            }

            auto world_event = world->createEntity();
            world_event->addComponent(make_shared<WindowEvent>(event));
            world_event->addComponent(make_shared<GarbageMark>());
        }


        ImGui::SFML::Update(window, time.restart());


        for (const auto &item: world->getEntities()){
            auto render_method = item->getComponent<RenderMethod>();
            if (!render_method) continue;

            render_method->method(dt, world);
        }


        window.clear(sf::Color::White);

        for (const auto &item: world->getEntities()){
            auto render_object = item->getComponent<GraphicObject>();
            if (!render_object) continue;

            window.draw(*render_object->object);
        }

        ImGui::SFML::Render(window);

        window.display();
    }
}
