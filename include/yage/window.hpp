#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

#include <string>

enum class WindowFlags
{
    SHOWN=0x1,
    HIDDEN=0x2,
    FULLSCREEN=0x4,
    BORDERLESS=0x8,
};

class Window
{
private:
    SDL_Window *window_=nullptr;
    int width_=1280;
    int height_=720;
    
public:
    Window();
    ~Window();

    void create(const std::string &window_name, int width, int height, WindowFlags flags=WindowFlags::SHOWN);
};

#endif
