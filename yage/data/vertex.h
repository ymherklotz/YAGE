/** ---------------------------------------------------------------------------
 * @file: vertex.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <glad/glad.h>

namespace yage
{

struct Position {
    float x;
    float y;

    Position() = default;

    Position(float x_, float y_) : x(x_), y(y_) {}
};

struct Colour {
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;

    Colour() : r(0), g(0), b(0), a(0) {}

    Colour(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a_)
        : r(r_), g(g_), b(b_), a(a_)
    {
    }
};

struct UV {
    float u;
    float v;

    UV() = default;

    UV(float u_, float v_) : u(u_), v(v_) {}
};

struct Vertex {
    Position position;
    Colour colour;
    UV uv;

    Vertex() = default;

    Vertex(const Position &position_, const Colour &colour_, const UV &uv_)
        : position(position_), colour(colour_), uv(uv_)
    {
    }

    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    void setColour(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
    {
        colour.r = r;
        colour.g = g;
        colour.b = b;
        colour.a = a;
    }

    void setUv(float u, float v)
    {
        uv.u = u;
        uv.v = v;
    }
};

} // namespace yage

#endif
