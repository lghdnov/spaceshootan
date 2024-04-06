#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Renderer.h"

//static auto log = logz::LoggerBuilder::newLogger("MAIN")
//        ->addOut(&std::cout)
//        ->addOut(&file)
//        ->getLogger();


int main(){
    auto file = ofstream("logs.txt", std::ios::out | std::ios::app);
    logz::Logger::addGlobalOut(&file);
    logz::Logger::addGlobalOut(&std::cout);

    auto log = logz::LoggerBuilder::newLogger("MAIN")
            ->getLogger();

    log->info("Staring application...");

    World world;
    world.addSystem<Renderer>();

    world.init();

    while (true){
        world.update();
    }
}
