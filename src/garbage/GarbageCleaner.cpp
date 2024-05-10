#include <sstream>
#include "GarbageCleaner.h"

GarbageCleaner::GarbageCleaner() = default;

void GarbageCleaner::init(World *world) {
    log->debug("Garbage cleaner initialization");

    this->world = world;

}

void GarbageCleaner::update(float dt) {
    int remove_counter = 0;
    auto &entities = world->getEntities();

    for (auto it = entities.begin(); it != entities.end(); ) {
        auto &item = *it;
        auto mark = item->getComponent<GarbageMark>();

        if (!mark) {
            ++it;
        } else {
            it = entities.erase(it);
            remove_counter++;
        }
    }
//    if (remove_counter > 0){
//        stringstream log_str;
//        log_str << "Garbage cleaner removed " << remove_counter << " entities on this frame";
//        log->debug(log_str.str());
//    }
}