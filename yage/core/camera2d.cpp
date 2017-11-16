/* ----------------------------------------------------------------------------
 * camera2d.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/* ----------------------------------------------------------------------------
 * camera2d.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "camera2d.h"

#include <glad/glad.h>

namespace yage
{

Camera2D::Camera2D(int screen_width, int screen_height)
    : position_(0.f, 0.f), camera_matrix_(1.f),
      ortho_matrix_(
          glm::ortho(0.f, (float)screen_width, 0.f, (float)screen_height))
{
}

void Camera2D::update(GlslProgram &program)
{
    if (update_matrix_) {
        glm::vec3 translate(-position_.x, -position_.y, 0.f);
        glm::vec3 scale(scale_, scale_, 0.f);

        camera_matrix_ = glm::translate(ortho_matrix_, translate);
        camera_matrix_ = glm::scale(glm::mat4(1.f), scale) * camera_matrix_;

        update_matrix_ = false;
    }

    GLint matrix_location = program.getUniformLocation("P");
    glUniformMatrix4fv(matrix_location, 1, GL_FALSE, &(camera_matrix_[0][0]));
}

void Camera2D::move(const glm::vec2 &direction)
{
    position_ += direction;
    update_matrix_ = true;
}

} // namespace yage
