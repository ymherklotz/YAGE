/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: camera.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "camera.h"
#include "../render/shader.h"
#include "logger.h"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

namespace yage
{

/**
 * Creates a camera that looks onto the scene. The screen width and screen
 * height should be the current size of the window that the camera is being used
 * on so that is functions correctly.
 *
 * @param screen_width Current screen width of the Window.
 * @param screen_height Current screen height of the Window.
 */
Camera::Camera(int screen_width, int screen_height)
    : position_(0.f, 0.f), camera_matrix_(1.f),
      ortho_matrix_(
          glm::ortho(0.f, (float)screen_width, 0.f, (float)screen_height))
{
}

/**
 * Updates the camera matrix value in the shader program that is passed to it.
 * This must be a parameter `P` in the shader for this function to work.
 *
 * @param program Shader program to make changes to.
 *
 * @todo Make this function more general to be able to be able to use any
 * parametre in then shader as the camera matrix and not make it dependent on it
 * being `P`.
 */
void Camera::update(Shader &program)
{
    if (update_matrix_) {
        glm::vec3 translate(-position_.x, -position_.y, 0.f);
        glm::vec3 scale(scale_, scale_, 0.f);

        camera_matrix_ = glm::translate(ortho_matrix_, translate);
        camera_matrix_ = glm::scale(glm::mat4(1.f), scale) * camera_matrix_;

        update_matrix_ = false;
    }

    program.setUniform("P", camera_matrix_);
}

/**
 * Moves the camera using a two-dimensional displacement vector to describe the
 * movement.
 *
 * @param direction Two-dimensional vector to describe the displacement of the
 * camera.
 */
void Camera::move(const glm::vec2 &direction)
{
    position_ += direction;
    update_matrix_ = true;
}

/**
 * Zooms the camera by an incremental amount.
 *
 * @param factor Factor by which the camera should zoom. This can also be a
 * negative number for the camera to zoom out.
 */
void Camera::zoom(float factor)
{
    scale_ += factor;
    update_matrix_ = true;
}

} // namespace yage
