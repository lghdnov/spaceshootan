#include <iostream>
#include <fstream>

#include "Renderer.h"
#include "PlayerController.h"
#include "GarbageCleaner.h"
#include "VelocitySystem.h"
#include "NetSystem.h"

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
    world.addSystem<PlayerController>();
    world.addSystem<VelocitySystem>();
    world.addSystem<Renderer>();
    world.addSystem<NetSystem>();

    world.addSystem<GarbageCleaner>();

    while (true){
        world.update();
    }
}
