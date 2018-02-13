#ifndef YAGE_UTIL_NONCOPYABLE_H
#define YAGE_UTIL_NONCOPYABLE_H

namespace yage
{

class NonCopyable
{
protected:
    NonCopyable()  = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};

} // namespace yage

#endif
