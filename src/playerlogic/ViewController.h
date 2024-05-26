#ifndef SPACESHOOTAN_VIEWCONTROLLER_H
#define SPACESHOOTAN_VIEWCONTROLLER_H


#include "PhysicalObject.h"
#include "LocalPlayer.h"
#include "Window.h"

class ViewController : public System{
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("PLAYER")
            ->getLogger();

    sf::View view;

public:
    ViewController();
    void init(World* world) override;
    void update(float dt) override;
};

#endif //SPACESHOOTAN_VIEWCONTROLLER_H
