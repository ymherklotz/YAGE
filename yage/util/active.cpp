/** ---------------------------------------------------------------------------
 * @file: active.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "active.h"

namespace yage
{

Active::Active() : running_(true) {}

Active::~Active()
{
    send([this] { running_ = false; });
    thread_.join();
}

std::unique_ptr<Active> Active::create()
{
    std::unique_ptr<Active> result(new Active);

    result->thread_ = std::thread(&Active::run, result.get());

    return result;
}

void Active::send(Callback message)
{
    queue_.push(message);
}

void Active::run()
{
    Callback fn;
    while (running_) {
        queue_.pop(fn);
        fn();
    }
}

} // namespace yage
