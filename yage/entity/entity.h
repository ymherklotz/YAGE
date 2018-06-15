#include <bitset>
#include <vector>

/** 
 * The entity is currently just an unsigned integer, which may change to a
 * class in the future.
 */
typedef unsigned int Entity;

/** 
 * The component mask represents all the components that the entity is
 * currently attached to.
 */
typedef std::bitset<64> ComponentMask;

class EntityManager;

class BaseSystem;

template <typename T>
class System;

class BaseComponent;

template <typename T>
class Component;

class BaseComponentGroup;

template <typename T>
class ComponentGroup;

/** 
 * Has to keep track of all the different entities and their current state.
 * 
 * The key actions on an Entity are: deleting, creating.
 */
class EntityManager
{
public:
    Entity createEntity();
    EntityManager &deleteEntity(Entity entity);
    void addComponent(Entity entity, BaseComponent *component);

private:
    Entity next_entity_;

    std::vector<BaseComponentGroup *> component_group_;
    std::vector<ComponentMask> component_masks_;
};
