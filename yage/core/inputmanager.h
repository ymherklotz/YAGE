/* ----------------------------------------------------------------------------
 * inputmanager.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <unordered_map>

namespace yage
{

class InputManager
{
private:
    std::unordered_map<unsigned, bool> key_map_;

public:
    void keyPressed(unsigned key);
    void keyReleased(unsigned key);
    bool isKeyPressed(unsigned key) const;
};

} // namespace yage

#endif
