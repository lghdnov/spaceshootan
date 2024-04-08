#ifndef SPACESHOOTAN_POSITIONVELOCITY_H
#define SPACESHOOTAN_POSITIONVELOCITY_H

#include "utils/impl.h"

class PositionVelocity : public Component{
public:
    float x_vel, y_vel;
    explicit PositionVelocity(float x, float y) : x_vel(x), y_vel(y) {}
};

#endif //SPACESHOOTAN_POSITIONVELOCITY_H
