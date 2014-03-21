/*#version 120

attribute vec3 in_position;
attribute vec2 in_texCoord;

varying vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectedMatrix;

void main()
{
	texCoord = in_texCoord;
	gl_Position = projectedMatrix * vec4(in_position, 1);
}*/

#version 330

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_texCoord;

out vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectedMatrix;

void main()
{
	texCoord = in_texCoord;
	gl_Position = projectedMatrix * vec4(in_position, 1);
}