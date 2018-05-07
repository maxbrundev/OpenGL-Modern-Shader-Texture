#version 460 core

uniform sampler2D myTexture;

in vec2 outTexture;

out vec4 finalTexture;

void main()
{
	finalTexture = texture(myTexture, outTexture);
}