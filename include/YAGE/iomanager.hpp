#ifndef IO_MANAGER_HPP
#define IO_MANAGER_HPP

#include <string>
#include <vector>

namespace yage
{

class IoManager
{
public:
    static bool readFileToBuffer(const std::string &file_path, std::vector<unsigned char> &buffer);
};
    
} // yage

#endif
