/* ----------------------------------------------------------------------------
 * logmessage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGMESSAGE_H
#define YAGE_CORE_LOGMESSAGE_H

#include <memory>
#include <sstream>
#include <string>

namespace yage
{

class Logger;

class LogMessage
{
public:
    ~LogMessage();

    LogMessage(const LogMessage &msg) = delete;

    LogMessage &operator=(const LogMessage &msg) = delete;
    LogMessage &operator=(LogMessage &&msg) = delete;

    template <typename T>
    LogMessage &operator<<(const T &value);

    LogMessage &operator<<(std::ostream &(*fn)(std::ostream &os));

    struct Meta {
        std::string fileName;
        int lineNo;
    };

private:
    friend class Logger;

    std::ostringstream buffer_;
    Logger *owner_;

    LogMessage(Logger *owner);
    LogMessage(LogMessage &&msg);
};

/* -----------------------------------------------------------------------------
 * Template definitions
 * -----------------------------------------------------------------------------
 */

template <typename T>
LogMessage &LogMessage::operator<<(const T &value)
{
    buffer_ << value;
    return *this;
}

} // namespace yage

#endif
