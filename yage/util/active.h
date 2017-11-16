#ifndef YAGE_UTIL_ACTIVE_H
#define YAGE_UTIL_ACTIVE_H

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

#endif
