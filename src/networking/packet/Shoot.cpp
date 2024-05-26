#include <cmath>
#include "Shoot.h"

Shoot::Shoot() = default;

void Shoot::init(World *world) {
    this->world = world;
}

void Shoot::update(float dt) {
    sf::String header = "shoot";

    shared_ptr<NetworkingC> networkingC;

    for (const auto &item: world->getEntities()){
        auto _networking = item->getComponent<NetworkingC>();
        if (_networking) networkingC = _networking;
    }

    for (const auto &item: world->getEntities()) {
        auto event = item->getComponent<WindowEvent>();
        if (!event) continue;
        if (event->event.type != sf::Event::MouseButtonPressed || event->event.mouseButton.button != sf::Mouse::Left)
            continue;

        sf::Packet shoot_packet;
        shoot_packet << header;

        networkingC->networking.worker->send(shoot_packet);
    }

    for (const auto &item: world->getEntities()) {
        auto _packet = item->getComponent<Packet>();
        if (!_packet) continue;

        sf::Packet packet;
        packet.append(_packet->packet.getData(), _packet->packet.getDataSize());

        sf::String header_;
        packet >> header_;
        if (header_ != header) continue;

        sf::Int32 id;
        packet >> id;

        for (const auto &item: world->getEntities()) {
            auto remote_player = item->getComponent<RemotePlayer>();
            auto physical = item->getComponent<PhysicalObject>();
            auto pos_vel = item->getComponent<PositionVelocity>();
            auto id_ = item->getComponent<Id>();

            if (!remote_player || !physical || !pos_vel || !id_) continue;
            if (id_->id != id) continue;

            float shoot_angle = (physical->object->getRotation() - 90) / (180 / (float)M_PI);
            float shoot_distance = 90.f;

            sf::Vector2f bullet_position = physical->object->getPosition();
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
}