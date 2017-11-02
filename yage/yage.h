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

#include "core/camera2d.h"
#include "core/glslprogram.h"
#include "core/imageloader.h"
#include "core/inputmanager.h"
#include "core/iomanager.h"
#include "core/picopng.h"
#include "core/resourcemanager.h"
#include "core/spritebatch.h"
#include "core/spritesheet.h"
#include "core/texture.h"
#include "core/vertex.h"
#include "core/window.h"
#include "core/logger.h"
#include "core/logmessage.h"
#include "core/logsink.h"

#include "physics/body.h"
#include "physics/particlebody.h"
#include "physics/rectanglecollider.h"
#include "physics/rigidbody.h"

/** Project namespace.
  *
  * Avoids collision as all the classes and global functions are wrapped in.
  * it.
  */
namespace yage
{

extern void glfwErrorCallback(int, const char *);

/** Initializes yage.
  *
  * This is only there to initialize glfw.
  *
  * @return Returns true if the initialization was successful.
  */
extern void init();

/** Quit and cleanup yage
  *
  * glfw needs to clean itself up.
  */
extern void quit();

} // namespace yage

#endif
