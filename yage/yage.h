/* ----------------------------------------------------------------------------
 * yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

/** @file Includes all the headers in the main yage project.
  *
  * This does not include
  */

#ifndef YAGE_YAGE_H
#define YAGE_YAGE_H

#include "base/camera2d.h"
#include "base/glslprogram.h"
#include "base/imageloader.h"
#include "base/inputmanager.h"
#include "base/iomanager.h"
#include "base/picopng.h"
#include "base/resourcemanager.h"
#include "base/spritebatch.h"
#include "base/texture.h"
#include "base/vertex.h"
#include "base/window.h"

#include "physics/rectanglecollider.h"
#include "physics/rigidbody.h"
#include "physics/particlebody.h"
#include "physics/body.h"


#include <SDL2/SDL.h>

#include <stdexcept>

/** Project namespace.
  *
  * Avoids collision as all the classes and global functions are wrapped in.
  * it.
  */
namespace yage
{

/** Initializes yage.
  *
  * This is only there to initialize SDL2.
  *
  * @return Returns true if the initialization was successful.
  */
extern bool init();

/** Quit and cleanup yage
  *
  * SDL2 needs to clean itself up.
  */
extern void quit();

} // namespace yage

#endif
