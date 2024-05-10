#ifndef SPACESHOOTAN_LEVELGENERATOR_H
#define SPACESHOOTAN_LEVELGENERATOR_H

#include "utils/impl.h"
#include "PhysicalObject.h"
#include "GraphicObject.h"
#include "PositionVelocity.h"
#include "RotationVelocity.h"
#include "Mass.h"

class LevelGenerator : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("LEVEL")
            ->getLogger();
public:
    LevelGenerator();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_LEVELGENERATOR_H
