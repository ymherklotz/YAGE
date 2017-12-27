#version 450

layout(location = 0) in vec2 fragment_position;
layout(location = 1) in vec4 fragment_colour;
layout(location = 2) in vec2 fragment_uv;

layout(location = 0) out vec4 colour;
layout(location = 1) out vec4 colour2;

uniform sampler2D texture_sampler;

void main()
{
    vec4 texture_colour = texture(texture_sampler, fragment_uv);

    colour2 = vec4(1.f, 0.f, 0.f, 1.f);
    colour = texture_colour;
}
