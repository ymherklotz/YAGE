/* ----------------------------------------------------------------------------
 * iomanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef IO_MANAGER_H
#define IO_MANAGER_H

#include <string>
#include <vector>

namespace yage
{

class IoManager
{
public:
    static bool readFileToBuffer(const std::string &file_path,
                                 std::vector<unsigned char> &buffer);
};

} // namespace yage

#endif
