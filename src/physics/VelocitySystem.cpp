#include "VelocitySystem.h"

VelocitySystem::VelocitySystem() = default;

void VelocitySystem::init(World *world) {
    log->debug("Velocity system initialization");
    this->world = world;
}

void VelocitySystem::update(float dt) {
    processRotations(dt);
    processMovements(dt);
}

void VelocitySystem::processMovements(float dt) {
    for (const auto &item: world->getEntities()){
        auto object = item->getComponent<PhysicalObject>();
        auto vel = item->getComponent<PositionVelocity>();
        if (!object || !vel) continue;

        object->object->move(vel->x_vel, vel->y_vel);
    }
}

void VelocitySystem::processRotations(float dt) {
    for (const auto &item: world->getEntities()){
        auto object = item->getComponent<PhysicalObject>();
        auto vel = item->getComponent<RotationVelocity>();
        if (!object || !vel) continue;

        object->object->rotate(vel->velocity);
    }

}