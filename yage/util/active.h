/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: active.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include "syncqueue.h"

#include <functional>
#include <memory>
#include <thread>

namespace yage
{

class Active
{
public:
    typedef std::function<void()> Callback;

    Active(const Active &) = delete;
    Active &operator=(const Active &) = delete;

    ~Active();

    static std::unique_ptr<Active> create();

    void send(Callback message);

private:
    Active();
    void run();

    bool running_;
    SyncQueue<Callback> queue_;
    std::thread thread_;
};

} // namespace yage
