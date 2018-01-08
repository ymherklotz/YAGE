/** ---------------------------------------------------------------------------
 * @file: logmessage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGMESSAGE_H
#define YAGE_CORE_LOGMESSAGE_H

#include <memory>
#include <sstream>
#include <string>

#include "loglevel.h"

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
        LogLevel level;
        std::string fileName;
        int line;
    };

private:
    friend class Logger;

    std::ostringstream buffer_;
    Logger *owner_;
    Meta meta_;

    LogMessage(Logger *owner, LogLevel level, const std::string &file_name,
               int line_num);
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
