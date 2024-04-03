#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "Renderer.h"
#include "logger.h"

auto file_ = ofstream("logs.txt");

auto log_ = logz::LoggerBuilder::newLogger("MAIN")
        ->addOut(&std::cout)
        ->addOut(&file_)
        ->addStandardModifiers()
        ->getLogger();


int main(){

    log_->info("Staring application...");

    World world;
    world.addSystem<Renderer>();

    world.init();

    while (true){
        world.update();
    }
}
