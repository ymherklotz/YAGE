#pragma once

#include <map>

#include "entitymanager.h"

namespace yage
{

template <typename CompT>
class ComponentMapper
{
private:
    std::map<Entity, CompT> map_;
};

} // namespace yage
