#include "exception.h"

namespace yage
{

FileLoadException::FileLoadException(std::string err) : std::runtime_error("File Load Exception")
{
    std::ostringstream msg("");

    msg << runtime_error::what() << ": " << err;

    err_msg = msg.str();
}

const char *FileLoadException::what() const throw()
{
    return err_msg.c_str();
}

} // namespace yage
