/* ----------------------------------------------------------------------------
 * vertex.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glew.h>

namespace yage
{

struct Position {
    float x;
    float y;

    Position() = default;

    Position(float x_, float y_) : x(x_), y(y_) {}
};

struct Color {
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;

    Color() = default;

    Color(GLubyte r_, GLubyte g_, GLubyte b_, GLubyte a_)
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
    Color color;
    UV uv;

    Vertex() = default;

    Vertex(const Position &position_, const Color &color_, const UV &uv_)
        : position(position_), color(color_), uv(uv_)
    {
    }

    void setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
    {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }

    void setUv(float u, float v)
    {
        uv.u = u;
        uv.v = v;
    }
};

} // namespace yage

#endif
