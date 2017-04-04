#ifndef CAMERA_2D_HPP
#define CAMERA_2D_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace yage
{

class Camera2D
{
    // member variables
private:
    bool matrix_needs_update_=true;
    float scale_=1.f;
    glm::vec2 position_;
    glm::mat4 camera_matrix_;
    glm::mat4 ortho_matrix_;

    // member functions
public:
    Camera2D(int screen_width=1280, int screen_height=720);
    virtual ~Camera2D();

    // update camera location
    void update();
    // camera movement
    void move(const glm::vec2 &direction);

    // getters
    float getScale() { return scale_; }
    glm::vec2 getPosition() { return position_; }
    glm::mat4 getCameraMatrix() { return camera_matrix_; }
};

} // yage

#endif
