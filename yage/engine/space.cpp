/** ---------------------------------------------------------------------------
 * @file: space.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "space.h"

namespace yage
{

Space::Space() : em_(this) {}

unsigned Space::createEntity()
{
    return em_.createEntity();
}

} // namespace yage
