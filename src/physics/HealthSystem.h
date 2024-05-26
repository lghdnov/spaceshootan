#ifndef SPACESHOOTAN_HEALTHSYSTEM_H
#define SPACESHOOTAN_HEALTHSYSTEM_H

#include <random>

#include "utils/impl.h"

#include "Health.h"
#include "PhysicalObject.h"
#include "GarbageMark.h"
#include "GraphicObject.h"
#include "ExplosionParticle.h"

class HealthSystem : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("HEALTHPHYSIC")
            ->getLogger();
public:
    HealthSystem();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_HEALTHSYSTEM_H
