/* ----------------------------------------------------------------------------
 * renderingtest.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <string>

class RenderTest
{
public:
    RenderTest(std::string sprite);
    void render();

private:
    std::string sprite_;
};
