#include "Connection.h"


Connection::Connection() = default;

void Connection::init(World *world) {
    log->debug("Connection packet handler initialization");
    this->world = world;
}

void Connection::update(float dt) {

    for (const auto &item: world->getEntities()) {
        auto _packet = item->getComponent<Packet>();
        if (!_packet) continue;

        sf::Packet packet;
        packet.append(_packet->packet.getData(), _packet->packet.getDataSize());

        sf::String header;
        packet >> header;
        if (header != "connect") continue;
        log->debug("New connection");

    }
}