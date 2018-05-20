/** ---------------------------------------------------------------------------
 * @file: entity.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <vector>
#include <memory>

namespace yage
{

class Space;
class ComponentGroup;

typedef unsigned int Entity;

/** Manages entities in a space.
 */
class EntityManager
{
public:
    /** Default instance of an EntityManager.
     */
    EntityManager() = default;

    /** Creates an instance of the entity manager, which refers back to the
     * space it was created in and belongs to.
     *
     * @param space Current space that the EntityManager belongs to.
     */
    EntityManager(Space *space);

    /** Creates an instance of the entitiy manager with an initial size.
     *
     * @param space Current space that the EntityManager belongs to.  @param n
     * Initial size of the EntityManager.
     */
    EntityManager(Space *space, std::size_t n);

    /** Creates an Entity and returns the handle to the entity, which can then
     * be used by the user to do operations on it.
     *
     * @return The handle to the entity that was created in the space.
     */
    Entity createEntity();

    /** Delete an entity.
     */
    void deleteEntity(Entity entity);

private:
    /** The next available handle to give to the user.
     */
    Entity next_entity_ = 0;

    /** The space that the entity manager belongs to.
     */
    Space *space_ = nullptr;

    /** The entities in the current space.
     */
    std::vector<Entity> entities_;

    /** Component list of different component groups, that then contain the
     * different components for the entities.
     */
    std::vector<std::unique_ptr<ComponentGroup>> components;
};

/** Base component used to store components.
 *
 * Should not be inherited from when declaring a new component. Instead, the
 * Component<Derived> should be used.
 */
class BaseComponent {
public:
    /** Group used to register a specific component internally with the entity
     * manager.
     */
    typedef unsigned Group;

protected:
    static Group group_id_counter_;
};

/** The main component that is used to make a component from a defined struct.
 *
 * A component should only be declared as a struct and should not contain any
 * data itself.
 */
template <typename Derived>
class Component : public BaseComponent {
private:
    friend class EntityManager;

    BaseComponent::Group group();
};

/** Contains a list of all components that belong to a sepecific group, these
 * are then stored in the main entity manager.
 */
class ComponentGroup {
private:
    friend class EntityManager;

    std::vector<BaseComponent *> components_;
};

// Template definitions

template <typename Derived>
BaseComponent::Group Component<Derived>::group()
{
    static Group group_id = group_id_counter_++;
    return group_id;
}

} // namespace yage
