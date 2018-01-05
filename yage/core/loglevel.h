/** ---------------------------------------------------------------------------
 * @file: loglevel.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_CORE_LOGLEVEL_H
#define YAGE_CORE_LOGLEVEL_H

namespace yage {

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

}

#endif
