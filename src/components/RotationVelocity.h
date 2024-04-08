#ifndef SPACESHOOTAN_ROTATIONVELOCITY_H
#define SPACESHOOTAN_ROTATIONVELOCITY_H

#include "utils/impl.h"

class RotationVelocity : public Component{
public:
    float velocity;
    explicit RotationVelocity(float _velocity) : velocity(_velocity) {}
};

#endif //SPACESHOOTAN_ROTATIONVELOCITY_H
