#ifndef SPACESHOOTAN_NETSYSTEM_H
#define SPACESHOOTAN_NETSYSTEM_H

#include "utils/impl.h"
#include "Netw.h"
#include "packet/Connection.h"

class NetSystem : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("NETSYS")
            ->getLogger();
public:
    NetSystem();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_NETSYSTEM_H
