#ifndef SPACESHOOTAN_VELOCITYSYSTEM_H
#define SPACESHOOTAN_VELOCITYSYSTEM_H

#include "utils/impl.h"
#include "PositionVelocity.h"
#include "RotationVelocity.h"
#include "PhysicalObject.h"

class VelocitySystem : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("VELPHYSIC")
            ->getLogger();

    void processRotations(float dt);
    void processMovements(float dt);
public:
    VelocitySystem();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_VELOCITYSYSTEM_H
