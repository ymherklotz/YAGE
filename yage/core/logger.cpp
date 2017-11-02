/* ----------------------------------------------------------------------------
 * logger.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "logger.h"

#include <iostream>
#include <string>

namespace yage
{

LogMessage Logger::operator()()
{
    return LogMessage(this);
}

void Logger::flush(const LogMessage *msg)
{
    using std::string;
    using std::cout;

    string asString(msg->buffer_.str());
    cout << asString << "\n";
}

Logger &Logger::instance()
{
    static Logger gLogger;

    return gLogger;
}

} // namespace yage
