/* ----------------------------------------------------------------------------
 * logger.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGGER_H
#define YAGE_CORE_LOGGER_H

#include <yage/util/active.h>

#include <memory>
#include <string>
#include <vector>

namespace yage
{

class LogMessage;
class LogSink;

class Logger
{
public:
    explicit Logger();

    LogMessage operator()(const std::string &fileName, int lineNum);

    void flush(const LogMessage *msg);
    void add(const LogSink &sink);
    void remove(const LogSink &sink);
    void clear();

    static Logger &instance();

private:
    std::vector<LogSink> sinks_;
    std::unique_ptr<Active> active_;
};

} // namespace yage

#define gLog (yage::Logger::instance()(__FILE__, __LINE__))

#endif
