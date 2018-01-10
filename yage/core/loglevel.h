/** ---------------------------------------------------------------------------
 * @file: loglevel.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGLEVEL_H
#define YAGE_CORE_LOGLEVEL_H

namespace yage
{

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

    /// Error message.
    ERROR,

    /// Fatal message that should be output when the game
    /// crashes.
    FATAL,
};
}

#endif
