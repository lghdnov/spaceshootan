#ifndef SPACESHOOTAN_NETSYSTEM_H
#define SPACESHOOTAN_NETSYSTEM_H

#include "utils/impl.h"
#include "Networking.h"
#include "packet/Connection.h"
#include "GarbageMark.h"
#include "packet/SetId.h"
#include "NetworkingC.h"

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
