#include "Position.h"


Position::Position() = default;

void Position::init(World *world) {
    log->debug("Position packet handler initialization");
    this->world = world;
}

void Position::update(float dt) {

    sf::String header = "settrans";

    shared_ptr<NetworkingC> networkingC;

    for (const auto &item: world->getEntities()){
        auto _networking = item->getComponent<NetworkingC>();
        if (_networking) networkingC = _networking;
    }

    static bool is_first_frame = true;
    static float prev_rotation_vel;

    for (const auto &item: world->getEntities()){
        auto local_player = item->getComponent<LocalPlayer>();
        auto physical = item->getComponent<PhysicalObject>();
        auto position_vel = item->getComponent<PositionVelocity>();
        auto rotation_vel = item->getComponent<RotationVelocity>();

        if (!local_player || !physical || !position_vel || !rotation_vel) continue;

        if (is_first_frame){
            is_first_frame = false;
            prev_rotation_vel = rotation_vel->velocity;
            break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ||
            prev_rotation_vel != rotation_vel->velocity)
        {
            sf::Packet packet;
            packet << header
            << physical->object->getPosition().x << physical->object->getPosition().y
            << position_vel->x_vel << position_vel->y_vel
            << physical->object->getRotation() << rotation_vel->velocity;

            networkingC->networking.worker->send(packet);
        }
    }


    for (const auto &item: world->getEntities()) {
        auto _packet = item->getComponent<Packet>();
        if (!_packet) continue;

        sf::Packet packet;
        packet.append(_packet->packet.getData(), _packet->packet.getDataSize());

        sf::String header_;
        packet >> header_;
        if (header_ != header) continue;

        sf::Vector2f position;
        sf::Vector2f velocity;
        float rotation;
        float rotation_v;
        sf::Int32 id;

        packet >> position.x >> position.y >> velocity.x >> velocity.y >> rotation >> rotation_v >> id;

        for (const auto &item: world->getEntities()){
            auto remote_player = item->getComponent<RemotePlayer>();
            auto physical = item->getComponent<PhysicalObject>();
            auto position_vel = item->getComponent<PositionVelocity>();
            auto rotation_vel = item->getComponent<RotationVelocity>();
            auto id_ = item->getComponent<Id>();

            if (!remote_player || !physical || !position_vel || !rotation_vel || !id_) continue;
            if (id_->id != id) continue;

            physical->object->setPosition(position);
            physical->object->setRotation(rotation);
            position_vel->x_vel = velocity.x;
            position_vel->y_vel = velocity.y;
            rotation_vel->velocity = rotation_v;

            return;
        }

        auto player_shape = make_shared<sf::ConvexShape>();
        player_shape->setFillColor(sf::Color::Black);
        player_shape->setPointCount(3);
        player_shape->setPoint(0, sf::Vector2f(0, -40));
        player_shape->setPoint(1, sf::Vector2f(20, 20));
        player_shape->setPoint(2, sf::Vector2f (-20, 20));
        player_shape->setPosition(position);
        player_shape->setRotation(rotation);

        auto new_player = world->createEntity();
        new_player->addComponent(make_shared<RemotePlayer>());
        new_player->addComponent(make_shared<GraphicObject>(player_shape));
        new_player->addComponent(make_shared<PhysicalObject>(player_shape));
        new_player->addComponent(make_shared<PositionVelocity>(velocity.x, velocity.y));
        new_player->addComponent(make_shared<RotationVelocity>(rotation_v));
        new_player->addComponent(make_shared<Id>(id));
        new_player->addComponent(make_shared<Mass>(100));

    }
}