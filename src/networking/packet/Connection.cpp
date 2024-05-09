#include "Connection.h"


Connection::Connection() = default;

void Connection::init(World *world) {
    log->debug("Connection packet handler initialization");
    this->world = world;
}

void Connection::update(float dt) {
    for (const auto &item: world->getEntities()) {
        auto packet = item->getComponent<Packet>();
        if (!packet) continue;

        sf::String header;
        packet->packet >> header;
        if (header != "connect") continue;

        log->debug("new connection");
    }
}