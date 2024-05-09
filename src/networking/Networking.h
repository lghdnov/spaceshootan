#ifndef SPACESHOOTAN_NETWORKING_H
#define SPACESHOOTAN_NETWORKING_H

#include <optional>

#include "SFML/Network.hpp"
#include "utils/impl.h"
#include "sstream"

namespace netw{
    enum NetMode{
        SERVER, CLIENT
    };
}

class Networking {
private:
    logz::Logger* log = logz::LoggerBuilder::newLogger("NET")
            ->getLogger();
    sf::TcpListener listener;
    sf::TcpSocket socket;
    sf::IpAddress listnAddr;
    int listnPort;
    netw::NetMode mode = netw::NetMode::SERVER;


    std::optional<sf::Packet> processClientInput();
    std::optional<sf::Packet> processServerInput();
public:
    Networking();
    void runServer(int port, sf::IpAddress adr);
    std::optional<sf::Packet> getPacket();
};


#endif //SPACESHOOTAN_NETWORKING_H
