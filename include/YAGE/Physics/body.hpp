#ifndef YAGE_BODDY_HPP
#define YAGE_BODDY_HPP

#include <glm/glm.hpp>

class Body
{
private:
    glm::vec2 centerOfMass_;
    double mass_;
    
public:
    virtual ~Body();
    
};

#endif
