#ifndef SPACESHOOTAN_GRAVITATIONSYSTEM_H
#define SPACESHOOTAN_GRAVITATIONSYSTEM_H

#include <cmath>

#include "SFML/System/Vector2.hpp"

#include "utils/impl.h"
#include "PositionVelocity.h"
#include "PhysicalObject.h"
#include "Mass.h"

class GravitationSystem : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("GRAVPHYSIC")
            ->getLogger();

public:
    GravitationSystem();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_GRAVITATIONSYSTEM_H
