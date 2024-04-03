#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Renderer.h"

static auto file = ofstream("logs.txt");

static auto log = logz::LoggerBuilder::newLogger("MAIN")
        ->addOut(&std::cout)
        ->addOut(&file)
        ->addStandardModifiers()
        ->getLogger();


int main(){

    log->info("Staring application...");

    World world;
    world.addSystem<Renderer>();

    world.init();

    while (true){
        world.update();
    }
}
