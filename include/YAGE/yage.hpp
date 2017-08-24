/* ----------------------------------------------------------------------------
 * yage.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

/** @file Includes all the headers in the main YAGE project.
  *
  * This does not include
  */

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

/** Project namespace.
  *
  * Avoids collision as all the classes and global functions are wrapped in.
  * it.
  */
namespace yage
{

/** Initializes YAGE.
  *
  * This is only there to initialize SDL2.
  *
  * @return Returns true if the initialization was successful.
  */
bool init()
{
    return SDL_Init(SDL_INIT_VIDEO);
}

/** Quit and cleanup YAGE
  *
  * SDL2 needs to clean itself up.
  */
void quit()
{
    SDL_Quit();
}

} // namespace yage

#endif
