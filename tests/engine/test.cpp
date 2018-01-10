#include <yage/engine/space.h>

#include <yage/yage.h>

int main()
{
    yage::Space space;
    auto entity = space.createEntity();
    auto entity2 = space.createEntity();
    auto entity3 = space.createEntity();

    yLogInfo << "Entity 1: " << entity;
    yLogInfo << "Entity 3: " << entity3;
    yLogInfo << "Entity 2: " << entity2;
    return 0;
}
