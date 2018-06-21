#include <yage/entity/component.h>
#include <yage/entity/entity.h>
#include <yage/entity/system.h>

using namespace yage;

#include <iostream>
#include <vector>

struct Position : public Component<Position> {
    double x;
    double y;

    Position(double x_, double y_) : x(x_), y(y_) {}
};

struct Size : public Component<Size> {
    double width;
    double height;

    Size(double w, double h) : width(w), height(h) {}
};

class MovementSystem : public System<MovementSystem>
{
public:
    void update(double dt, EntityManager &em) override
    {
        for (auto &&x : em.component_masks_) {
            if(x[1] == 1) {
                std::cout << "Found size: ";
            }
        }
    }
};

int main()
{
    EntityManager em;
    Position p1(1, 2);
    Position p2(2, 1);
    Size s1(5, 5);
    Entity e1 = em.create_entity();
    Entity e2 = em.create_entity();
    std::cout << "e1: " << e1 << ", e2: " << e2 << "\n";

    MovementSystem s;

    em.add_component(e1, &p1).add_component(e2, &p2).add_component(e2, &s1);

    s.update(60, em);
}
