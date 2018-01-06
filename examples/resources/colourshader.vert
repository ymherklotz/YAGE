#version 450

layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec4 vertex_colour;

layout(location = 0) out vec4 fragment_colour;

uniform mat4 P;

void main()
{
    gl_Position = vec4(vertex_position, 0.f, 1.f);

    fragment_colour = vertex_colour;
}
