#ifndef SPACESHOOTAN_RENDERMETHOD_H
#define SPACESHOOTAN_RENDERMETHOD_H

#include <functional>
#include <utility>

#include "utils/impl.h"

class RenderMethod : public Component{
public:
    std::function<void(float, World*)> method;
    explicit RenderMethod(std::function<void(float, World*)> _method): method(std::move(_method)){}
};

#endif //SPACESHOOTAN_RENDERMETHOD_H
