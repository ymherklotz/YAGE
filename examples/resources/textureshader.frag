#version 330

in vec2 fragment_position;
in vec4 fragment_colour;
in vec2 fragment_uv;

out vec4 colour;

uniform sampler2D texture_sampler;

void main()
{
    vec4 texture_colour = texture(texture_sampler, fragment_uv);

    colour = texture_colour;
}
