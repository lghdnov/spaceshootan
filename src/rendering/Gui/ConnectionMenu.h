#ifndef SPACESHOOTAN_CONNECTIONMENU_H
#define SPACESHOOTAN_CONNECTIONMENU_H

#include "utils/impl.h"
#include "RenderMethod.h"
#include "NetworkingC.h"
#include "imgui-SFML.h"
#include "imgui.h"

class ConnectionMenu : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("RENDERER")
            ->getLogger();
public:
    ConnectionMenu();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_CONNECTIONMENU_H
