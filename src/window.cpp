#include "window.hpp"

#include <GL/glew.h>

#include <iostream>
#include <stdexcept>

Window::Window()
{}

Window::~Window()
{}

void Window::create(const std::string &window_name, int width, int height, WindowFlags flags)
{
    // SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    // SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    window_ = SDL_CreateWindow("Arider", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			       width_, height_, SDL_WINDOW_OPENGL);
    if(window_ == nullptr)
	throw std::runtime_error("SDL_CreateWindow failed");

    SDL_GLContext gl_context = SDL_GL_CreateContext(window_);
    if(gl_context == nullptr)
	throw std::runtime_error("SDL_GL_CreateContext failed");

    GLenum error = glewInit();
    if(error != GLEW_OK)
	throw std::runtime_error("glewInit failed");

    std::cout<<"***  OpenGL version: "<<glGetString(GL_VERSION)<<"  ***\n";

    SDL_GL_SetSwapInterval(1);

    glClearColor(0.f, 0.f, 0.f, 1.f);
}
