#ifndef YAGE_HPP
#define YAGE_HPP

#include "camera2d.hpp"
#include "glslprogram.hpp"
#include "imageloader.hpp"
#include "inputmanager.hpp"
#include "iomanager.hpp"
#include "picopng.hpp"
#include "resourcemanager.hpp"
#include "spritebatch.hpp"
#include "texture.hpp"
#include "vertex.hpp"
#include "window.hpp"

#include <SDL2/SDL.h>

#include <stdexcept>

namespace yage
{

bool init()
{
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		return false;
	}
	return true;
}

void quit()
{
	SDL_Quit();
}

};

#endif
