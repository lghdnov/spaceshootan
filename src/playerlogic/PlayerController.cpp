#include "PlayerController.h"

PlayerController::PlayerController() = default;

void PlayerController::init(World* world) {
    log->debug("Player controller initialization");
    this->world = world;
    auto player = world->createEntity();

    auto playerShape = make_shared<sf::ConvexShape>();
    playerShape->setFillColor(sf::Color::Black);
    playerShape->setPointCount(3);
    playerShape->setPoint(0, sf::Vector2f(-10, -20));
    playerShape->setPoint(1, sf::Vector2f(40, 0));
    playerShape->setPoint(2, sf::Vector2f (-10, 20));
    playerShape->setPosition(50, 50);

    player->addComponent(make_shared<GraphicObject>(playerShape));
    player->addComponent(make_shared<PhysicalObject>(playerShape));
    player->addComponent(make_shared<LocalPlayer>());

}

void PlayerController::update(float dt) {
    for (const auto &item: world->getEntities()){
        auto physic_object = item->getComponent<PhysicalObject>();
        auto player = item->getComponent<LocalPlayer>();
        if (!physic_object || !player) continue;

        physic_object->object->move(0.5, 0);
    }
}