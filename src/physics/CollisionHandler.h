#ifndef SPACESHOOTAN_COLLISIONHANDLER_H
#define SPACESHOOTAN_COLLISIONHANDLER_H

#include "utils/impl.h"
#include "PhysicalObject.h"
#include "Health.h"

class CollisionHandler : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("COLLPHYSIC")
            ->getLogger();
public:
    CollisionHandler();
    void init(World* world) override;
    void update(float dt) override;

};


#endif //SPACESHOOTAN_COLLISIONHANDLER_H
