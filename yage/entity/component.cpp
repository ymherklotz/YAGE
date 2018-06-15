#include "component.h"

GroupId BaseComponent::getGroup() {
    static GroupId group_id = group_id_counter_++;
    return group_id;
}
