/* ----------------------------------------------------------------------------
 * logsink.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

/// @file

#ifndef YAGE_CORE_LOGSINK_H
#define YAGE_CORE_LOGSINK_H

/// @todo remove the include to make compilation faster
#include "logmessage.h"

#include <memory>
#include <string>

namespace yage
{

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

        virtual Concept *clone() const = 0;
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

} // namespace yage

#endif
