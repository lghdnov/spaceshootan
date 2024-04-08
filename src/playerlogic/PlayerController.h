#ifndef SPACESHOOTAN_PLAYERCONTROLLER_H
#define SPACESHOOTAN_PLAYERCONTROLLER_H

#include <memory>
#include <cmath>

#include "GraphicObject.h"
#include "PhysicalObject.h"
#include "LocalPlayer.h"
#include "GarbageMark.h"
#include "Window.h"
#include "PositionVelocity.h"
#include "RotationVelocity.h"

class PlayerController : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("PLAYER")
            ->getLogger();

public:
    PlayerController();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_PLAYERCONTROLLER_H
