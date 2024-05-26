#include "CollisionHandler.h"

bool contains(vector<shared_ptr<Entity>>& vec, shared_ptr<Entity> value) {
    for (const shared_ptr<Entity>& element : vec) {
        if (element == value) {
            return true;
        }
    }
    return false;
}

CollisionHandler::CollisionHandler() = default;

void CollisionHandler::init(World *world) {
    log->debug("Collision handler initialization");
    this->world = world;
}

void CollisionHandler::update(float dt) {
    for (const auto &item: world->getEntities()){
        auto object = item->getComponent<PhysicalObject>();
        auto health = item->getComponent<Health>();
        if (!object) continue;

        for (const auto &item_: world->getEntities()){
            auto object_ = item_->getComponent<PhysicalObject>();
            auto health_ = item_->getComponent<Health>();
            if (!object_) continue;
            if (object == object_) continue;

            if (object->object->getGlobalBounds().intersects(object_->object->getGlobalBounds())){
                if (health && health_){
                    float dmg = health->health;
                    health->health -= health_->health;
                    health_->health -= dmg;
                }
                else if (health){
                    health->health = 0;
                }
                else if (health_){
                    health_->health = 0;
                }
            }
        }
    }
}