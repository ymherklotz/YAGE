/** ---------------------------------------------------------------------------
 * @file: system.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_ENGINE_SYSTEM_H
#define YAGE_ENGINE_SYSTEM_H

#include <cstddef>

#include "../util/noncopyable.h"

namespace yage
{

class BaseSystem : public yage::NonCopyable
{
public:
    typedef std::size_t Identifier;

    virtual void update() = 0;

protected:
    Identifier id_;
};

/**
 * System interface for the different systems in the engine.
 */
template <typename Derived>
class System : public BaseSystem
{
public:
};

class SystemManager : public yage::NonCopyable {
    
};

} // namespace yage

#endif
