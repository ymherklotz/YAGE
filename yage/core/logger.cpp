/* ----------------------------------------------------------------------------
 * logger.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "logger.h"
#include "logmessage.h"
#include "logsink.h"

#include <algorithm>
#include <iostream>
#include <string>

namespace yage
{

Logger::Logger() : active_(Active::create())
{
    add(makeConsoleSink());
}

LogMessage Logger::operator()(const std::string &fileName, int lineNum)
{
    return LogMessage(this, fileName, lineNum);
}

void Logger::flush(const LogMessage *msg)
{
    std::string asString(msg->buffer_.str());

    auto &&sinks = sinks_;
    auto &&meta = msg->meta_;

    active_->send([=] {
        for (auto &&sink : sinks) {
            sink.write(meta, asString);
        }
    });
}

void Logger::add(const LogSink &sink)
{
    sinks_.push_back(sink);
}

void Logger::remove(const LogSink &sink)
{
    auto it = std::find(std::begin(sinks_), std::end(sinks_), sink);

    if (it != std::end(sinks_)) {
        sinks_.erase(it);
    }
}

void Logger::clear()
{
    sinks_.clear();
}

Logger &Logger::instance()
{
    static Logger gLogger;

    return gLogger;
}

} // namespace yage
