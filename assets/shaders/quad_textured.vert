#version 330 core

// positions
layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aTexCoords;

// Pass texture coordinates to fragment shader
out vec2 texCoords;

void main()
{
    // Since we are drawing a 2D triangle, Z position is always 0!
    gl_Position = vec4(aPos, 0.0, 1.0);

    texCoords = aTexCoords;
}