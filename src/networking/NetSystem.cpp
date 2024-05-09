#include "NetSystem.h"

NetSystem::NetSystem() = default;

void NetSystem::init(World *world) {
    log->debug("Net system initialization");
    this->world = world;

    world->addSystem<Connection>();

    if (networking::createWorker<networking::NetClient>(17302, "127.0.0.1") != sf::Socket::Done){
        log->info("Unable find the local server. New server will start on port 17302");
        networking::createWorker<networking::NetServer>(17302, "127.0.0.1");
    }
}

void NetSystem::update(float dt) {
    if (networking::currentWorker == nullptr) return;

    std::optional<sf::Packet> input = networking::currentWorker->receive();
    if (input == std::nullopt) return;


}
