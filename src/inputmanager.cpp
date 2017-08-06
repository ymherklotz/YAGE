/* ----------------------------------------------------------------------------
 * inputmanager.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include "inputmanager.hpp"

namespace yage {

void InputManager::keyPressed(unsigned key) { key_map_[key] = true; }

void InputManager::keyReleased(unsigned key) { key_map_[key] = false; }

bool InputManager::isKeyPressed(unsigned key) const {
    auto key_index = key_map_.find(key);
    if (key_index != key_map_.end()) return key_index->second;
    return false;
}
}
