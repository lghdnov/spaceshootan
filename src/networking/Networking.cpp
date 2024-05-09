#include "Networking.h"

Networking::Networking() = default;

void Networking::runServer(int port, sf::IpAddress adr) {
    stringstream log_str;
    log_str << "Server starts on " << adr.toString() << " : " << port;
    log->info(log_str.str());

    listnPort = port;
    listnAddr = adr;

    listener.setBlocking(false);////////////
    mode = netw::NetMode::SERVER;
}

std::optional<sf::Packet> Networking::getPacket() {


    std::optional<sf::Packet> packet;

    switch (mode) {
        case netw::SERVER:
            packet = processServerInput();
            break;
        case netw::CLIENT:
            packet = processClientInput();
            break;
    }

    return packet;
}

std::optional<sf::Packet> Networking::processServerInput() {
    if (socket.getRemotePort() == 0){
        listener.listen(listnPort, listnAddr);
        if (listener.accept(socket) != sf::Socket::Done)
            return std::nullopt;

        socket.setBlocking(false);
    }

    sf::Packet packet;
    if (socket.receive(packet) == sf::Socket::Done)
        return packet;
    else return std::nullopt;
}

std::optional<sf::Packet> Networking::processClientInput() {

}