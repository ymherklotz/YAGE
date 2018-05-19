/** ---------------------------------------------------------------------------
 * @file: syncqueue.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>

namespace yage
{

template <typename T>
class SyncQueue
{
public:
    SyncQueue()                  = default;
    SyncQueue(const SyncQueue &) = delete;
    SyncQueue &operator=(const SyncQueue &) = delete;

    T pop();
    void pop(T &item);
    void push(const T &item);
    void push(T &&item);

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cond_;
};

// Template definitions

template <typename T>
T SyncQueue<T>::pop()
{
    std::unique_lock<std::mutex> mlock(mutex_);

    while (queue_.empty()) {
        cond_.wait(mlock);
    }

    auto item = queue_.front();
    queue_.pop();
    return item;
}

template <typename T>
void SyncQueue<T>::pop(T &item)
{
    std::unique_lock<std::mutex> mlock(mutex_);

    while (queue_.empty()) {
        cond_.wait(mlock);
    }

    item = queue_.front();
    queue_.pop();
}

template <typename T>
void SyncQueue<T>::push(const T &item)
{
    std::unique_lock<std::mutex> mlock(mutex_);

    queue_.push(item);
    mlock.unlock();
    cond_.notify_one();
}

template <typename T>
void SyncQueue<T>::push(T &&item)
{
    std::unique_lock<std::mutex> mlock(mutex_);

    queue_.push(std::move(item));
    mlock.unlock();
    cond_.notify_one();
}

} // namespace yage
