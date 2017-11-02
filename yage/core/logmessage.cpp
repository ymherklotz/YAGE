/* ----------------------------------------------------------------------------
 * logmessage.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "logmessage.h"
#include "logger.h"

namespace yage
{

LogMessage::LogMessage(Logger *owner) : owner_(owner) {}

LogMessage::LogMessage(LogMessage &&msg) : owner_(std::move(msg.owner_)) {}

LogMessage::~LogMessage()
{
    if (owner_ != nullptr) {
        owner_->flush(*this);
    }
}

LogMessage &LogMessage::operator<<(std::ostream &(*fn)(std::ostream &os))
{
    fn(buffer_);
    return *this;
}

} // namespace yage
