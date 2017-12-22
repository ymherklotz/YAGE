#version 450

layout(location = 0) in vec2 fragment_position;
layout(location = 1) in vec4 fragment_colour;
layout(location = 2) in vec2 fragment_uv;

out vec4 colour;

uniform sampler2D texture_sampler;

void main()
{
    vec4 texture_color = texture(texture_sampler, fragment_uv);

    colour = texture_color * fragment_colour;
}
