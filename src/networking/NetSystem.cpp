#include "NetSystem.h"

NetSystem::NetSystem() = default;

void NetSystem::init(World *world) {
    log->debug("Net system initialization");
    this->world = world;

    sf::Socket::Status conn_res = networking::createWorker<networking::NetClient>(17302, "127.0.0.1");


    if (conn_res != sf::Socket::Done){
        log->info("Unable find the local server. New server will start on port 17302");
        networking::createWorker<networking::NetServer>(17302, "127.0.0.1");
    } else {
        world->addSystem<SetId>();
    }
    world->addSystem<Connection>();

}

void NetSystem::update(float dt) {
    if (networking::currentWorker == nullptr) return;

    std::optional<sf::Packet> input = networking::currentWorker->receive();
    if (input == std::nullopt) return;

    std::cout << input.value() << endl;

    auto packet = world->createEntity();
    packet->addComponent(make_shared<Packet>(input.value()));
    packet->addComponent(make_shared<GarbageMark>());

    auto networking = world->createEntity();
    networking->addComponent(make_shared<NetworkingC>(networking::currentWorker));

}
