#version 130

in vec2 vertex_position;
in vec4 vertex_colour;
in vec2 vertex_uv;

out vec2 fragment_position;
out vec4 fragment_colour;
out vec2 fragment_uv;

uniform mat4 P;

void main()
{
    gl_Position.xy = (P*vec4(vertex_position, 0.0, 1.0)).xy;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;

    fragment_position = vertex_position;
    fragment_colour = vertex_colour;
    fragment_uv = vec2(vertex_uv.x, 1-vertex_uv.y);
}
