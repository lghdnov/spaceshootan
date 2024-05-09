#ifndef SPACESHOOTAN_PACKET_H
#define SPACESHOOTAN_PACKET_H

#include "utils/impl.h"
#include "SFML/Network/Packet.hpp"

class Packet : public Component{
public:
    Packet() = default;
    sf::Packet packet;
};

#endif //SPACESHOOTAN_PACKET_H
