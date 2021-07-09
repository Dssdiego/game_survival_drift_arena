#version 330 core

// Color received from the vertex shader
in vec4 colorFromVert;

// Color in the screen (out)
out vec4 fragColor;

void main()
{
    fragColor = colorFromVert;
}