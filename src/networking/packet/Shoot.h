#ifndef SPACESHOOTAN_SHOOT_H
#define SPACESHOOTAN_SHOOT_H

#include "utils/impl.h"
#include "SFML/Network/Packet.hpp"
#include "SFML/System/String.hpp"
#include "SFML/System/Vector2.hpp"
#include "Packet.h"
#include "Networking.h"
#include "RemotePlayer.h"
#include "PhysicalObject.h"
#include "PositionVelocity.h"
#include "LocalPlayer.h"
#include "Id.h"
#include "GraphicObject.h"
#include "NetworkingC.h"
#include "Mass.h"
#include "Health.h"
#include "WindowEvent.h"

class Shoot : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("PACK")
            ->getLogger();
public:
    Shoot();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_SHOOT_H
