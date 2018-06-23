#include "component.h"

#include <memory>

namespace yage
{

GroupId BaseComponent::group_id_counter_ = 0;

ComponentGroup &ComponentGroup::add(std::unique_ptr<BaseComponent> &&component)
{
    components_.push_back(std::move(component));
    return *this;
}

ComponentGroup::Container::iterator ComponentGroup::begin() {
    return components_.begin();
}

ComponentGroup::Container::iterator ComponentGroup::end() {
    return components_.end();
}

} // namespace yage
