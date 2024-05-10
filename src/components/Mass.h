#ifndef SPACESHOOTAN_MASS_H
#define SPACESHOOTAN_MASS_H

#include "utils/impl.h"

class Mass : public Component{
public:
    float mass;
    explicit Mass(float _mass) : mass(_mass) {}
};

#endif //SPACESHOOTAN_MASS_H
