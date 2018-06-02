/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: logger.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "logger.h"

#include "../util/active.h"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

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

        auto now        = system_clock::now();
        auto time_t     = system_clock::to_time_t(now);
        auto local_time = std::localtime(&time_t);

        std::string level;

        switch (meta.level) {
        case LogLevel::DEBUG:
            level = "DEBUG";
            break;
        case LogLevel::INFO:
            level = "INFO";
            break;
        case LogLevel::WARNING:
            level = "WARNING";
            break;
        case LogLevel::ERROR:
            level = "ERROR";
            break;
        case LogLevel::FATAL:
            level = "FATAL";
            break;
        }

        (*fileHandle_) << std::put_time(local_time, "[%H:%M:%S] [") << level
                       << "] " << msg << "\n";
        if (meta.fileName != "") {
            (*fileHandle_) << "(" << meta.fileName;
            if (meta.line != -1) {
                (*fileHandle_) << ":" << meta.line << ")";
            } else {
                (*fileHandle_) << ")";
            }
        }
        (*fileHandle_) << "\n\n";
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
