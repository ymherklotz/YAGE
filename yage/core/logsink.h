/* ----------------------------------------------------------------------------
 * logger.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGSINK_H
#define YAGE_CORE_LOGSINK_H

#include "logmessage.h"

#include <string>

namespace yage
{

class LogSink
{
public:
    void operator()(const LogMessage::Meta &, const std::string &message);
};

} // namespace yage

#endif
