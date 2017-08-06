/* ----------------------------------------------------------------------------
 * iomanager.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef IO_MANAGER_HPP
#define IO_MANAGER_HPP

#include <string>
#include <vector>

namespace yage {

class IoManager {
public:
    static bool readFileToBuffer(const std::string &file_path,
                                 std::vector<unsigned char> &buffer);
};

} // yage

#endif
