#include "SetId.h"

SetId::SetId() = default;

void SetId::init(World *world) {
    log->debug("SetId packet handler initialization");
    this->world = world;
}

void SetId::update(float dt) {

    shared_ptr<NetworkingC> networking;

    for (const auto &item: world->getEntities()){
        auto _networking = item->getComponent<NetworkingC>();
        if (_networking) networking = _networking;
    }

    for (const auto &item: world->getEntities()) {
        auto _packet = item->getComponent<Packet>();
        if (!_packet) continue;

        sf::Packet packet;
        packet.append(_packet->packet.getData(), _packet->packet.getDataSize());

        sf::String header;
        packet >> header;
        if (header != "setid") continue;

        sf::Int32 id;
        packet >> id;

        networking->worker->setId(id);

        sf::Packet connection_packet;
        sf::String connection_header = "connect";
        connection_packet << connection_header;
        networking->worker->send(connection_packet);
    }
}