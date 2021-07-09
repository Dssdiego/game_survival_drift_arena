#version 330 core

// Color received from vertex shader
in vec4 vertColor;

// Color in the screen (out)
out vec4 fragColor;

void main()
{
    fragColor = vertColor;
}