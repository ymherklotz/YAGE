/* ----------------------------------------------------------------------------
 * logsink.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "logsink.h"

namespace yage
{

void LogSink::write(const LogMessage::Meta &meta, const std::string &msg)
{
    wrapper_->write(meta, msg);
}

} // namespace yage
