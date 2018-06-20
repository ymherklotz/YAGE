#include <yage/entity/entity.h>
#include <yage/entity/component.h>
#include <yage/entity/system.h>

struct Position {
    double x;
    double y;

    Position(double x_i, double y_i) : x(x_i), y(y_i) {}
};

int main() {
    EntityManager em();
    Entity player = em.createEntity();
}
