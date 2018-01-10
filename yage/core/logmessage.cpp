/** ---------------------------------------------------------------------------
 * @file: logmessage.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "logmessage.h"
#include "logger.h"

#include <iostream>

namespace yage
{

LogMessage::LogMessage(Logger *owner, LogLevel level,
                       const std::string &file_name, int line_num)
    : owner_(owner), meta_({level, file_name, line_num})
{
}

LogMessage::LogMessage(LogMessage &&msg) : owner_(std::move(msg.owner_)) {}

LogMessage::~LogMessage()
{
    if (owner_ != nullptr) {
        owner_->flush(this);
    }
}

LogMessage &LogMessage::operator<<(std::ostream &(*fn)(std::ostream &os))
{
    fn(buffer_);
    return *this;
}

} // namespace yage
