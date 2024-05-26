#include "PlayerController.h"

void create_player(World* world){
    auto player = world->createEntity();

    auto playerShape = make_shared<sf::ConvexShape>();
    playerShape->setFillColor(sf::Color::Black);
    playerShape->setOutlineThickness(2);
    playerShape->setOutlineColor(sf::Color(0, 10, 150));
    playerShape->setPointCount(3);
    playerShape->setPoint(0, sf::Vector2f(0, -40));
    playerShape->setPoint(1, sf::Vector2f(20, 20));
    playerShape->setPoint(2, sf::Vector2f (-20, 20));
    playerShape->setPosition(200, 500);

    player->addComponent(make_shared<GraphicObject>(playerShape));
    player->addComponent(make_shared<PhysicalObject>(playerShape));
    player->addComponent(make_shared<LocalPlayer>());
    player->addComponent(make_shared<RotationVelocity>(0));
    player->addComponent(make_shared<PositionVelocity>(0 ,5.6));
    player->addComponent(make_shared<Mass>(1));
    player->addComponent(make_shared<Health>(100));
}

PlayerController::PlayerController() = default;

void PlayerController::init(World* world) {
    log->debug("Player controller initialization");
    this->world = world;
    auto player = world->createEntity();

    create_player(world);
}

void PlayerController::update(float dt) {
    bool is_player_detected = false;
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
        is_player_detected = true;

        sf::Vector2<int> mouse_pos = sf::Mouse::getPosition(window_c->window);

        sf::View view = window_c->window.getView();

        sf::Vector2f mouse_world_pos = window_c->window.mapPixelToCoords(mouse_pos, view);

        float dx = mouse_world_pos.x - physic_object->object->getPosition().x;
        float dy = mouse_world_pos.y - physic_object->object->getPosition().y;
        float current_rotation = physic_object->object->getRotation();

        float target_rotation = atan2(dx, dy) * (180 / (float)M_PI) * -1 + 180;
        float rotation_velocity;


        float delta_rotation = target_rotation - current_rotation;

        if (abs((int)delta_rotation) > 3) {
            rotation_velocity = delta_rotation > 0 ? 4 : -4;
        } else rotation_velocity = 0;

        if (current_rotation - target_rotation > 180) rotation_velocity = 4;
        if (target_rotation - current_rotation > 180) rotation_velocity = -4;

        if (window_c->window.hasFocus())
            rot_vel->velocity = rotation_velocity;



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && window_c->window.hasFocus()){
            float move_angle = (current_rotation - 90) / (180 / (float)M_PI);

            pos_vel->x_vel += (float)(cos(move_angle) * 0.3);
            pos_vel->y_vel += (float)(sin(move_angle) * 0.3);
        }

        for (const auto &item: world->getEntities()){
            auto event = item->getComponent<WindowEvent>();
            if (!event) continue;

            if (event->event.type != sf::Event::MouseButtonPressed || event->event.mouseButton.button != sf::Mouse::Left)
                continue;

            float shoot_angle = (current_rotation - 90) / (180 / (float)M_PI);
            float shoot_distance = 90.f;

            sf::Vector2f bullet_position = physic_object->object->getPosition();
            bullet_position.x += shoot_distance * cos(shoot_angle);
            bullet_position.y += shoot_distance * sin(shoot_angle);

            auto bullet_object = make_shared<sf::CircleShape>();
            bullet_object->setFillColor(sf::Color(80, 10 ,0));
            bullet_object->setRadius(10);
            bullet_object->setOrigin(bullet_object->getRadius(), bullet_object->getRadius());
            bullet_object->setPosition(bullet_position);

            auto bullet_pos_vel = make_shared<PositionVelocity>(pos_vel->x_vel, pos_vel->y_vel);
            bullet_pos_vel->x_vel += (float)(cos(shoot_angle) * 10);
            bullet_pos_vel->y_vel += (float)(sin(shoot_angle) * 10);

            auto bullet = world->createEntity();
            bullet->addComponent(make_shared<PhysicalObject>(bullet_object));
            bullet->addComponent(make_shared<GraphicObject>(bullet_object));
            bullet->addComponent(make_shared<Mass>(1));
            bullet->addComponent(make_shared<Health>(20));
            bullet->addComponent(bullet_pos_vel);

        }

    }

    static float respawn_time = 0;
    if (!is_player_detected){
        respawn_time += dt;
        if (respawn_time >= 3){
            create_player(world);
            respawn_time = 0;
        }
    }
}