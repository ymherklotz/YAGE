#include <yage/entity/component.h>
#include <yage/entity/entity.h>
#include <yage/entity/system.h>

using namespace yage;

#include <iostream>
#include <vector>

struct Position : public Component<Position> {
    double x;
    double y;

    Position() = default;
    Position(double x_, double y_) : x(x_), y(y_) {}
};

struct Size : public Component<Size> {
    double width;
    double height;

    Size() = default;
    Size(double w_, double h_) : width(w_), height(h_) {}
};

class MovementSystem : public System<MovementSystem>
{
public:
    void update(double dt, EntityManager &em) override
    {
        std::cout << "New Iteration\n";
        std::cout << "  Position\n";
        em.each<Position>([](Position &pos) {
            std::cout << "    X: " << pos.x << ", Y: " << pos.y << "\n";
            ++pos.x, ++pos.y;
        });
        std::cout << "  Size\n";
        em.each<Size>([](Size &size) {
            std::cout << "    WIDTH: " << size.width
                      << ", HEIGHT: " << size.height << "\n";
            size.width += 7;
            size.height += 10;
        });
    }
};

int main()
{
    EntityManager em;
    Entity e1 = em.create_entity();
    Entity e2 = em.create_entity();
    MovementSystem s;

    std::cout << "e1: " << e1 << "\n";

    em.add_component(e1, std::make_unique<Size>(10, 5))
        .add_component(e1, std::make_unique<Position>(1, 5))
        .add_component(e2, std::make_unique<Position>(5, 2));
    s.update(60, em);
    s.update(60, em);
    em.delete_entity(e2);
    s.update(60, em);
}
