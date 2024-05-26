#ifndef SPACESHOOTAN_EXPLOSIONPARTICLE_H
#define SPACESHOOTAN_EXPLOSIONPARTICLE_H

#include "utils/impl.h"

enum ExplosionParticleType{
    SMOKE, WAVE
};

class ExplosionParticle : public Component{
public:
    int animStep;
    ExplosionParticleType type;
    ExplosionParticle(ExplosionParticleType _type, int _animStep):
    type(_type), animStep(_animStep){};
};

#endif //SPACESHOOTAN_EXPLOSIONPARTICLE_H
