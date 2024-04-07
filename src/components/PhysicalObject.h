//
// Created by dimasik on 07.04.24.
//

#ifndef SPACESHOOTAN_PHYSICALOBJECT_H
#define SPACESHOOTAN_PHYSICALOBJECT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "utils/impl.h"

class PhysicalObject: public Component{
public:
    shared_ptr<sf::Shape> object;
    explicit PhysicalObject(shared_ptr<sf::Shape> _object) : object(std::move(_object)) {};
};

#endif //SPACESHOOTAN_PHYSICALOBJECT_H
