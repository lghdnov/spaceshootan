
#ifndef SPACESHOOTAN_GRAPHICOBJECT_H
#define SPACESHOOTAN_GRAPHICOBJECT_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <utility>

#include "utils/impl.h"

class GraphicObject: public Component{
public:
    shared_ptr<sf::Shape> object;
    explicit GraphicObject(shared_ptr<sf::Shape> _object) : object(std::move(_object)) {};
};

#endif //SPACESHOOTAN_GRAPHICOBJECT_H
