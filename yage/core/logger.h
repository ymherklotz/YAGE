/** ---------------------------------------------------------------------------
 * @file: logger.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGGER_H
#define YAGE_CORE_LOGGER_H

#include <memory>
#include <string>
#include <vector>

#include "../util/active.h"
#include "loglevel.h"
#include "logmessage.h"
#include "logsink.h"

namespace yage
{

class Logger
{
public:
    Logger();
    explicit Logger(const std::string &file_path);
    explicit Logger(LogLevel min_level);
    Logger(LogLevel min_level, const std::string &file_path);

    LogMessage operator()(LogLevel level = LogLevel::INFO, const std::string &fileName = "",
                          int lineNum = -1);

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

} // namespace yage

#define yLogger (yage::Logger::instance())

#define yLogDebug                                                              \
    (yage::Logger::instance()(yage::LogLevel::DEBUG, __FILE__, __LINE__))

#define yLogInfo (yage::Logger::instance()(yage::LogLevel::INFO, __FILE__, __LINE__))

#define yLogWarning                                                            \
    (yage::Logger::instance()(yage::LogLevel::WARNING, __FILE__, __LINE__))

#define yLogError                                                              \
    (yage::Logger::instance()(yage::LogLevel::ERROR, __FILE__, __LINE__))

#define yLogFatal                                                              \
    (yage::Logger::instance()(yage::LogLevel::FATAL, __FILE__, __LINE__))

#endif
