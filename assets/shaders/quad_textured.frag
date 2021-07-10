#version 330 core

// Texture Coordinates from vertex shader
in vec2 texCoords;

// Color in the screen (out)
out vec4 fragColor;

// Texture sampler
uniform sampler2D uTex;

void main()
{
//    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
    fragColor = texture(uTex, texCoords);
}