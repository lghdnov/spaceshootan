#ifndef SPACESHOOTAN_CONNECTION_H
#define SPACESHOOTAN_CONNECTION_H

#include "utils/impl.h"
#include "SFML/Network/Packet.hpp"
#include "SFML/System/String.hpp"
#include "Packet.h"

class Connection : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("PACK")
            ->getLogger();
public:
    Connection();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_CONNECTION_H
