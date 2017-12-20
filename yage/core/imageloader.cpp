/* ----------------------------------------------------------------------------
 * imageloader.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "imageloader.h"
#include "texture.h"

#include <glad/glad.h>
#include <yage/core/iomanager.h>
#include <yage/core/picopng.h>

#include <iostream>
#include <stdexcept>

namespace yage
{

Texture ImageLoader::loadPng(const std::string &file_path)
{
    std::vector<unsigned char> in;
    std::vector<unsigned char> out;
    unsigned long width, height;

    if (!IoManager::readFileToBuffer(file_path, in)) {
        throw std::runtime_error("Failed to load '" + file_path +
                                 "' to buffer");
    }

    int error_code = decodePNG(out, width, height, &in[0], in.size());
    if (error_code != 0) {
        throw std::runtime_error("Failed to load '" + file_path +
                                 "' to png with error code" +
                                 std::to_string(error_code));
    }

    Texture texture(0, static_cast<int>(width), static_cast<int>(height));
    std::cout << "Geometry: " << texture.width << "x" << texture.height << "\n";

    glGenTextures(1, &texture.id);

    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, &out[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    return texture;
}

} // namespace yage
