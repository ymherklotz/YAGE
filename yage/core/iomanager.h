/** ---------------------------------------------------------------------------
 * @file: iomanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <string>
#include <vector>

namespace yage
{

namespace IoManager
{

extern bool readFileToBuffer(const std::string &file_path,
                             std::vector<unsigned char> &buffer);

}

} // namespace yage
