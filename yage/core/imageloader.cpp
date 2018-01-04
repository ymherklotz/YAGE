/** ---------------------------------------------------------------------------
 * @file: imageloader.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "imageloader.h"
#include "../data/texture.h"
#include "logger.h"
#include "stb_image.h"

#include <glad/glad.h>

#include <iostream>
#include <stdexcept>

namespace yage
{

Texture ImageLoader::loadPng(const std::string &file_path)
{
    int width, height, num_channels;
    unsigned char *data =
        stbi_load(file_path.c_str(), &width, &height, &num_channels, 0);

    Texture texture(0, static_cast<int>(width), static_cast<int>(height));
    glGenTextures(1, &texture.id);

    glBindTexture(GL_TEXTURE_2D, texture.id);

    if (num_channels == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                     GL_UNSIGNED_BYTE, data);
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB,
                     GL_UNSIGNED_BYTE, data);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    yLog << "Successfully loaded texture: " << file_path;

    return texture;
}

} // namespace yage
