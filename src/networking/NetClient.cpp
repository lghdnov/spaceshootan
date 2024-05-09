#include "Netw.h"

using namespace networking;

NetClient::NetClient(int port, sf::IpAddress adr):
port(port), adr(adr)
{}

sf::Socket::Status NetClient::init() {
    auto conn_res = connection.connect(adr, port);
    connection.setBlocking(false);
    return conn_res;
}

void NetClient::send(sf::Packet packet) {
    connection.send(packet);
}

std::optional<sf::Packet> NetClient::receive() {
    sf::Packet packet;
    return (connection.receive(packet) == sf::Socket::Done) ?
        std::optional<sf::Packet>(std::move(packet)) :
        std::nullopt;
}
