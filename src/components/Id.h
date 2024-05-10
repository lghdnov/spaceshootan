#ifndef SPACESHOOTAN_ID_H
#define SPACESHOOTAN_ID_H

#include "utils/impl.h"

class Id : public Component{
public:
    int id;
    explicit Id(int _id) : id(_id) {}
};

#endif //SPACESHOOTAN_ID_H
