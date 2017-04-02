#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
public:
    template<typename Tail>
    static std::string log(std::ostream &out, Tail &&tail)
    {
	out<<tail;
    }

    template<typename Head, typename... Tail>
    static std::string log(std::ostream &out, Head &&head, Tail &&...tail)
    {
	out<<std::forward<Head>(head);
	log(out, std::forward<Tail>(tail)...);
    }
};


#endif
