#include <yage/entity/space.h>

#include <yage/yage.h>

int main()
{
    yage::Space space;
    auto entity  = space.createEntity();
    auto entity2 = space.createEntity();
    auto entity3 = space.createEntity();
    auto entity4 = space.createEntity();

    yLogInfo << "Entity 1: " << entity;
    yLogInfo << "Entity 3: " << entity3;
    yLogInfo << "Entity 2: " << entity2;
    yLogInfo << "Entity 4: " << entity4;

    return 0;
}
