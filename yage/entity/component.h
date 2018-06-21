#pragma once

#include <bitset>
#include <memory>
#include <vector>

namespace yage
{

/**
 * The component mask represents all the components that the entity is
 * currently attached to.
 */
typedef std::bitset<64> ComponentMask;

typedef unsigned int GroupId;

class BaseComponent
{
protected:
    virtual GroupId getGroup() = 0;
    static GroupId group_id_counter_;

private:
    friend class EntityManager;
};

template <typename T>
class Component : public BaseComponent
{
    GroupId getGroup() override;
};

class ComponentGroup
{
public:
    std::vector<std::unique_ptr<BaseComponent>> components_;
};

template <typename T>
GroupId Component<T>::getGroup()
{
    static GroupId group_id = group_id_counter_++;
    return group_id;
}

} // namespace yage
