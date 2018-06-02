/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: exception.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "exception.h"

namespace yage
{

FileLoadException::FileLoadException(std::string err)
    : std::runtime_error("File Load Exception")
{
    std::ostringstream msg("");

    msg << runtime_error::what() << ": " << err;

    err_msg = msg.str();
}

const char *FileLoadException::what() const throw()
{
    return err_msg.c_str();
}

} // namespace yage
