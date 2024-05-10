#include "Networking.h"
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

    sf::Int32 id = 0;
    packet << id;

    for (const auto &connection: connections){
        connection->send(packet);
    }
}

std::optional<sf::Packet> NetServer::receive() {

    static int connections_counter = 1;

    if (listener.accept(*last_connection) == sf::Socket::Done) {
        connections.push_back(last_connection);

        sf::Packet set_id_packet;
        sf::String set_id_header = "setid";
        sf::Int32 id = connections_counter;

        set_id_packet << set_id_header << id;
        last_connection->send(set_id_packet);

        connections_counter++;

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

void NetServer::setId(int) {}

NetServer::~NetServer() {
    std::cout << "destro" << std::endl;
}