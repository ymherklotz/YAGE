# Entity Component System (ECS)

## Structure

### Entity

The `EntityManager` is the class that manages the entities, by allocating and
deleting them as necessary. The `Entity` itself is just a handle, and does not
contain any logic or data. It is just used to refer to the `Entity` when doing
operations on it.

### Components

These are just data that is associated with Entities, and it gets processed
by the Systems when these are updated. The systems only process a few components
at once, which separates the logic and makes it easy to develop the Systems and
Components orthogonally. 

### Systems

These process the Components and update their state. This completely separates
the data from the logic, and means that they can be tested independently. New
systems can be created by inheriting from the `BaseSystem`, which provides an
interface which then enables that system to be added to the main `Engine`
through different types of `Spaces`.

## Implementation

The Entity is just an `unsigned int`, which has a `typedef` called `Entity`,
which is also what all the functions return. 

The link between the components are managed by a templated `ComponentMapper`
class, that links every entity with it's component. This way it is also to find
out if an entity is part of a specific component, and that entity will never be
processed in the system that only targets that component, which makes it much
more efficient.
