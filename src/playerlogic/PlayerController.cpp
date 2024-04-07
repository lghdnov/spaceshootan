#include "PlayerController.h"

PlayerController::PlayerController() = default;

void PlayerController::init(World* world) {
    log->debug("Player controller initialization");
    this->world = world;
    auto player = world->createEntity();

    auto playerShape = make_shared<sf::RectangleShape>(sf::Vector2f(100, 50));
    playerShape->setFillColor(sf::Color::Black);

    player->addComponent(make_shared<GraphicObject>(playerShape));
    player->addComponent(make_shared<PhysicalObject>(playerShape));

}

void PlayerController::update(float dt) {
    for (const auto &item: world->getEntities()){
        auto physic_object = item->getComponent<PhysicalObject>();
        if (!physic_object) continue;

        physic_object->object->move(0.5, 0);
    }
}