#ifndef SPACESHOOTAN_SETID_H
#define SPACESHOOTAN_SETID_H


#include "utils/impl.h"
#include "SFML/Network/Packet.hpp"
#include "SFML/System/String.hpp"
#include "Packet.h"
#include "Networking.h"
#include "NetworkingC.h"

class SetId : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("PACKET")
            ->getLogger();
public:
    SetId();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_SETID_H
