#pragma once

#include "entity.h"

namespace yage
{

class BaseSystem
{
public:
    virtual void update(double dt, EntityManager &em) = 0;
};

template <typename T>
class System : public BaseSystem
{
protected:
    ComponentMask active_mask_;
};

} // namespace yage
