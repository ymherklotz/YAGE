#ifndef YAGE_CORE_EXCEPTION_H
#define YAGE_CORE_EXCEPTION_H

#include <stdexcept>
#include <sstream>

namespace yage
{

class FileLoadException : public std::runtime_error
{
public:
    FileLoadException(std::string err);

    virtual const char *what() const throw();

private:
    std::string err_msg;
};

} // namespace yage

#endif
