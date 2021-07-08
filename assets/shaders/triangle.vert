#version 330 core

in vec2 aPos;

void main()
{
    // Since we are drawing a 2D triangle, Z position is always 0!
    gl_Position = vec4(aPos, 0.0, 1.0);
}