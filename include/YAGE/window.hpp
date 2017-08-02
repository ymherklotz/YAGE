/* ----------------------------------------------------------------------------
 * window.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

#include <string>

namespace yage
{

// window flags that can change it's appearance
enum WindowFlags : unsigned
{
    SHOWN=0x1,
    HIDDEN=0x2,
    FULLSCREEN=0x4,
    BORDERLESS=0x8,
};

// window wrapper around SDL_Window pointer
class Window
{
private:
    /// window handle
    SDL_Window *window_=nullptr;
    
public:
    Window();
	Window(const Window&)=delete;
	Window(Window&&)=delete;
    /// destroys the window handle
	~Window();

	Window& operator=(const Window&)=delete;
	Window& operator=(Window&&)=delete;

    /// create the window, initialize the handle and update the width and height
    void create(const std::string &window_name, int width, int height, unsigned flags=WindowFlags::SHOWN);
    /// swap the buffer
    void swapBuffer();
    /// clear buffer
    void clearBuffer();
};
    
} // namespace yage

#endif
