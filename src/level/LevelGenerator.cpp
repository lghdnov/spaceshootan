#include "LevelGenerator.h"


LevelGenerator::LevelGenerator() = default;

void LevelGenerator::init(World *world) {
    log->debug("Initializing level generator");
    log->info("Generating world objects...");

    auto star = make_shared<sf::CircleShape>();
    star->setFillColor(sf::Color::Black);
    star->setRadius(150);
    star->setOrigin(star->getRadius(), star->getRadius());
    star->setPosition(500, 500);

    auto star_entity = world->createEntity();
    star_entity->addComponent(make_shared<PhysicalObject>(star));
    star_entity->addComponent(make_shared<GraphicObject>(star));
    star_entity->addComponent(make_shared<PositionVelocity>(0, 0));
    star_entity->addComponent(make_shared<RotationVelocity>(0));
    star_entity->addComponent(make_shared<Mass>(5));
}

void LevelGenerator::update(float dt) {}