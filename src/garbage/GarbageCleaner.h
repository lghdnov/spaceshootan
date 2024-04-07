#ifndef SPACESHOOTAN_GARBAGECLEANER_H
#define SPACESHOOTAN_GARBAGECLEANER_H

#include "utils/impl.h"
#include "GarbageMark.h"

class GarbageCleaner : public System {
private:
    World* world = nullptr;
    logz::Logger* log = logz::LoggerBuilder::newLogger("GARBAGER")
            ->getLogger();

public:
    GarbageCleaner();
    void init(World* world) override;
    void update(float dt) override;
};


#endif //SPACESHOOTAN_GARBAGECLEANER_H
