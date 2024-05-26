#ifndef SPACESHOOTAN_HEALTH_H
#define SPACESHOOTAN_HEALTH_H

#include "utils/impl.h"

class Health : public Component{
public:
    float health;
    explicit Health(float _health): health(_health){}
};

#endif //SPACESHOOTAN_HEALTH_H
