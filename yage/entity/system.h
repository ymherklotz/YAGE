/** ---------------------------------------------------------------------------
 * @file: system.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <cstddef>

#include "../util/noncopyable.h"

namespace yage
{

class System : public NonCopyable
{
public:
    virtual void init() = 0;
    virtual void update() = 0;
};

} // namespace yage
