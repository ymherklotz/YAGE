/* ----------------------------------------------------------------------------
 * logsink.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "logsink.h"

#include <iostream>

namespace yage
{

LogSink::LogSink(const LogSink &sink) : wrapper_(sink.wrapper_->clone()) {}

LogSink::LogSink(LogSink &&sink) : wrapper_(std::move(sink.wrapper_)) {}

LogSink &LogSink::operator=(const LogSink &sink)
{
    wrapper_.reset(sink.wrapper_->clone());
    return *this;
}

LogSink &LogSink::operator=(LogSink &&sink)
{
    wrapper_ = std::move(sink.wrapper_);
    return *this;
}

bool LogSink::operator==(const LogSink &sink)
{
    return (wrapper_.get() == sink.wrapper_.get());
}

void LogSink::write(const LogMessage::Meta &meta, const std::string &msg)
{
    wrapper_->write(meta, msg);
}

LogSink makeConsoleSink()
{
    return [](const LogMessage::Meta &meta, const std::string &msg) {
        std::cout << msg << " (" << meta.fileName << ":" << meta.lineNo
                  << ")\n";
    };
}

} // namespace yage
