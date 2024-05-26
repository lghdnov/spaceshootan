#include "HealthSystem.h"

HealthSystem::HealthSystem() = default;

void HealthSystem::init(World *world) {
    log->debug("Health system initialization");
    this->world = world;
}

void HealthSystem::update(float dt) {
    for (const auto &item: world->getEntities()){
        auto health = item->getComponent<Health>();
        auto object = item->getComponent<PhysicalObject>();
        if (!health) continue;

        if (health->health <= 0){
            item->addComponent(make_shared<GarbageMark>());

            if (object){
//                auto pos = object->object->getPosition();
//
//                pos.x += rand() % 50;
//                pos.y += rand() % 50;
//
//                auto smoke_circle = make_shared<sf::CircleShape>();
//                smoke_circle->setRadius(20);
//                smoke_circle->setOrigin(smoke_circle->getRadius(), smoke_circle->getRadius());
//                smoke_circle->setFillColor(sf::Color(50, 50, 50));
//                smoke_circle->setPosition(pos);
//
//                auto smoke = world->createEntity();
//                smoke->addComponent(make_shared<ExplosionParticle>(ExplosionParticleType::SMOKE, 0));
//                smoke->addComponent(make_shared<GraphicObject>(smoke_circle));
//                auto smoke_circle = make_shared<sf::CircleShape>();
//                smoke_circle->setRadius(30);
//                smoke_circle->setOrigin(smoke_circle->getRadius(), smoke_circle->getRadius());
//                smoke_circle->setFillColor(sf::Color(100, 100, 100));
//                smoke_circle->setPosition(object->object->getPosition());
//
//                auto smoke = world->createEntity();
//                smoke->addComponent(make_shared<ExplosionParticle>(ExplosionParticleType::WAVE, 0));
//                smoke->addComponent(make_shared<GraphicObject>(smoke_circle));
            }
        }
    }

//    for (const auto &item: world->getEntities()){
//        auto object = item->getComponent<GraphicObject>();
//        auto particle = item->getComponent<ExplosionParticle>();
//        if (!object || !particle) continue;
//
//        if (particle->animStep >= 150){
//            item->addComponent(make_shared<GarbageMark>());
//            continue;
//        }
//
//        auto scale = object->object->getScale();
//        scale.x += 0.5f * dt;
//        scale.y += 0.5f * dt;
//
//        object->object->setScale(scale);
//
//        if (particle->type != ExplosionParticleType::SMOKE) continue;
//
//        auto color = object->object->getFillColor();
//        color.r += 1;
//        color.g += 1;
//        color.b += 1;
//
//        object->object->setFillColor(color);
//
//        particle->animStep++;
//    }
}