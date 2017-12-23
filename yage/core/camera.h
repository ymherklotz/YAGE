/** ---------------------------------------------------------------------------
 * @file: camera.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CAMERA2D_H
#define YAGE_CAMERA2D_H

#include <glm/glm.hpp>

namespace yage
{

class GlslProgram;

class Camera
{
private:
    bool update_matrix_ = true;
    float scale_        = 1;
    glm::vec2 position_;
    glm::mat4 camera_matrix_;
    glm::mat4 ortho_matrix_;

public:
    Camera(int screen_width = 1280, int screen_height = 720);

    void update(GlslProgram &program);
    void move(const glm::vec2 &direction);
};

} // namespace yage

#endif
