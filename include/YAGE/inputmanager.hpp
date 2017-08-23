/* ----------------------------------------------------------------------------
 * inputmanager.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

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
}
#endif
