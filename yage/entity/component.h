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
private:
    GroupId getGroup() override;
};

class ComponentGroup
{
public:
    typedef std::vector<std::unique_ptr<BaseComponent>> Container;

    ComponentGroup &add(std::unique_ptr<BaseComponent> &&component);
    Container::iterator begin();
    Container::iterator end();

private:
    Container components_;
};

template <typename T>
GroupId Component<T>::getGroup()
{
    static GroupId group_id = group_id_counter_++;
    return group_id;
}

} // namespace yage
