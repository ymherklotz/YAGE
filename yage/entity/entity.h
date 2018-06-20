#include <bitset>
#include <vector>

namespace yage {

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
    Entity create_entity();
    EntityManager &delete_entity(Entity entity);
    bool is_valid(Entity entity) const;
    void add_component(Entity entity, BaseComponent *component);

private:
    Entity update_next_entity();

    Entity next_entity_;

    std::vector<BaseComponentGroup *> component_group_;
    std::vector<ComponentMask> component_masks_;
    std::vector<Entity> deleted_;
};

} // namespace yage
