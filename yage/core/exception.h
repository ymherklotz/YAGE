/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: exception.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <sstream>
#include <stdexcept>

namespace yage
{

class FileLoadException : public std::runtime_error
{
public:
    FileLoadException(std::string err);

    virtual char const *what() const throw();

private:
    std::string err_msg;
};

} // namespace yage
