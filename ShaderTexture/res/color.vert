#version 460 core

layout(location = 0) in vec4 inPosition;
layout(location = 1) in vec2 inTexture;

out vec2 outTexture;

void main()
{
	gl_Position = inPosition;
	outTexture = inTexture;
}