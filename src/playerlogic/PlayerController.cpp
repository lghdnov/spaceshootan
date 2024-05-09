#include "PlayerController.h"

PlayerController::PlayerController() = default;

void PlayerController::init(World* world) {
    log->debug("Player controller initialization");
    this->world = world;
    auto player = world->createEntity();

    auto playerShape = make_shared<sf::ConvexShape>();
    playerShape->setFillColor(sf::Color::Black);
    playerShape->setPointCount(3);
    playerShape->setPoint(0, sf::Vector2f(0, -40));
    playerShape->setPoint(1, sf::Vector2f(20, 20));
    playerShape->setPoint(2, sf::Vector2f (-20, 20));
    playerShape->setPosition(500, 500);

    player->addComponent(make_shared<GraphicObject>(playerShape));
    player->addComponent(make_shared<PhysicalObject>(playerShape));
    player->addComponent(make_shared<LocalPlayer>());
    player->addComponent(make_shared<RotationVelocity>(0));
    player->addComponent(make_shared<PositionVelocity>(0 ,0));

}

void PlayerController::update(float dt) {
    shared_ptr<WindowC> window_c = nullptr;
    for (const auto &item: world->getEntities()){
        window_c = item->getComponent<WindowC>();
        if (window_c) break;
    }

    for (const auto &item: world->getEntities()){
        auto physic_object = item->getComponent<PhysicalObject>();
        auto player = item->getComponent<LocalPlayer>();
        auto pos_vel = item->getComponent<PositionVelocity>();
        auto rot_vel = item->getComponent<RotationVelocity>();
        if (!physic_object || !player || !pos_vel || !rot_vel) continue;

        sf::Vector2<int> mouse_pos = sf::Mouse::getPosition(window_c->window);

        float dx = (float)mouse_pos.x - physic_object->object->getPosition().x;
        float dy = (float)mouse_pos.y - physic_object->object->getPosition().y;
        float current_rotation = physic_object->object->getRotation();

        float target_rotation = atan2(dx, dy) * (180 / (float)M_PI) * -1 + 180;
        float rotation_velocity;


        float delta_rotation = target_rotation - current_rotation;

        if (abs((int)delta_rotation) > 3) {
            rotation_velocity = delta_rotation > 0 ? 4 : -4;
        } else rotation_velocity = 0;

        if (current_rotation - target_rotation > 180) rotation_velocity = 4;
        if (target_rotation - current_rotation > 180) rotation_velocity = -4;

        rot_vel->velocity = rotation_velocity;



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
            float move_angle = (current_rotation - 90) / (180 / (float)M_PI);

            pos_vel->x_vel += (float)(cos(move_angle) * 0.3);
            pos_vel->y_vel += (float)(sin(move_angle) * 0.3);
        }
    }
}