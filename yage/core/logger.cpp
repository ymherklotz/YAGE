/** ---------------------------------------------------------------------------
 * @file: logger.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "logger.h"
#include "logmessage.h"
#include "logsink.h"

#include <yage/util/active.h>

#include <algorithm>
#include <iostream>
#include <string>

namespace yage
{

Logger::Logger() : active_(Active::create()), min_level_(LogLevel::INFO)
{
    add(makeConsoleSink());
}

Logger::Logger(const std::string &file_path)
    : active_(Active::create()), min_level_(LogLevel::INFO)
{
    add(makeConsoleSink());
    add(makeFileSink(file_path));
}

Logger::Logger(LogLevel min_level)
    : active_(Active::create()), min_level_(min_level)
{
    add(makeConsoleSink());
}

Logger::Logger(LogLevel min_level, const std::string &file_path)
    : active_(Active::create()), min_level_(min_level)
{
    add(makeConsoleSink());
    add(makeFileSink(file_path));
}

LogMessage Logger::operator()(LogLevel level, const std::string &fileName,
                              int lineNum)
{
    return LogMessage(this, level, fileName, lineNum);
}

void Logger::flush(const LogMessage *msg)
{
    if (static_cast<int>(msg->meta_.level) >= static_cast<int>(min_level_)) {
        std::string asString(msg->buffer_.str());

        auto &&sinks = sinks_;
        auto &&meta  = msg->meta_;

        active_->send([=] {
            for (auto &&sink : sinks) {
                sink.write(meta, asString);
            }
        });
    }
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
    static Logger y_logger(LogLevel::INFO, "yage.log");

    return y_logger;
}

void Logger::setLevel(LogLevel min_level)
{
    min_level_ = min_level;
}

} // namespace yage
