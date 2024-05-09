#include "Netw.h"
#include "iostream"

using namespace networking;
using namespace std;

NetServer::NetServer(int port, sf::IpAddress adr):
port(port), adr(adr), connections()
{
    listener.setBlocking(false);
    last_connection = new sf::TcpSocket();
    last_connection->setBlocking(false);
}

sf::Socket::Status NetServer::init() {
    return listener.listen(port);
}

void NetServer::send(sf::Packet packet) {
    for (const auto &connection: connections){
        connection->send(packet);
    }
}

std::optional<sf::Packet> NetServer::receive() {

    if (listener.accept(*last_connection) == sf::Socket::Done) {
        connections.push_back(last_connection);
        last_connection = new sf::TcpSocket();
        last_connection->setBlocking(false);
    }

    sf::Packet packet;
    for (const auto &connection: connections){
        if (connection->receive(packet) == sf::Socket::Done){
            for (const auto &connection_: connections){
                if (connection_ != connection)
                    connection_->send(packet);
            }

            return packet;
        }
    }
    return std::nullopt;
}