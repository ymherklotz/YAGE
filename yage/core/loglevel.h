/** ---------------------------------------------------------------------------
 * @file: loglevel.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGLEVEL_H
#define YAGE_CORE_LOGLEVEL_H

#ifdef _WIN32
#ifdef ERROR
#define YAGE_ERROR_TMP ERROR
#undef ERROR
#endif
#endif

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

#ifdef _WIN32
#ifdef YAGE_ERROR_TMP
#define ERROR YAGE_ERROR_TMP
#undef YAGE_ERROR_TMP
#endif
#endif

#endif
