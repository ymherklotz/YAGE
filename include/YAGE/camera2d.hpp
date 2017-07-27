/* ----------------------------------------------------------------------------
 * camera2d.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef CAMERA_2D_HPP
#define CAMERA_2D_HPP

#include "glslprogram.hpp"

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
    void update(GlslProgram &program);
    // camera movement
    void move(const glm::vec2 &direction);
};

} // yage

#endif
