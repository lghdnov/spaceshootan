#include <iostream>
#include <fstream>

#include "rendering/Renderer.h"
#include "playerlogic/PlayerController.h"
#include "garbage/GarbageCleaner.h"
#include "physics/VelocitySystem.h"
#include "networking/NetSystem.h"
#include "level/LevelGenerator.h"
#include "physics/GravitationSystem.h"



using namespace std;
using namespace logz;

int main(){
    auto file = ofstream("logs.txt", ios::out | ios::app);
    Logger::addGlobalOut(&file);
    Logger::addGlobalOut(&cout);

    auto log = LoggerBuilder::newLogger("MAIN")
            ->getLogger();

    log->info("Staring application...");

    World world;
    world.addSystem<LevelGenerator>();
    world.addSystem<PlayerController>();
    world.addSystem<GravitationSystem>();
    world.addSystem<VelocitySystem>();
    world.addSystem<Renderer>();
    world.addSystem<NetSystem>();

    world.addSystem<GarbageCleaner>();

    while (true){
        world.update();
    }
}
