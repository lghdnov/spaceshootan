#include "NetSystem.h"

NetSystem::NetSystem() = default;

void NetSystem::init(World *world) {
    log->debug("Net system initialization");
    this->world = world;

    networking::Networking networking = networking::Networking();
    auto networkingC = make_shared<NetworkingC>(networking);
    auto networking_entity = world->createEntity();
    networking_entity->addComponent(networkingC);


    log->info("New server will start on port 17302");
    networkingC->networking.createWorker<networking::NetServer>(17302, "127.0.0.1");

    world->addSystem<SetId>();
    world->addSystem<Connection>();
    world->addSystem<Position>();
    world->addSystem<Shoot>();

}

void NetSystem::update(float dt) {

    for (const auto &item: world->getEntities()){
        auto networkingC = item->getComponent<NetworkingC>();

        if (!networkingC) continue;

        std::optional<sf::Packet> input = networkingC->networking.worker->receive();
        if (input == std::nullopt) continue;

        auto packet = world->createEntity();
        packet->addComponent(make_shared<Packet>(input.value()));
        packet->addComponent(make_shared<GarbageMark>());
    }

}
