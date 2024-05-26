#include "ViewController.h"

ViewController::ViewController() = default;

void ViewController::init(World *world) {
    this->world = world;

    shared_ptr<WindowC> windowC;

    for (const auto &item: world->getEntities()){
        auto window = item->getComponent<WindowC>();
        if (!window) continue;
        windowC = window;
        break;
    }

    view = sf::View(sf::FloatRect(
            0,
            0,
            windowC->window.getSize().x,
            windowC->window.getSize().y
    ));

    windowC->window.setView(view);
}

void ViewController::update(float dt) {

    shared_ptr<WindowC> windowC;

    for (const auto &item: world->getEntities()){
        auto window = item->getComponent<WindowC>();
        if (!window) continue;
        windowC = window;
        break;
    }

    for (const auto &item: world->getEntities()){
        auto player = item->getComponent<LocalPlayer>();
        auto object = item->getComponent<PhysicalObject>();
        if (!player || !object) continue;

        view.setCenter(object->object->getPosition());
    }

    windowC->window.setView(view);
}