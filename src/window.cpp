#include "window.hpp"

#include <GL/glew.h>

#include <iostream>
#include <stdexcept>

namespace yage
{

Window::Window()
{}

Window::~Window()
{
    SDL_DestroyWindow(window_);
}

void Window::create(const std::string &window_name, int width, int height, unsigned flags)
{
    Uint32 gl_window_states=0;

    // set the correct input flags
    if(flags & WindowFlags::SHOWN)
	gl_window_states|=SDL_WINDOW_OPENGL;
    if(flags & WindowFlags::HIDDEN)
	gl_window_states|=SDL_WINDOW_HIDDEN;
    if(flags & WindowFlags::FULLSCREEN)
	gl_window_states|=SDL_WINDOW_FULLSCREEN;
    if(flags & WindowFlags::BORDERLESS)
	gl_window_states|=SDL_WINDOW_BORDERLESS;

    // SDL_GL options
    
    // SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    // SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // create the SDL window
    window_ = SDL_CreateWindow(window_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			       width, height, gl_window_states);
    if(window_ == nullptr)
	throw std::runtime_error("SDL_CreateWindow failed");

    // initialize the GL context in the window
    SDL_GLContext gl_context = SDL_GL_CreateContext(window_);
    if(gl_context == nullptr)
	throw std::runtime_error("SDL_GL_CreateContext failed");

    // initialize glew
    GLenum error = glewInit();
    if(error != GLEW_OK)
	throw std::runtime_error("glewInit failed");

    // print out the current OpenGL version to debug
    std::cout<<"***  OpenGL version: "<<glGetString(GL_VERSION)<<"  ***\n";

    // set vsync on instead of custom fps limiting
    SDL_GL_SetSwapInterval(1);
    // set the clear color to black
    glClearColor(0.f, 0.f, 0.f, 1.f);
}

void Window::swapBuffer()
{
    // swap the window buffer
    SDL_GL_SwapWindow(window_);
}
    
} // yage
