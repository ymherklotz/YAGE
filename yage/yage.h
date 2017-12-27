/** ---------------------------------------------------------------------------
 * @file: yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef YAGE_YAGE_H
#define YAGE_YAGE_H

#include "core/camera.h"
#include "core/imageloader.h"
#include "core/iomanager.h"
#include "core/logger.h"
#include "core/logmessage.h"
#include "core/logsink.h"
#include "core/picopng.h"
#include "core/resourcemanager.h"
#include "core/spritesheet.h"
#include "core/window.h"
#include "data/input.h"
#include "data/texture.h"
#include "data/vertex.h"
#include "math/matrix.h"
#include "physics/body.h"
#include "physics/particlebody.h"
#include "physics/rectanglecollider.h"
#include "physics/rigidbody.h"
#include "render/shader.h"
#include "render/spritebatch.h"
#include "util/active.h"
#include "util/syncqueue.h"

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
