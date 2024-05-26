#include "GravitationSystem.h"


struct GravityObject{
    shared_ptr<PositionVelocity> velocity;
    shared_ptr<PhysicalObject> object;
    shared_ptr<Mass> mass;
};

sf::Vector2f calculateGravitationalForce(const sf::Vector2f& position1, float mass1,
                                         const sf::Vector2f& position2, float mass2) {
    sf::Vector2f direction = position2 - position1;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
    //float magnitude = G * mass1 * mass2 / (distance * distance);
    float magnitude = mass2 * 0.000001;
    direction /= distance;
    return direction * magnitude;
}

GravitationSystem::GravitationSystem() = default;

void GravitationSystem::init(World *world) {
    this->world = world;
}

void GravitationSystem::update(float dt) {
    vector<GravityObject> gravity_objects;

    for (const auto &item: world->getEntities()){
        auto velocity = item->getComponent<PositionVelocity>();
        auto object = item->getComponent<PhysicalObject>();
        auto mass = item->getComponent<Mass>();

        if (!velocity || !mass) continue;
        gravity_objects.push_back(GravityObject{
            velocity, object, mass
        });
    }

    for (const auto &obj: gravity_objects){
        auto &velocity = *(obj.velocity);
        auto &object = *(obj.object);
        auto &mass = *(obj.mass);
        sf::Vector2f acceleration(0.f, 0.f);

        for (const auto &other_obj: gravity_objects) {
            if (&obj == &other_obj) continue;

            auto &otherVelocity = *(other_obj.velocity);
            auto &other_object = *(other_obj.object);
            auto &otherMass = *(other_obj.mass);

            sf::Vector2f force = calculateGravitationalForce(object.object->getPosition(), mass.mass,
                                                             other_object.object->getPosition(), otherMass.mass);
            acceleration += force / mass.mass;
        }

        velocity.x_vel += acceleration.x * dt * 60;
        velocity.y_vel += acceleration.y * dt * 60;
    }
}