/** ---------------------------------------------------------------------------
 * @file: logger.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "../util/active.h"

namespace yage
{

class Logger;

/**
 * Different log levels that can be assigned to each message sent to the Logger.
 * The logger then outputs the message if it is above the minimum log level, or
 * does not process it.
 */
enum class LogLevel {
    /// Lowest log level. This is used by the game engine to output debugging
    /// information but is turned off in the logger by default.
    DEBUG,

    /// Information message.
    INFO,

    /// Warning message.
    WARNING,

#ifdef _WIN32
#ifdef ERROR
#define YAGE_ERROR_TMP ERROR
#undef ERROR
#endif
#endif

    /// Error message.
    ERROR,

#ifdef _WIN32
#ifdef YAGE_ERROR_TMP
#define ERROR YAGE_ERROR_TMP
#undef YAGE_ERROR_TMP
#endif
#endif

    /// Fatal message that should be output when the game
    /// crashes.
    FATAL,
};

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
    LogMessage::Meta meta_;

    LogMessage(Logger *owner, LogLevel level, const std::string &file_name,
               int line_num);
    LogMessage(LogMessage &&msg);
};

class LogSink
{
public:
    template <typename T>
    LogSink(T impl);

    LogSink(const LogSink &sink);
    LogSink(LogSink &&sink);

    LogSink &operator=(const LogSink &sink);
    LogSink &operator=(LogSink &&sink);
    bool operator==(const LogSink &sink);

    void write(const LogMessage::Meta &meta, const std::string &msg) const;

private:
    struct Concept {
        virtual ~Concept() = default;

        virtual Concept *clone() const                   = 0;
        virtual void write(const LogMessage::Meta &meta,
                           const std::string &msg) const = 0;
    };

    template <typename T>
    struct Model : Concept {
        Model(T impl_i);
        virtual Concept *clone() const override;
        virtual void write(const LogMessage::Meta &meta,
                           const std::string &msg) const override;

        T impl;
    };

    std::unique_ptr<Concept> wrapper_;
};

class Logger
{
public:
    Logger();
    explicit Logger(const std::string &file_path);
    explicit Logger(LogLevel min_level);
    Logger(LogLevel min_level, const std::string &file_path);

    LogMessage operator()(LogLevel level              = LogLevel::INFO,
                          const std::string &fileName = "", int lineNum = -1);

    void flush(const LogMessage *msg);
    void add(const LogSink &sink);
    void remove(const LogSink &sink);
    void clear();

    static Logger &instance();

    // setter for the level
    void setLevel(LogLevel min_level);

private:
    std::vector<LogSink> sinks_;
    std::unique_ptr<Active> active_;
    LogLevel min_level_;
};

LogSink makeConsoleSink();

LogSink makeFileSink(const std::string &filename);
LogSink makeFileSink(std::string &&filename);

/* -----------------------------------------------------------------------------
 * Template Implementation
 * -----------------------------------------------------------------------------
 */

template <typename T>
LogSink::LogSink(T impl) : wrapper_(new Model<T>(std::move(impl)))
{
}

template <typename T>
LogSink::Model<T>::Model(T impl_i) : impl(impl_i)
{
}

template <typename T>
LogSink::Concept *LogSink::Model<T>::clone() const
{
    return new Model<T>(impl);
}

template <typename T>
void LogSink::Model<T>::write(const LogMessage::Meta &meta,
                              const std::string &msg) const
{
    impl(meta, msg);
}

template <typename T>
LogMessage &LogMessage::operator<<(const T &value)
{
    buffer_ << value;
    return *this;
}

} // namespace yage

#define yLogger (yage::Logger::instance())

#define yLogDebug                                                              \
    (yage::Logger::instance()(yage::LogLevel::DEBUG, __FILE__, __LINE__))

#define yLogInfo                                                               \
    (yage::Logger::instance()(yage::LogLevel::INFO, __FILE__, __LINE__))

#define yLogWarning                                                            \
    (yage::Logger::instance()(yage::LogLevel::WARNING, __FILE__, __LINE__))

#define yLogError                                                              \
    (yage::Logger::instance()(yage::LogLevel::ERROR, __FILE__, __LINE__))

#define yLogFatal                                                              \
    (yage::Logger::instance()(yage::LogLevel::FATAL, __FILE__, __LINE__))
