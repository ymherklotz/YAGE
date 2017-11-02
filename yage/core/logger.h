/* ----------------------------------------------------------------------------
 * logger.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGGER_H
#define YAGE_CORE_LOGGER_H

#include "logmessage.h"

namespace yage
{

class Logger
{
public:
    LogMessage operator()();

    void flush(const LogMessage *msg);

    static Logger &instance();
};

} // namespace yage

#define gLog yage::Logger::instance()()

#endif