/* ----------------------------------------------------------------------------
 * logsink.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "logsink.h"

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
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

void LogSink::write(const LogMessage::Meta &meta, const std::string &msg) const
{
    wrapper_->write(meta, msg);
}

LogSink makeConsoleSink()
{
    return [](const LogMessage::Meta &meta, const std::string &msg) {
        std::cout << msg << "\n";
    };
}

namespace
{

class FileSink
{
public:
    FileSink(std::string &&filename)
        : fileHandle_(std::make_shared<std::ofstream>(filename))
    {
        if (!fileHandle_->good()) {
            throw std::runtime_error("Could not open file: " + filename);
        }
    }

    FileSink(const std::string filename)
        : fileHandle_(std::make_shared<std::ofstream>(filename))
    {
        if (!fileHandle_->good()) {
            throw std::runtime_error("Could not open file: " + filename);
        }
    }

    ~FileSink() = default;

    void operator()(const LogMessage::Meta &meta, const std::string &msg) const
    {
        using namespace std::chrono;

        auto now = system_clock::now();
        auto time_t = system_clock::to_time_t(now);
        auto local_time = std::localtime(&time_t);

        (*fileHandle_) << std::put_time(local_time, "[%H:%M:%S] ") << msg
                       << " (" << meta.fileName << ":" << meta.lineNo << ")\n";
    }

private:
    std::shared_ptr<std::ofstream> fileHandle_;
};

} // namespace

LogSink makeFileSink(const std::string &filename)
{
    return FileSink(filename);
}

LogSink makeFileSink(std::string &&filename)
{
    return FileSink(filename);
}

} // namespace yage
