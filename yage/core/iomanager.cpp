/** ---------------------------------------------------------------------------
 * @file: iomanager.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include <yage/core/iomanager.h>

#include <fstream>
#include <stdexcept>
#include <regex>

namespace yage
{

namespace IoManager {

bool readFileToBuffer(const std::string &file_path,
                                 std::vector<unsigned char> &buffer)
{
    std::ifstream file(file_path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open '" + file_path + "'");
    }

    // seek to the end
    file.seekg(0, std::ios::end);

    // get the file size
    int file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    // reduce file size by header bytes
    file_size -= file.tellg();

    buffer.resize(file_size);
    file.read((char *)&buffer[0], file_size);
    file.close();

    return true;
}

}

} // namespace yage
