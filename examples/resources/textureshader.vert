#version 330

layout(location = 0) in vec2 vertex_position;
layout(location = 1) in vec4 vertex_colour;
layout(location = 2) in vec2 vertex_uv;

out vec2 fragment_position;
out vec4 fragment_colour;
out vec2 fragment_uv;

uniform mat4 P;

void main()
{
    gl_Position = vec4((P*vec4(vertex_position, 0.f, 1.f)).xy, 0.f, 1.f);

    fragment_position = vertex_position;
    fragment_colour = vertex_colour;
    fragment_uv = vec2(vertex_uv.x, 1-vertex_uv.y);    
}
