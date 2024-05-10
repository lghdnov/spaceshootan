#ifndef SPACESHOOTAN_NETWORKINGC_H
#define SPACESHOOTAN_NETWORKINGC_H

#include "utils/impl.h"
#include "SFML/Network/Packet.hpp"
#include "Networking.h"

using namespace networking;

class NetworkingC : public Component{
public:
    explicit NetworkingC(Networking _networking): networking(_networking) {}
    Networking networking ;
};

#endif //SPACESHOOTAN_NETWORKINGC_H
