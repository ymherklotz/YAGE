/* ----------------------------------------------------------------------------
 * yage.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "yage.h"

namespace yage
{

bool init()
{
    return SDL_Init(SDL_INIT_VIDEO);
}

void quit()
{
    SDL_Quit();
}

} // namespace yage
